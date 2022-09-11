#pragma once
#include "ISort.h"

class InsertionSort : public ISort {
public:
	void sort(int *arr, int len) {
		return insertionSort(arr, len);
	}

private:
	void insertionSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		for (int i = 1; i < len; i++) {
			for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
				swap(arr, j, j-1);
			}
		}
	}
};
