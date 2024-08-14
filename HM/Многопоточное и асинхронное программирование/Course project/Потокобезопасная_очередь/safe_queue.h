#pragma once
#include<iostream>
#include<queue>
#include<mutex>
#include<condition_variable>

template<class T>
class safe_queue {
public:
	safe_queue() = default;
	void push(T task) {

		std::unique_lock ulock(mute);
		ulock.lock();
		std::cout << "PUSH" << std::endl;
		queue_task.push(task);

		ulock.unlock();
		add = true;
		ConditionVarible.notify_one();
	}

	T pop() {

		std::unique_lock ulock(mute);
		std::cout << "POP" << std::endl;
		ConditionVarible.wait(ulock,[] {return add; });

		add = false;
		return 	queue_task.pop();
	}

private:
	std::queue<T> queue_task;
	std::mutex mute;
	std::condition_variable ConditionVarible{ true };
	bool add = false;
};