#pragma once
#include "ISort.h"

class MergeSort : public ISort {
	/*
		归并排序
	*/
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		mergeSort(arr, 0, len - 1);
	}

private:
	void mergeSort(int *arr, int l, int r) {
		if (l == r) {
			return;
		}
		int m = l + ( (r - l) >> 1 );
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
		return;
	}

	void merge(int *arr, int l, int m, int r) {
		int *help = new int[r - l + 1];
		int i = 0; 
		int p1 = l;
		int p2 = m+1;
		while (p1 <= m && p2 <= r) {
			help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
		}
		while (p1 <= m) {
			help[i++] = arr[p1++];
		}
		while (p2 <= r) {
			help[i++] = arr[p2++];
		}
		for (int j = l, i = 0; j <= r; ) {
			arr[j++] = help[i++];
		}
		delete[] help;
		return;
	}

	/*
		小和问题
	*/
public:
	int getSmallSum(int *arr, int l, int r) {
		if (l == r) {
			return 0;
		}
		int m = l + ((r - l) >> 1);
		return getSmallSum(arr, l, m) + getSmallSum(arr, m + 1, r) + getPartSmallSum(arr, l, m, r);
	}

private:
	int getPartSmallSum(int *arr, int l, int m, int r) {
		int *help = new int[r - l + 1];
		int i = 0;
		int p1 = l;
		int p2 = m + 1;
		int res = 0;
		while (p1 <= m && p2 <= r) {
			res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
			help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
		}
		while (p1 <= m) {
			help[i++] = arr[p1++];
		}
		while (p2 <= r) {
			help[i++] = arr[p2++];
		}
		for (int j = l, i = 0; j <= r; ) {
			arr[j++] = help[i++];
		}
		delete[] help;
		return res;
	}
};