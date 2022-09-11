#pragma once
class GetMax {
public:
	static int getMax(int *arr, int len) {
		return getMax(arr, 0, len - 1);
	}

	static int getMax(int *arr, int l, int r) {
		// end condition
		if (l == r) {
			return arr[l];
		}
		// recursion
		int m = l + ((r - l) >> 1); // prevent overflow
		int left_max = getMax(arr, l, m);
		int right_max = getMax(arr, m+1, r);
		return max(left_max, right_max);
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}
};