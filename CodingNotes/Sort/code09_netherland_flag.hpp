#pragma once

class NetherlandFlag {
public:
	static void easyNetherlandFlag(int num, int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		int l = -1;
		for (int i = 0; i < len; i++) {
			if (arr[i] <= num) {
				swap(arr, i, ++l);
			}
		}
		return;
	}

	static void netherlandFlag(int num, int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		int l = -1;
		int r = len;
		for (int i = 0; i < r; ) {
			if (arr[i] < num) {
				swap(arr, i++, ++l);
			} else if (arr[i] > num) {
				swap(arr, i, --r);
			} else {
				i++;
			}
		}
		return;
	}

	static void swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};