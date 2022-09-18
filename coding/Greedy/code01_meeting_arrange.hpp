#pragma once
#include <vector>
#include <algorithm>

int getMaxArrangeMeetingCount(std::vector<std::vector<int>> &meetings) {
	auto cmp = [](std::vector<int> &a, std::vector<int> &b) {
		return a[1] < b[1];
	};
	std::sort(meetings.begin(), meetings.end(), cmp);
	int res = 0;
	int last_end_time = -1;
	for (auto m : meetings) {
		if (m[0] >= last_end_time) {
			last_end_time = m[1];
			res++;
		}
	}
	return res;
}

std::vector<std::vector<int>> generateRandomArray(int max_size, int max_val, int min_val) {
	int size = rand() % max_size;
	std::vector<std::vector<int>> res;
	for (int i = 0; i < size; i++) {
		int num1 = (rand() % (max_val - min_val + 1)) + min_val;
		int num2 = (rand() % (max_val - min_val + 1)) + min_val;
		res.push_back({ num1, num2 });
	}
	return res;
}