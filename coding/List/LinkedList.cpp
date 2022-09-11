#include "LinkedList.h"

#include <iostream>

void LinkedList::printCommonPart(ListNode *head1, ListNode *head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return;
	}
	while (head1 && head2) {
		if (head1->val == head2->val) {
			std::cout << head1->val << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head1->val < head2->val) {
			head1 = head1->next;
		}
		else {
			head2 = head2->next;
		}
	}
	std::cout << std::endl;
	return;
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

LinkedList::LinkedList() {

}

LinkedList::LinkedList(int *arr, int len) {
	_head = generateList(arr, len);
}