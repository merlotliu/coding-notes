#pragma once
#include "LinkedList.h"

#include <stack>

bool LinkedList::isPalindromeListWithStack(ListNode *head) {
	if (head == nullptr) return false;
	if (head->next == nullptr) return true;
	// push into stack
	std::stack<ListNode*> stk;
	ListNode *cur = head;
	while (cur) {
		stk.push(cur);
		cur = cur->next;
	}
	// pop out stack & compare
	cur = head;
	while (!stk.empty()) {
		if (cur->val != stk.top()->val) return false;
		cur = cur->next;
		stk.pop();
	}
	return true;
}

bool LinkedList::isPalindromeListWithStackAndTwoPoints(ListNode *head) {
	if (head == nullptr) return false;
	if (head->next == nullptr) return true;
	// find middle position
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != nullptr) slow = slow->next; // even
	// push into stack
	std::stack<ListNode*> stk;
	while (slow != nullptr) {
		stk.push(slow);
		slow = slow->next;
	}
	// pop out stack & compare
	while (!stk.empty()) {
		if (head->val != stk.top()->val) return false;
		stk.pop();
		head = head->next;
	}
	return true;
}

bool LinkedList::isPalindromeListWithTwoPoints(ListNode *head) {
	if (head == nullptr) return false;
	if (head->next == nullptr) return true;
	// find middle position
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *mid = slow;
	// reverse
	fast = slow->next;
	ListNode *tail = LinkedList::reverse(slow->next);
	fast->next = mid;
	mid->next = nullptr;
	// traverse & compare
	bool flag = true;
	slow = head;
	fast = tail;
	while (slow != mid) {
		if (slow->val != fast->val) {
			flag = false;
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	// odd : the same node
	// even : the last middle node
	if (slow->val != fast->val) flag = false;
	// reverse back
	LinkedList::reverse(tail);

	return flag;
}


