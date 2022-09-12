#pragma once
#include "LinkedList.h"

#include <unordered_map>

class ListRandomNode : public ListNode {
public:
	ListRandomNode() : val(0), next(nullptr), random(nullptr) {}
	ListRandomNode(int v, ListRandomNode *n, ListRandomNode *r) : val(v), next(n), random(r) {}
public:
	int val;
	ListRandomNode *next;
	ListRandomNode *random;
};

ListRandomNode* LinkedList::copyListWithRandomByMap(ListRandomNode *head) {
	if (head == nullptr ) return head;
	std::unordered_map<ListRandomNode*, ListRandomNode*> ref;
	// create new node
	ListRandomNode *cur = head;
	while (cur != nullptr) {
		ListRandomNode *tmp = new ListRandomNode(cur->val, nullptr, nullptr);
		ref[cur] = tmp;
		cur = cur->next;
	}
	// joint new node
	cur = head;
	while (cur != nullptr) {
		ref[cur]->next = ref[cur->next];
		ref[cur]->random = ref[cur->random];
		cur = cur->next;
	}
	return ref[head];
}

ListRandomNode* LinkedList::copyListWithRandom(ListRandomNode *head) {
	if (head == nullptr) return head;
	// create new node
	ListRandomNode *cur = head;
	while (cur != nullptr) {
		ListRandomNode *cur_ = new ListRandomNode(cur->val, nullptr, nullptr);
		ListRandomNode *tmp = cur->next;
		cur->next = cur_;
		cur_->next = tmp;
		cur = tmp;
	}
	// assign random pointers
	cur = head;
	while (cur != nullptr) {
		cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	// split
	cur = head;
	ListRandomNode *new_head = head->next;
	ListRandomNode *cur_ = head->next;
	while (cur_->next != nullptr) {
		cur->next = cur_->next;
		cur = cur->next;
		cur_->next = cur->next;
		cur_ = cur_->next;
	}
	cur->next = nullptr;
	cur_->next = nullptr;
	return new_head;
}

ListRandomNode* LinkedList::generateListWithRandom(int *arr, int len) {
	if (arr == nullptr || len < 1) {
		return nullptr;
	}
	std::vector<ListRandomNode*> vec;
	ListRandomNode *head = new ListRandomNode(arr[0], nullptr, nullptr);
	ListRandomNode *cur = head;
	for (int i = 1; i < len; i++) {
		vec.push_back(cur);
		cur->next = new ListRandomNode(arr[i], nullptr, nullptr);
		cur = cur->next;
	}
	vec.push_back(cur);
	for (int i = 0; i < len; i++) {
		vec[i]->random = vec[rand() % len];
	}
	return head;
}

void LinkedList::printListWithRandom(ListRandomNode *head) {
	while (head) {
		std::cout << head->val << "[" << head->random->val << "]" << (head->next ? "->" : " ") ;
		head = head->next;
	}
	std::cout << std::endl;
}