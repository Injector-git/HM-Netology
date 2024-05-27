#include <iostream>
#include<set>
#include<list>
#include<vector>

template<typename T>
void print_container(T &container) {
    auto print = container.begin();
    for (int i = 0; i < container.size(); i++) {
        std::cout << *print << " ";
        print++;
    }
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::cout << std::endl;

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::cout << std::endl;

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
}
