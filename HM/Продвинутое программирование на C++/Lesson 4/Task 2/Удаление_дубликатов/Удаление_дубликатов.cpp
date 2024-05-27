#include <iostream>
#include <set>


int main()
{
    std::cout << "[IN]:" << std::endl;
    int size, number;
    std::cin >> size;

    std::set<int,std::greater<>> my_set;

    for (int i = 0; i < size; i++) {
        std::cin >> number;
        my_set.insert(number);
    }

    std::cout << "[OUT]:" << std::endl;
    for (const auto& elem : my_set)
        std::cout << elem << std::endl;
}
