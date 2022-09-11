#pragma once

// single linked list
class ListNode {
public:
	ListNode() : val(0), next(nullptr) {}
	ListNode(int v, ListNode *n) : val(v), next(n) {}
public:
	int val;
	ListNode *next;
};

// double linked list
class DoubleLinkedNode : public ListNode {
public:
	DoubleLinkedNode() : val(0), pre(nullptr), next(nullptr) {}
	DoubleLinkedNode(int v, DoubleLinkedNode *p, DoubleLinkedNode *n) : val(v), pre(p), next(n) {}
public:
	int val;
	DoubleLinkedNode *pre;
	DoubleLinkedNode *next;
};

class LinkedList {
public:
	//
	ListNode* reverseWithStack(ListNode *head);
	ListNode* reverse(ListNode *head);
	//
	DoubleLinkedNode* reverseDoubleLinkedList(DoubleLinkedNode *head);
	//
	void printCommonPart(ListNode *head1, ListNode *head2);

	bool isPalindromeListWithStack(ListNode *head);

public:
	ListNode* generateList(int *arr, int len);

public:
	LinkedList();
	LinkedList(int *arr, int len);

private:
	ListNode *_head;
};

