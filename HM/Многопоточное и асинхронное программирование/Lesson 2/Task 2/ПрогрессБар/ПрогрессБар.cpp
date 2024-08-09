#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <Windows.h>
#include <string>



class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);




std::mutex m;
consol_parameter handle;
using namespace std::chrono_literals;


void printBar(int number) {

    m.lock();
    handle.SetPosition(0, number + 1);
    std::cout << number << " " << std::this_thread::get_id();
    auto start = std::chrono::steady_clock::now();
    m.unlock();

    int time{ 20 };
    for (int i{}; i < time; i++)
    {
        std::this_thread::sleep_for(200ms);
        m.lock();
        handle.SetPosition(8 + i, number + 1);
        std::cout << ">";
        m.unlock();
    }


    m.lock();
    auto end = std::chrono::steady_clock::now();
    handle.SetPosition(time+12, number + 1);
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << elapsed_seconds.count() << "s\t";
    m.unlock();

};

int main()
{
    int amount = 4;
    std::cout << "# id\t Progress Bar\t\t Time\n";

    std::vector<std::thread> ProgressBar(amount);
    for (int i{}; i < amount; i++) {
        ProgressBar[i] = (std::thread(printBar,i));
    }

    for (int i{}; i < amount; i++) {
        ProgressBar[i].join();
    }
    handle.SetPosition(0, 5);

    return EXIT_SUCCESS;
}

