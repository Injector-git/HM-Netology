#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>//для корректной работы кириллицы со стрингом



class ini_parser {

public:
    ini_parser() = delete;
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

        while (true) {//Обход файла
            if (std::getline(file, in).eof()) { break; } //переход на следующую строку и проверка на конец файла
            stroka_counter++;
            trim(in);
            std::cout << "stroka:" << stroka_counter << "\t" << in << std::endl;

            if (in[0] == ';') {
                continue;
            }

            else if (in[0] == '[') {/// Проверка коррекции [Section?]

                std::string string_template{ "[Section?]" };// шаблон [Section?]
                for (int i = 0; i < string_template.size(); i++) {
                    if (i == 8) { section_number = in[i]; i++; }//проскакивание числа и запись секции
                    if (in[i] != string_template[i]) { throw  std::runtime_error("Ошибка чтения файла строка: " + std::to_string(stroka_counter)); }
                }
            }

            else if (in[0] > 'A' && in[0] < 'z') {
                value_name.clear();//отчистка имени переменной
                value_val.clear();//отчистка значения переменной
                bool equals_value = false;//проверка наличия '='
                for (int i = 0; i < in.size() && in[i] != ';'; i++) {
                    if (in[i] == '=') { equals_value = true; i++; }
                    if (!equals_value) { value_name.push_back(in[i]); }//запись имени переменной
                    else value_val.push_back(in[i]);//запись значения переменной
                }
                if (!equals_value) { throw  std::runtime_error("отсутствие '=' в переменной"); } //отсутствие '=' в переменной

                value["Section" + section_number + '.' + value_name] = value_val; //запись переменной
                //value.insert({ "Section" + section_number + '.' + value_name, value_val}); 

            }

            else if (in[0] == '\n' || in[0] == '\r' || in[0] == '\t') { throw  std::runtime_error("Ошибка чтения файла строка: " + std::to_string(stroka_counter));
            }
            
        }//Обход файла
    }

    template <typename T>
    T get_value(int section, std::string value) {
        if constexpr (std::is_same_v<T, std::string>) {
            std::string val = get_value_template(section, value);
            return val;
        }
        if constexpr (std::is_same_v<T, int>) {
            std::string val = get_value_template(section, value);
            return stoi(val);
        }
        if constexpr (std::is_same_v<T, double>) {
            std::string val = get_value_template(section, value);
            return stod(val);
        }
    }


    std::string get_value_template(int section, std::string val) {

        std::string answer = "Section" + std::to_string(section) + '.' + val;

        std::cout << "map------------------------- " << std::endl;
        for (const auto& elem : value)
            std::cout << "| " << elem.first << ": " << elem.second << std::endl;

        try {
            value.at(answer);
        }
        catch (...) { throw  std::runtime_error("Элемент отсутствует"); };
        
        if (value[answer] == "") { throw  std::runtime_error("Значение переменной отсутствует"); }

        return value[answer];

    }

    
    ~ini_parser() {
        file.close();
    }

private:
    std::ifstream file;
    std::map<std::string, std::string> value;//массив файла 
    std::string section_number;//номер секции 
    std::string value_name, value_val;//имя и значение переменной 
    int stroka_counter = 0; //cчетчик строк
};


int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        ini_parser parser("test.ini");  //filename
        auto value = parser.get_value<std::string>(4, "Mode"); //section.value
        std::cout << value;
    }
    catch (std::runtime_error& err) { std::cout << err.what() << std::endl; }
    catch (...) {
        std::cout << "Unknown error" << std::endl;
    }
    return 0;
}

