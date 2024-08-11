#include <iostream>
#include <vector>
#include <future>
#include <thread>


void mySort(std::vector<int> vec, int i, std::promise<int*> pr) {

    int min[]{ INT_MAX, i };

        for (int j{ i }; j < vec.size(); j++) {

            if (vec[j] < min[0]) { min[0] = vec[j]; min[1] = j; }
        }

        pr.set_value(min);
}

int main()
{
    int asd[3];
    int sdf[3];
    std::vector<int> vec{43, 5, 8, 5, 342, 5, 34, 6, 123, 52, 3, 123, 20};



    for (int i{}; i < vec.size() - 1; i++) {

        int* min;
        int index_min{};

        std::promise<int*> prom{};
        std::future<int*> fut{ prom.get_future() };
        std::async(std::launch::async, mySort, vec, i,std::move(prom));

        min = fut.get();
        vec[min[1]] = vec[i];
        vec[i] = min[0];
    }

    

    for (int i : vec) {
        std::cout << i << " ";
    }
    

    
}

