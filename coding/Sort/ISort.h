#pragma once
#include <vector>

class ISort {
public:
	virtual void sort(int *arr, int len) {}

	void swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	void swap(std::vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};