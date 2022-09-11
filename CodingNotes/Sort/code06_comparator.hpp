#pragma once
#include <random>
#include <iostream>
#include <algorithm>

// 对数器
class Comparator {
public:
	static void sort(int *arr, int len) {
		qsort(arr, len, sizeof(int), [](const void* a, const void* b) {
				int arg1 = *static_cast<const int*>(a);
				int arg2 = *static_cast<const int*>(b);

				if (arg1 < arg2) return -1;
				if (arg1 > arg2) return 1;
				return 0;

				//  返回 (arg1 > arg2) - (arg1 < arg2); // 可行的缩写
				//  返回 arg1 - arg2; // 错误的缩写（若有 INT_MIN 则失败）
			});
	}

	static int* generateRandomArray(int max_size, int max_val, int &len, int min_size = 0, int positive_only = 0) {
		len = (rand() % (max_size - min_size + 1)) + min_size;
		//len = 10;
		int *arr = new int[len];
		if (positive_only) {
			for (int i = 0; i < len; i++) {
				arr[i] = (rand() % max_val); // only positive number
			}
		} else {
			for (int i = 0; i < len; i++) {
				arr[i] = (rand() % max_val) - (rand() % max_val);
			}
		}
		return arr;
	}

	static int* copyArray(int *src, int len) {
		if (src == nullptr) {
			return nullptr;
		}
		int *res = new int[len];
		for (int i = 0; i < len; i++) {
			res[i] = src[i];
		}
		return res;
	}

	static int isEqual(int *arr_a, int len_a, int *arr_b, int len_b) {
		if (len_a != len_b) {
			return false;
		}
		for (int i = 0; i < len_a && arr_a[i] != arr_b[i]; i++) {
			return false;
		}
		return true;
	}
};