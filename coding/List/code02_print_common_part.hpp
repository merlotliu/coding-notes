#pragma once
#include "LinkedList.h"

#include <iostream>

int LinkedList::printCommonPart(ListNode *head1, ListNode *head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return -1;
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
	return 0;
}