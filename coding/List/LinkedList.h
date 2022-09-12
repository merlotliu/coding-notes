#pragma once
#include <vector>

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
	// reverse list
	ListNode* reverseWithStack(ListNode *head);
	ListNode* reverse(ListNode *head);
	DoubleLinkedNode* reverseDoubleLinkedList(DoubleLinkedNode *head);
	// print commom part
	int printCommonPart(ListNode *head1, ListNode *head2);
	// palindrome list
	bool isPalindromeListWithStack(ListNode *head);
	bool isPalindromeListWithStackAndTwoPoints(ListNode *head);
	bool isPalindromeListWithTwoPoints(ListNode *head);
	// list partition with pivot
	ListNode* partitionWithPivotAndArray(ListNode *head, int pivot);
	ListNode* partitionWithPivot(ListNode *head, int pivot);
	// copy list with random
	ListNode* copyListWithRandom(ListNode *head);
	// find first intersection between two lists
	ListNode* findFirstIntersection(ListNode *head1, ListNode *head2);
public:
	ListNode* generateList(int *arr, int len);
	ListNode* generateList(std::vector<int> &arr);
	
	void swap(ListNode *a, ListNode *b);

public:
	LinkedList();
	LinkedList(int *arr, int len);

private:
	ListNode *_head;
};

