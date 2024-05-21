#include <iostream>
#include <vector>

template <typename T>
T pow(T a) {
    return a * a;
}

template <typename T>
std::vector<T>& pow(std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i]*= vec[i];
    }
    return vec;
}

int main()
{
    int in = 4;
    std::cout << "[IN]: " << in << std::endl;
    std::cout << "[OUT]: " << pow<int>(in) << std::endl;;

    
    std::vector<int> vec = { -1,  4, 8 };
    std::cout << "[IN]: ";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;

    pow(vec);

    std::cout << "[OUT]: ";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    return 0;

}
