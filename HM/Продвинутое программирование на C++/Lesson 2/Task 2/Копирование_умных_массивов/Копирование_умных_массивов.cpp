#include <iostream>

class Smart_array {
public:

	Smart_array(int size) {
		this->size = size;
		arr = new int[size];
	}

	~Smart_array() {
		delete[] arr;
	}

	void add_element(int a) {
		if (i < size) {
			arr[i] = a;
			i++;
		}
		else
			throw exp;
	}
	
	int get_element(int a) {
		if (a >= 0 && a < size)
			return arr[a];
		else throw exp;
	}

	Smart_array& operator=(const Smart_array& right) {

		if (arr == right.arr) return right;
		~Smart_array;
		Smart_array new_arr(right.size);
		for (int i = 0; i < right.size; i++) {
			new_arr[i] = right.arr[i];
		}
		return new_arr;
	}

	Smart_array(const Smart_array& right) { //Конструктор копирования

		Smart_array new_arr(right.size);
		for (int i = 0; i < right.size; i++) {
			new_arr[i] = right.arr[i];
		}
		return new_arr;
	}

private:
	int* arr;
	int size;
	int i = 0;
	std::exception exp;
};

int main()
{

	Smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	Smart_array new_array(4);
	new_array.add_element(44);
	new_array.add_element(34);
	new_array.add_element(24);
	new_array.add_element(14);

	arr = new_array;

}
