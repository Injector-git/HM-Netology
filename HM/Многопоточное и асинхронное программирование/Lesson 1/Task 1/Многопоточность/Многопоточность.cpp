#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void customer(int& counter) {
    do
    {
        std::this_thread::sleep_for(1000ms);
        counter++;
        std::cout << "counter customer = " << counter << "\n";
    } while (counter<5);


}

void oper(int& counter) {
    do
    {
        std::this_thread::sleep_for(2000ms);
        counter--;
        std::cout << "counter oper = " << counter << "\n";
    } while (counter!=0);

}

int main()
{
    int counter{1};
    std::thread ThreadCus{ customer, std::ref(counter)};
    std::thread ThreadOp{ oper, std::ref(counter) };

    ThreadCus.join();
    ThreadOp.join();


    std::cout << "Work is done!\n";
    return 0;
}
