#pragma once
#include <vector>
#include <iostream>
#include <unordered_set>

class ListRandomNode;

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
	ListRandomNode* copyListWithRandomByMap(ListRandomNode *head);
	ListRandomNode* copyListWithRandom(ListRandomNode *head);
	// find first intersection between two lists
	
	ListNode* findFirstIntersection(ListNode *head1, ListNode *head2);

	ListNode* hasCycleBySet(ListNode *head);
	ListNode* hasCycle(ListNode *head);

	ListNode* findFirstIntersectionWithNoLoop(ListNode *head1, ListNode *head2);
	ListNode* findFirstIntersectionWithNoLoopEx(ListNode *head1, ListNode *head2);
	ListNode* findFirstIntersectionWithLoops(ListNode *head1, ListNode *loop1, ListNode *head2, ListNode *loop2);
public:
	ListNode* generateList(int *arr, int len);
	ListNode* generateList(std::vector<int> &arr);
	ListRandomNode* generateListWithRandom(int *arr, int len);

	void printListWithRandom(ListRandomNode *head);

	void swap(ListNode *a, ListNode *b);

public:
	LinkedList();
	LinkedList(int *arr, int len);

private:
	ListNode *_head;
};

