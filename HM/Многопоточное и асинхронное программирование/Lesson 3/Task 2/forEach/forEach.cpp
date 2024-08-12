#include <algorithm>
#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <random>



template<typename Iterator, typename T>
void parallel_forEach(Iterator first, Iterator last, T init)
{
	unsigned long const length = std::distance(first, last);
	unsigned long const max_chunk_size = 25;
	if (length <= max_chunk_size)
	{
		auto F = first;
		auto L = last;
		for (; F != L; ++F) {
			init(*F);
		}
	}
	else
	{
		Iterator const mid_point = first + length / 2;
		std::future<void> first_half_result = std::async(parallel_forEach<Iterator, T>, first, mid_point, init);
		parallel_forEach(mid_point, last, init);
	}

}

int main()
{
	std::vector<int> V(100,2);

	parallel_forEach(V.begin(), V.end(), [](int& n) { n++;});
	
	for (int i: V) {
		std::cout << i << " ";
	}

	return 0;
}