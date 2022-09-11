#pragma once
#include "ISort.h"

class BubbleSort : public ISort {
public:
	void sort(int *arr, int len) {
		return bubbleSort(arr, len);
	}

private:
	void bubbleSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}

		for (int j = len - 1; j > 0; j--) {
			for (int i = 0; i < j; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr, i, i + 1);
				}
			}
		}
		return;
	}
};