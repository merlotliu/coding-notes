#pragma once
#include <queue>
#include <iostream>
#include <algorithm>

class Median{
public:
	void insert(int num) {
		int max_heap_top = max_heap.empty() ? INT_MAX : max_heap.top();
		if (num < max_heap_top) {
			max_heap.push(num);
		} else {
			min_heap.push(num);
		}
		// adjust
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		} else if (min_heap.size() > max_heap.size() + 1) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}

	int getMedian() {
		if (min_heap.empty() && max_heap.empty()) return INT_MIN;
		if (min_heap.size() > max_heap.size()) {
			return min_heap.top();
		}
		if (min_heap.size() < max_heap.size()) {
			return max_heap.top();
		}
		return ((min_heap.top() + max_heap.top()) / 2);
	}
public:
	std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};

std::vector<int> generateRandomArray(int max_size, int max_val, int min_val) {
	int size = rand() % max_size;
	std::vector<int> res;
	for (int i = 0; i < size; i++) {
		int num1 = (rand() % (max_val - min_val + 1)) + min_val;
		int num2 = (rand() % (max_val - min_val + 1)) + min_val;
		res.push_back(num1 - num2);
	}
	return res;
}

void printArray(std::vector<int> &arr) {
	for (auto num : arr) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
