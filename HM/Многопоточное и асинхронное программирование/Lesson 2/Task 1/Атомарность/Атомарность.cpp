#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std::chrono_literals;

void customer(std::atomic<int>& counter) {
    do
    {
        std::this_thread::sleep_for(1000ms);
        counter.fetch_add(1, std::memory_order_release);
        std::cout << "counter customer = " << counter << "\n";
    } while (counter < 5);


}

void oper(std::atomic<int>& counter) {
    do
    {
        std::this_thread::sleep_for(2000ms);
        counter.fetch_add(-1, std::memory_order_consume);
        std::cout << "counter oper = " << counter << "\n";
    } while (counter != 0);

}

int main()
{
    std::atomic<int> counter{ 1 };
    std::thread ThreadCus{ customer, std::ref(counter) };
    std::thread ThreadOp{ oper, std::ref(counter) };

    ThreadCus.join();
    ThreadOp.join();


    std::cout << "Work is done!\n";
    return 0;
}

