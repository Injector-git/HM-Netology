#pragma once
#include "safe_queue.h"
#include<vector>
#include<thread>
#include<future>

class thread_pool {
public:
	void submit(std::packaged_task<void()> task);
	void work();
private:
	std::vector<std::packaged_task<void()>> ThreadVec;
	safe_queue<std::packaged_task<void()>> SafeQueue;
};