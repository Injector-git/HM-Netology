#include "thread_pool.h"

thread_pool::thread_pool() {
	ThreadVec = new std::vector<std::thread>[4];//4 ядра
}

thread_pool::~thread_pool() {
	delete[] ThreadVec;
}

void thread_pool::submit(std::packaged_task<void()> task) {

	SafeQueue.push(std::move(task));
	thread_pool::work();
}

void thread_pool::work() {
	ThreadVec[i] = { std::thread(std::move(SafeQueue.pop())) };
	i++;
	if (i > 4)i = 0;
}