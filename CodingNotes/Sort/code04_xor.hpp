#pragma once
#include <vector>

class XOR {
public:
	static void swap(int &a, int &b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	/*
		题型一:
		一组数中，有一个数出现了奇数次，其他所有数出现了偶数次，求该出现了奇数次的数。
		e.g. { 1, 2, 3, 3, 2, 1, 4 }
	*/
	static int getOnlyOddTimesNum(int *arr, int len) {
		int eor = 0;
		for (int i = 0; i < len; i++) {
			eor ^= arr[i];
		}
		return eor;
	}

	/*
		题型二:
		一组数中，有两个数出现了奇数次，其他所有数出现了偶数次，求这两个出现了奇数次的数。
		e.g. { 1, 2, 3, 3, 2, 1, 4, 5}
	*/
	static std::vector<int> getTwoOddTimesNum(int *arr, int len) {
		int eor = 0;
		for (int i = 0; i < len; i++) {
			eor ^= arr[i];
		}
		int opp_byte = eor & (~eor + 1);
		int a = 0;
		for (int i = 0; i < len; i++) {
			if ((opp_byte & arr[i]) == 0) {
				a ^= arr[i];
			}
		}
		int b = eor ^ a;
		return {a, b};
	}
};