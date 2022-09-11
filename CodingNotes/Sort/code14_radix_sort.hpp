#pragma once
#include <iostream>

#include "ISort.h"

class RadixSort : public ISort {
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		// get max bit
		int bits = getBits(getMax(arr, 0, len-1));
		radixSort(arr, 0, len - 1, bits);
	}

	void radixSort(int *arr, int L, int R, int bits, int radix = 10) {
		int *help = new int[R - L + 1]; // ��������
		for (int bit = 1; bit <= bits; bit++) { // ���λΪ������Ͱ����
			//std::cout << "Bit : " << bit << std::endl;
			int *count = new int[radix](); // ͳ�ƴ�Ƶ
			// ����arr��ͳ�ƴ�Ƶ
			for (int i = L; i <= R; i++) {
				int bit_num = gitBitNum(arr[i], bit, radix);
				count[bit_num]++;
			}
			// ����count�����ǰ׺��
			for (int i = 1; i < radix; i++) {
				count[i] += count[i - 1];
				//std::cout << count[i] << " ";
			}
			//std::cout << std::endl;
			// Ϊ�����Ƚ��ȳ�,�Ӻ���ǰ����ԭ���飬����������countǰ׺�͵ó��ĸ�������λ��
			for (int i = R; i >= L; i--) {
				int bit_num = gitBitNum(arr[i], bit, radix);
				help[--count[bit_num]] = arr[i];
			}
			// ���ƻ�ԭ�����Ա���ôδ�����
			for (int i = L, j = 0; i <= R; i++, j++) {
				arr[i] = help[j];
				//std::cout << arr[i] << " ";
			}
			//std::cout << std::endl;
			delete[] count;
		}
		delete[] help;
		return;
	}

	int getMax(int *arr, int L, int R) {
		int max_index = 0;
		for (int i = L; i <= R; i++) {
			if (arr[i] < 0) {
				std::cout << "Error : Negative Number!" << std::endl;
				return -1;
			}
			max_index = arr[max_index] < arr[i] ? i : max_index;
		}
		return arr[max_index];
	}

	// ��ȡ���ֵ�λ��
	int getBits(int num, int radix = 10) {
		int res = 0;
		while (num > 0) {
			num /= radix;
			res++;
		}
		return res;
	}

	// ��ȡbitλ�ϵ�����
	// 1 ��λ
	// 2 ʮλ
	// ...
	int gitBitNum(int num, int bit, int radix = 10) {
		int res = 0;
		while(bit-- > 0) {
			res = num % radix;
			num /= radix;
		}
		return res;
	}
};