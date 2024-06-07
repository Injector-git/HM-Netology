#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class ini_parser {

public:
    ini_parser(std::string filename) {
        file.open(filename);
    }

    template <typename T>
    T get_value(int section, std::string value) {
        std::string in;
        bool section_name = false;//проверка наличия секции

        while (!(file >> in).eof()) {//Обход файла

 
            if (in[0] == '[') {/// Поиск нужной секции

                int n = in.find('n');// временная переменная
                std::string string_section;// стринговое значение секции
                while (in[++n] != ']') {
                    string_section.push_back(in[n]);
                }
                
                if (section == std::stoi(string_section)) {/// Поиск нужного значения
                    section_name = true;
                    bool value_name = false;//проверка наличия имени значения

                    while (value_name != true) {//сравнение имени значения
                        file >> in; //переход на следующую строку
                        if (in[0] == value[0]) {
                            for (int i = 1; in[i]!='='; i++) {
                                if (in[i] == value[i]) value_name = true;
                                else { value_name = false; break; }
                            }
                        }
                    }//сравнение имени значения
                    if (value_name == false) { throw std::runtime_error("Такой переменной нет"); }

                    int equals = in.find('=');// временная переменная
                    equals++;
                    std::string string_value;// стринговое значение значения
                    while(in[equals] != 0 && in[equals] != ';'){
                        string_value.push_back(in[equals]);
                        equals++;
                    }
                    if (string_value.size() == 0) { throw std::runtime_error("Нет значения для этой переменной"); }
                    else {
                        return std::stoi(string_value);
                        //return string_value;
                        /* (T == int) { return std::stoi(string_value); }
                        else if (T == std::string) { return string_value }
                        */
                    }
                    
                }/// Поиск нужного значения

            }/// Поиск нужной секции

        }//Обход файла
        if (section_name == false) { throw std::runtime_error("Такой cекции нет"); }

    }

    /*std::ifstream get_file() {
        return file;
    }*/
    
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

    ini_parser parser("test.ini");  //filename

    auto value = parser.get_value<int>(2,"var1");   //section.value
    std::cout << value;
}

