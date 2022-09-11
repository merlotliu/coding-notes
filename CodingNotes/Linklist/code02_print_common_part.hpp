#pragma once

#include "LinkedList.h"

#include <iostream>

void LinkedList::printCommomPart(LinkedNode *head1, LinkedNode *head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return;
	}
	while (head1 && head2) {
		if (head1->val == head2->val) {
			std::cout << head1->val;
			head1 = head1->next;
			head2 = head2->next;
		} else if (head1->val < head2->val) {
			head1 = head1->next;
		} else {
			head2 = head2->next;
		}
	}
	return;
}