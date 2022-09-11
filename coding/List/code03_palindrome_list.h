#pragma once
#include "LinkedList.h"

#include <stack>

bool LinkedList::isPalindromeListWithStack(ListNode *head) {
	std::stack<ListNode*> stk;
	ListNode *cur = head;
	while (cur) {
		stk.push(cur);
		cur = cur->next;
	}
	cur = head;
	while (!stk.empty()) {
		if (cur != stk.top()) {
			return false;
		}
		cur = cur->next;
		stk.pop();
	}
	return true;
}

