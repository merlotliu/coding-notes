#pragma once
class ISort {
public:
	virtual void sort(int *arr, int len) {}

	void swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};