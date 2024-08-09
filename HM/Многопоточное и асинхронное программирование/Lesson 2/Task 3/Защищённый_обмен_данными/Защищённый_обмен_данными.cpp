#include <iostream>
#include<mutex>

class Data {
public:
    int data1;
    double data2;
    std::mutex m;

    Data() = default;
    Data(int d1, double d2) {
        data1 = d1;
        data2 = d2;
    }

    void swap1(Data& D1, Data& D2) {
        std::lock(D1.m, D2.m);
        Data tmp;

        tmp.data1 = D1.data1;
        tmp.data2 = D1.data2;

        D1.data1 = D2.data1;
        D1.data2 = D2.data2;

        D2.data1 = tmp.data1;
        D2.data2 = tmp.data2;
        
        D1.m.unlock();
        D2.m.unlock();
    }

    void swap2(Data& D1, Data& D2) {
        std::scoped_lock{ D1.m, D2.m };
        Data tmp;

        tmp.data1 = D1.data1;
        tmp.data2 = D1.data2;

        D1.data1 = D2.data1;
        D1.data2 = D2.data2;

        D2.data1 = tmp.data1;
        D2.data2 = tmp.data2;
    }

    void swap3(Data& D1, Data& D2) {
        std::unique_lock ul1{ D1.m };
        std::unique_lock ul2{ D2.m };
        Data tmp;

        tmp.data1 = D1.data1;
        tmp.data2 = D1.data2;

        D1.data1 = D2.data1;
        D1.data2 = D2.data2;

        D2.data1 = tmp.data1;
        D2.data2 = tmp.data2;

        ul1.unlock();
        ul2.unlock();
    }


};

int main()
{
    Data D1(1111,3333.3);
    Data D2(5555,9999.9);

    std::cout << "D1 = " << D1.data1 << " " << D1.data2 << std::endl;
    std::cout << "D2 = " << D2.data1 << " " << D2.data2 << std::endl;

    D1.swap1(D1, D2);

    std::cout << "D1 = " << D1.data1 << " " << D1.data2 << std::endl;
    std::cout << "D2 = " << D2.data1 << " " << D2.data2 << std::endl;

    D1.swap2(D1, D2);

    std::cout << "D1 = " << D1.data1 << " " << D1.data2 << std::endl;
    std::cout << "D2 = " << D2.data1 << " " << D2.data2 << std::endl;

    D1.swap3(D1, D2);

    std::cout << "D1 = " << D1.data1 << " " << D1.data2 << std::endl;
    std::cout << "D2 = " << D2.data1 << " " << D2.data2 << std::endl;
}

