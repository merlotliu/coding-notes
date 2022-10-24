#include <iostream>

#include "maxSlidingWindow.h"

void printArr(vector<int> &arr) {
	for (auto elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}

int main() {
	Solution s;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> arr = s.maxSlidingWindow(nums, 3);
	printArr(arr);

	return 0;
}