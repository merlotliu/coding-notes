#pragma once
#include <queue>
#include <algorithm>

#include "ISort.h"

class HeapSort : public ISort {
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		// construct big heap O(N * logN)
		//for (int i = 0; i < len; i++) { // O(N)
		//	heapInsert(arr, i); // O(logN)
		//}
		// method 2 O(N)
		for (int i = len - 1; i >= 0; i--) { 
			heapify(arr, i, len);
		}

		int heap_size = len;
		swap(arr, 0, --heap_size); // O(1)
		while (heap_size > 0) { // O(N)
			heapify(arr, 0, heap_size); // O(N * logN)
			swap(arr, 0, --heap_size); // O(1)
		}
		return;
	}

	void heapInsert(int *arr, int index) {
		int parent = (index - 1) / 2;
		while (arr[index] > arr[parent]) {
			swap(arr, index, parent);
			index = parent;
		}
	}

	void heapify(int *arr, int index, int heap_size) {
		int left = index * 2 + 1; // left child
		while (left < heap_size) { // left child exist
			int max_index = left + 1 < heap_size && arr[left + 1] > arr[left] ? left + 1 : left; // max of children
			max_index = arr[index] < arr[max_index] ? max_index : index; // max between parents & children
			if (max_index == index) {
				break;
			}
			swap(arr, index, max_index);
			index = max_index;
			left = index * 2 + 1;
		}
		return;
	}

	void sortDistanceLessK(int *arr, int len, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<int>> q; // default big heap
		int i = 0;
		for (; i <= std::min(k, len); i++) {
			q.push(arr[i]);
		}
		int j = 0;
		while (i < len) {
			arr[j++] = q.top();
			q.pop();
			q.push(arr[i++]);
		}
		while (!q.empty()) {
			arr[j++] = q.top();
			q.pop();
		}
	}
};