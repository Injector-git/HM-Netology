#pragma once

class Counter {
private:
    int value;
public:

    Counter();
    Counter(int value);
    void increment();
    void decrement();
    int get_value();
};