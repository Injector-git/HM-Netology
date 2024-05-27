#include <iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
    
    std::cout << "[IN]: ";
    for (int i = 0; i < vec.size();i++) {
        std::cout << vec[i] << " ";
    }

    std::sort(vec.begin(), vec.end());
    auto un = std::unique(vec.begin(), vec.end());;
    vec.erase(un, vec.end());
    std::cout << std::endl;

    std::cout << "[OUT]: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    return 0;
}
