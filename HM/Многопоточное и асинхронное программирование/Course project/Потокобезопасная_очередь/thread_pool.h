#pragma once
#include "safe_queue.h"
#include<vector>
#include<thread>
#include<future>


class thread_pool {
public:
	thread_pool();
	~thread_pool();
	void submit(std::packaged_task<void()> task);
	void work();
private:
	std::vector<std::thread>* ThreadVec;
	safe_queue<std::packaged_task<void()>> SafeQueue;
	int i{};//номер исполняемого потока
};