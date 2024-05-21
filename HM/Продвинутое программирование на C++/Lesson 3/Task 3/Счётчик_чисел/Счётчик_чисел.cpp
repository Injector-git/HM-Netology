#include <iostream>

class Counter {
public:
    Counter() = default;
    void operator()(int number) { // определение оператора круглых скобок
        if (number % 3 == 0) {
            sum += number;
            counter++;
        }
    }

    int get_sum() {
        return sum;
    }

    int get_count() {
        return counter;
    }
private:
    int sum = 0;
    int counter = 0;
};


int main()
{
    Counter counter;
    counter(4);
    counter(1);
    counter(3);
    counter(6);
    counter(25);
    counter(54);
    /*const int size = 6;
    int arr[size] = { 4, 1, 3, 6, 25, 54 };*/

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;
}
