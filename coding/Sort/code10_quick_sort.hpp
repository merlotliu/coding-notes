#pragma once
#include <random>
#include <time.h>
#include <iostream>

#include "ISort.h"

class QuickSort : public ISort{
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		srand((unsigned int)time(nullptr));
		quickSort(arr, 0, len-1);
	}

private:
	void quickSort(int *arr, int L, int R) {
		// end condition
		if (L >= R) {
			return;
		}

		//int flag = arr[R]; // 2.0
		// random flag
		int flag = arr[(rand() % (R - L + 1)) + L]; // 3.0
		//std::cout << (R - L + 1) << " " << r << " " << flag << std::endl;
		// partition
		std::vector<int> bound = partition(flag, arr, L, R);
		// recursion
		quickSort(arr, L, bound[0]);
		quickSort(arr, bound[1], R);
	}

	std::vector<int> partition(int flag, int *arr, int L, int R) {
		// Notes: start from L, not 0
		int less = L - 1; 
		int more = R + 1;

		while (L < more) {
			if (arr[L] < flag) {
				swap(arr, L++, ++less);
			} else if (arr[L] > flag) {
				swap(arr, L, --more);
			} else {
				L++;
			}
		}
		return {less, more};
	}

	std::vector<int> partition(int flag, std::vector<int> &arr, int L, int R) {
		// Notes: start from L, not 0
		int less = L - 1;
		int more = R + 1;

		while (L < more) {
			if (arr[L] < flag) {
				swap(arr, L++, ++less);
			}
			else if (arr[L] > flag) {
				swap(arr, L, --more);
			}
			else {
				L++;
			}
		}
		return { less, more };
	}
};