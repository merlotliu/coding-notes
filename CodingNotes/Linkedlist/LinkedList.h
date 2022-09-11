#pragma once

// single linked list
class LinkedNode {
public:
	LinkedNode() : val(0), next(nullptr) {}
	LinkedNode(int v, LinkedNode *n) : val(v), next(n) {}
public:
	int val;
	LinkedNode *next;
};

// double linked list
class DoubleLinkedNode : public LinkedNode {
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
	LinkedNode* reverseWithStack(LinkedNode *head);
	LinkedNode* reverse(LinkedNode *head);
	//
	DoubleLinkedNode* reverseDoubleLinkedList(DoubleLinkedNode *head);
	//
	void printCommomPart(LinkedNode *head1, LinkedNode *head2);

public:
	LinkedNode* generateList(int *arr, int len);

public:
	LinkedList();
	LinkedList(int *arr, int len);

private:
	LinkedNode *_head;
};

