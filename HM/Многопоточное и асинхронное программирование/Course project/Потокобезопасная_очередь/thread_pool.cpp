#include "thread_pool.h"

void thread_pool::submit(std::packaged_task<void()> task) {
	SafeQueue.push(std::move(task));
}

void thread_pool::work() {
	SafeQueue.pop().get_future();
}