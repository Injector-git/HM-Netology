#include <iostream>
#include <vector>
#include <future>
#include <thread>

void mySort(std::vector<int> vec, std::promise<std::vector<int>> pr) {
    for (int i{}; i < vec.size() - 1; i++) {
        int min{ INT_MAX };
        int index_min{};

        for (int j{ i }; j < vec.size(); j++) {

            if (vec[j] < min) { min = vec[j]; index_min = j; }
        }

        vec[index_min] = vec[i];
        vec[i] = min;

    }
    pr.set_value(vec);
}

int main()
{
    std::vector<int> vec{43, 5, 8, 5, 342, 5, 34, 6, 123, 52, 3, 123, 20};

    std::promise<std::vector<int>> prom{};

    std::future<std::vector<int>> fut{ prom.get_future() };

    auto result = std::async(std::launch::async, mySort, vec, std::move(prom));

    for (int i : fut.get()) {
        std::cout << i << " ";
    }
    

    
}

