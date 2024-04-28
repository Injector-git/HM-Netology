#include <iostream>

class Smart_array {
public:
	Smart_array(int size) {
		this->size = size;
		arr = new int(size);
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
			throw ("Количество элементов больше количества элементов, на которую выделена память");
	}

	char get_element(int a) {
		if (a >= 0 && a <= size)
			return arr[a];
		else throw("Неккоректный идекс");
	}

	void operator=(Smart_array right) {

		if (size >= right.size)
			for (int i = 0; i < right.size; i++) {
				arr[i] = right.arr[i];
			}
		else
			throw("размер массив больше нужного");
		
	}

private:
	int* arr;
	int size;
	int i = 0;
};

int main()
{
	Smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	Smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;
}
