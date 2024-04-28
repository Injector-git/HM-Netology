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
private:
	int* arr;
	int size;
	int i = 0;
};

int main()
{

	try {
		Smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
