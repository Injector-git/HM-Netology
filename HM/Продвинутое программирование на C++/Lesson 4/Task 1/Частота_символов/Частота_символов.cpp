#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<char, int, std::greater<>> my_map;

    std::string str;

    std::cout << "[IN]: ";
    getline(std::cin, str);
    std::cout << std::endl;

    for (int i = 0; i < str.size(); i++) {
        my_map[str[i]]++;
    }

    for (const auto& elem : my_map) {
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}

