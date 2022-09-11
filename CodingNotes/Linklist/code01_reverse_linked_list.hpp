#pragma once
#include "LinkedList.h"

#include <stack>

// reverse single linked list
// 4->3->2->1
LinkedNode* LinkedList::reverseWithStack(LinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	std::stack<LinkedNode*> stk;
	LinkedNode* cur = head;
	while (cur) {
		stk.push(cur);
		cur = cur->next;
	}
	LinkedNode* tmp = new LinkedNode();
	cur = tmp;
	while (!stk.empty()) {
		cur->next = stk.top();
		stk.pop();
		cur = cur->next;
	}
	cur->next = nullptr;
	cur = tmp->next;
	delete tmp;
	return cur;
}

LinkedNode* LinkedList::reverse(LinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	LinkedNode *new_head = head;
	LinkedNode *cur = head->next;
	while (cur) {
		head->next = cur->next;
		cur->next = new_head;
		new_head = cur;
		cur = head->next;
	}
	return new_head;
}

// reverse double linked list
// 4<=>3<=>2<=>1
DoubleLinkedNode* LinkedList::reverseDoubleLinkedList(DoubleLinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	DoubleLinkedNode *pre = head;
	DoubleLinkedNode *cur = head->next;
	while (cur) {
		DoubleLinkedNode *tmp = pre->next;
		pre->next = pre->pre;
		pre->pre = tmp;
		
		pre = cur;
		cur = cur->next;
	}
	return pre;
} 

