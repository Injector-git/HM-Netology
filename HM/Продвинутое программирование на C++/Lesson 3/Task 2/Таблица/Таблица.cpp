#include <iostream>

template <typename T>
class Table {
public:
    Table(int row, int column) {
        this->row = row;
        this->column = column;
        arr = new T* [row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[column];
        }
    }

    int size() {
        return row * column;
    }

    T* operator[](T index) {
        return arr[index];
    }

    const T* operator[](T index) const{
        return arr[index];
    }

private:
    T** arr;
    int row = 0;
    int column = 0;
};
int main()
{
    Table<int> test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}
