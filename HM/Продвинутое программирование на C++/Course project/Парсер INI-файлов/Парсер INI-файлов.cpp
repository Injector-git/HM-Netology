#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>//для корректной работы кириллицы со стрингом

void print_V_console( std::string in, std::ifstream& asd) {
    std::cout << "stroka:" << asd.tellg() << "\t" << in << std::endl;
}

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

            trim(in);
            print_V_console(in, file);

            if (in[0] == ';') {
                continue;
            }

            else if (in[0] == '[') {/// Проверка коррекции [Section?]
                
                std::string string_template{ "[Section?]" };// шаблон [Section?]
                for (int i = 0; i < string_template.size(); i++) {
                    if (i == 8) { section_number = in[i]; i++; }//проскакивание числа и запись секции
                    if (in[i] != string_template[i]) { throw  std::runtime_error("Ошибка чтения файла "); }
                }
                // if((in[12] || in[13]) == ';') { throw  std::runtime_error("Кометарий после Section строка: "); } //отсутствие комеетария после Section
            }

            else if (in[0] > 'A' && in[0] < 'z') {
                bool equals_value = false;//проверка наличия '='
                for (int i = 0; i < in.size(); i++) {
                    if (in[i] == '=') { equals_value = true; i++; }
                    if (equals_value == false) { value_name.push_back(in[i]); }//запись имени переменной
                    else value_val.push_back(in[i]);//запись значения переменной
                }
                if (equals_value == false) { throw  std::runtime_error("отсутствие '=' в переменной"); } //отсутствие '=' в переменной

                if (section_number > value.capacity()) value.push_back({ value_name, value_val }); //запись переменной в вектор
                else value[section_number] = { value_name, value_val };

            }

            else if (in[0] == '\n' || in[0] == '\r' || in[0] == '\t') { throw  std::runtime_error("Ошибка чтения файла "); }
            
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

        //try {
        //    value[section]
       // }
       // catch (...) { std::cout << "Такой cекции нет" << std::endl; }

        auto test = value[section].find(val);
        std::string answer = test->second;

        std::cout << "answer=" << answer << std::endl;

        return answer;

    }

    
    ~ini_parser() {
        file.close();
    }

private:
    std::ifstream file;
    std::vector<std::map<std::string, std::string>> value;//массив из карт файла 
    int section_number = 0;//номер секции 
    std::string value_name, value_val;//имя и значение переменной 

};


int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        ini_parser parser("test.ini");  //filename
        auto value = parser.get_value<int>(1, "var2"); //section.value
        std::cout << value;
    }
    catch (std::runtime_error& err) { std::cout << err.what() << std::endl; }
    catch (...) {
        std::cout << "Unknown error" << std::endl;
    }
    return 0;
}

