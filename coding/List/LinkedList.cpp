#include "LinkedList.h"

#include <iostream>

void LinkedList::swap(ListNode *a, ListNode *b) {
	ListNode tmp = *a;
	*a = *b;
	*b = tmp;
}

ListNode* LinkedList::generateList(int *arr, int len) {
	if (arr == nullptr || len < 1) {
		return nullptr;
	}
	ListNode *head = new ListNode(arr[0], nullptr);
	ListNode *cur = head;
	for (int i = 1; i < len; i++) {
		cur->next = new ListNode(arr[i], nullptr);
		cur = cur->next;
	}
	return head;
}

ListNode* LinkedList::generateList(std::vector<int> &arr) {
	if (arr.size() < 1) {
		return nullptr;
	}
	ListNode *head = new ListNode(arr[0], nullptr);
	ListNode *cur = head;
	for (int i = 1; i < (int)arr.size(); i++) {
		cur->next = new ListNode(arr[i], nullptr);
		cur = cur->next;
	}
	return head;
}

LinkedList::LinkedList() {

}

LinkedList::LinkedList(int *arr, int len) {
	_head = generateList(arr, len);
}