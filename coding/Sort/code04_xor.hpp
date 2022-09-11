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
		����һ:
		һ�����У���һ���������������Σ�����������������ż���Σ���ó����������ε�����
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
		���Ͷ�:
		һ�����У��������������������Σ�����������������ż���Σ��������������������ε�����
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