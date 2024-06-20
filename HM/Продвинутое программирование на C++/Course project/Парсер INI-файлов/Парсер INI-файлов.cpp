#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class ini_parser {

public:
    ini_parser(std::string filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }
        parse();
    }

    void trim( std::string& source) {// удаление пробелов и табуляции с начала и конца строки.
        source.erase(0, source.find_first_not_of(" \n\r\t"));
        source.erase(source.find_last_not_of(" \n\r\t") + 1);;
    }
    
    void parse() {// проверка валидности файла
        std::string in;//поток ввода

        while (std::getline(file, in)) {//Обход файла

            trim(in);

            if (in[0] == '[') {/// Проверка коррекции [Section?]
                std::string string_template{"[Section?]"};// шаблон [Section?]
                for (int i = 0; i < string_template.size(); i++) {
                    if (i == 8) i++;//проскакивание числа
                    if (in[i] != string_template[i]) { throw std::runtime_error("Ошибка чтения файла строка: " + file.tellg()); }//???? почему выбрасывает не коректное значение
                }
            }

        }//Обход файла
        file.seekg(0, std::ios_base::beg);//Встать в начало файла
    }

    template <typename T>
    T get_value(int section, std::string value) {
        std::string val = get_value_template(section, value);
        return val;
    }

    template <>
    int get_value(int section, std::string value) {
        std::string val = get_value_template(section, value);
        return stoi(val);
    }

    template <>
    double get_value(int section, std::string value) {
        std::string val = get_value_template(section, value);
        return stod(val);
    }

    std::string get_value_template(int section, std::string value) {
        std::string in;
        bool section_name = false;//проверка наличия секции

        while (std::getline(file, in)) {//Обход файла

            trim(in);

            if (in[0] == '[') {/// Поиск нужной секции


                int n = in.find('n');// временная переменная
                std::string string_section;// стринговое значение секции
                while (in[++n] != ']') {
                    string_section.push_back(in[n]);
                }

                if (section == std::stoi(string_section)) {/// Поиск нужного значения
                    section_name = true;
                    bool value_name = false;//проверка наличия имени значения

                    while (value_name != true && in[0] !=' ') {//сравнение имени значения
                        if(std::getline(file, in).eof()) { throw std::runtime_error("Такой переменной нет"); } //переход на следующую строку и проверка на конец файла
                        for (int i = 0; in[i] != '='; i++) {
                            if (in[i] == value[i]) value_name = true;
                            else { value_name = false; break; }
                        }
                    }//сравнение имени значения
                    if (value_name == false) { throw std::runtime_error("Такой переменной нет"); }

                    int equals = in.find('=');// временная переменная
                    equals++;
                    std::string string_value;// стринговое значение значения
                    while (in[equals] != 0 && in[equals] != ';') {
                        string_value.push_back(in[equals]);
                        equals++;
                    }
                    if (string_value.size() == 0) { throw std::runtime_error("Нет значения для этой переменной"); }
                    else {
                        return string_value;
                    }

                }/// Поиск нужного значения

            }/// Поиск нужной секции

        }//Обход файла
        if (section_name == false) { throw std::runtime_error("Такой cекции нет"); }
    }
    
    ~ini_parser() {
        file.close();
    }

private:
    std::ifstream file;
};
int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        ini_parser parser("test.ini");  //filename
        auto value = parser.get_value<double>(1, "var1");   //section.value
        std::cout << value;
    }
    catch(std::runtime_error &err) { std::cout << err.what() << std::endl; }
}

