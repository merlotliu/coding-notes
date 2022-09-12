#pragma once
#include "LinkedList.h"

ListNode* LinkedList::partitionWithPivotAndArray(ListNode *head, int pivot) {
	if (head == nullptr || head->next == nullptr) return head;
	// push into array
	ListNode *cur = head;
	std::vector<ListNode*> arr;
	while (cur != nullptr) {
		arr.push_back(cur);
		cur = cur->next;
	}
	// partition
	int less = -1;
	int more = (int)arr.size();
	for (int i = 0; i < more; ) {
		if (arr[i]->val < pivot) {
			swap(arr[++less], arr[i++]);
		} else if (arr[i]->val > pivot) {
			swap(arr[--more], arr[i]);
		} else {
			i++;
		}
	}
	// rejoint
	int i = 1;
	for (; i < (int)arr.size(); i++) {
		arr[i - 1]->next = arr[i];
	}
	arr[i-1]->next = nullptr;
	return arr[0];
}

ListNode* LinkedList::partitionWithPivot(ListNode *head, int pivot) {
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *less_head, *less_tail, *pivot_head, *pivot_tail, *more_head, *more_tail;
	less_head = less_tail = pivot_head = pivot_tail = more_head = more_tail = nullptr;
	// partition
	ListNode *cur = head;
	while (cur) {
		if (cur->val < pivot) {
			if (less_head == nullptr) {
				less_head = less_tail = cur;
			} else {
				less_tail->next = cur;
				less_tail = cur;
			}
		} else if (cur->val == pivot) {
			if (pivot_head == nullptr) {
				pivot_head = pivot_tail = cur;
			}
			else {
				pivot_tail->next = cur;
				pivot_tail = cur;
			}
		} else {
			if (more_head == nullptr) {
				more_head = more_tail = cur;
			}
			else {
				more_tail->next = cur;
				more_tail = cur;
			}
		}
		cur = cur->next;
	}
	// joint
	if (less_head != nullptr) {
		less_tail->next = pivot_head != nullptr ? pivot_head : more_head;
	}
	if (pivot_head != nullptr) {
		pivot_tail->next = more_head;
	}
	// final head
	head = less_head ? less_head : (pivot_head ? pivot_head : more_head);
	return head;
}