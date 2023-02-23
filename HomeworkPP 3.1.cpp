#include <iostream>
#include <Windows.h>

class smart_array {
private:
	int* arr;
	int size = 0;
	int queue = 0;
public:
	smart_array(int input) {
		this->size = input;
		arr = new int[size];
	}

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

	void add_element(int input) {
		if (queue < size) {
			arr[queue] = input;
			++queue;
		}
		else {
			 throw std::runtime_error("Превышен размер массива");
		}
	}

	int get_element(int input) {
		if (input >= 0 && input < queue) {
			return arr[input];
		}
		else {
			 throw std::runtime_error("Ошибка, указан неправильный индекс элемента.");
		}
	}

	~smart_array() {
		delete[] arr;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
