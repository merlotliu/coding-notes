#pragma once
#include "ISort.h"

class SelectionSort : public ISort {
public:
	void sort(int *arr, int len) {
		return selectionSort(arr, len);
	}

private:
	void selectionSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return ;
		}
		for (int i = 0; i < len - 1; i++) {
			int min_idx = i;
			for (int j = i + 1; j < len; j++) {
				if (arr[min_idx] > arr[j]) {
					min_idx = j;
				}
			}
			if (min_idx != i) {
				swap(arr, i, min_idx);
			}
		}
		return ;
	}
};