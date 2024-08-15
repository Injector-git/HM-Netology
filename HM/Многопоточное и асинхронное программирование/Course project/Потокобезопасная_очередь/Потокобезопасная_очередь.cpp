#include "Потокобезопасная_очередь.h"
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

void print_name1() {
	std::cout << "task 1 Mark" << std::endl;
}

//void print_name2(std::string name) {
//	std::cout << "task2 " << name << std::endl;
//}
//
//std::string print_name3(std::string name) {
//	std::cout << name << std::endl;
// return "task 3 " + name;
//}

int main()
{

	thread_pool tp;
	std::vector<std::packaged_task<void()>> tasks(10);
	
	for (int i{}; i < tasks.size(); ++i) {
		tasks[i] = std::packaged_task<void()>(print_name1);
	}

	for (int i{}; i < tasks.size(); i+=2) {
		tp.submit(std::move(tasks[i]));
		tp.submit(std::move(tasks[i+1]));
		std::this_thread::sleep_for(1000ms);
	}

	return 0;
}
