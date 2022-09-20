#pragma once
#include <vector>
#include <algorithm>

/* 这里的先后手都是相对于一个人而言 */
int firstPick(std::vector<int> &nums, int l, int r);
int secondPick(std::vector<int> &nums, int l, int r);

int firstPick(std::vector<int> &nums, int l, int r) {
	if (l == r) return nums[l];
	int left = secondPick(nums, l + 1, r) + nums[l];
	int right = secondPick(nums, l, r - 1) + nums[r];
	return std::max(left, right);
}

int secondPick(std::vector<int> &nums, int l, int r) {
	if (l == r) return 0;
	return std::min(firstPick(nums, l + 1, r), firstPick(nums, l, r - 1));
}

int winnerScore(std::vector<int> &nums) {
	return std::max(firstPick(nums, 0, nums.size() - 1), secondPick(nums, 0, nums.size() - 1));
}