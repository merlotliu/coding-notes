#pragma once
#include "ISort.h"

class CountSort : public ISort {
public:
	/*
		年龄排序（假设数据范围在0-200之间）
	*/
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		ageCountSort(arr, 0, len-1);
	}

	void ageCountSort(int *arr, int L, int R) {
		int *count = new int[200]();
		for (int i = L; i <= R; i++) {
			count[arr[i]]++;
		}
		int idx = L;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < count[i]; j++) {
				arr[idx++] = i;
			}
		}
		delete[]count;
		return;
	}
};