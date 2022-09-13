#include <time.h>
#include <iostream>

#include "LinkedList.h"
#include "code01_reverse_list.hpp"
#include "code02_print_common_part.hpp"
#include "code03_palindrome_list.hpp"
#include "code04_pivot_list.hpp"
#include "code05_copy_list_with_random.hpp"
#include "code06_find_first_intersection.hpp"

void printList(ListNode *head) {
	std::unordered_set<ListNode*> set;
	while (head) {
		if (set.find(head) != set.end()) break;
		set.insert(head);
		std::cout << head->val << (head->next ? "->" : " ");
		head = head->next;
	}
	std::cout << std::endl;
}

void reverseList() {
	std::cout << "Reverse List" << std::endl;
	int arr[] = { 4, 3, 2, 1 };
	int len = sizeof(arr) / sizeof(int);

	LinkedList list;
	ListNode *head = list.generateList(arr, len);

	std::cout << "Reverse : ";
	printList(head);
	head = list.reverse(head);
	std::cout << "Result : ";
	printList(head);

	std::cout << "Reverse : ";
	printList(head);
	head = list.reverseWithStack(head);
	std::cout << "Result : ";
	printList(head);
	std::cout << std::endl;
}

void printCommonPart() {
	std::cout << "Print Common Part" << std::endl;
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 2, 3, 5, 6, 7 };
	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);

	LinkedList list;
	ListNode *head1 = list.generateList(arr1, len1);
	printList(head1);
	ListNode *head2 = list.generateList(arr2, len2);
	printList(head2);

	std::cout << "Common Part : " << std::endl;
	list.printCommonPart(head1, head2);
	std::cout << std::endl;
}

void isPalindromeList() {
	std::cout << "Palindrome List" << std::endl;
	int arr1[] = { 1, 2, 3, 3, 2, 1 };
	int arr2[] = { 2, 3, 5, 6, 7 };
	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);

	LinkedList list;
	ListNode *head1 = list.generateList(arr1, len1);
	ListNode *head2 = list.generateList(arr2, len2);

	printList(head1);
	std::cout << "Palindrome List (Stack) : " << (list.isPalindromeListWithStack(head1) ? "True" : "False") << std::endl; 
	std::cout << "Palindrome List (Stack & 2 Points) : " << (list.isPalindromeListWithStackAndTwoPoints(head1) ? "True" : "False") << std::endl;
	std::cout << "Palindrome List (2 Points) : " << (list.isPalindromeListWithTwoPoints(head1) ? "True" : "False") << std::endl;
	//printList(head1);

	printList(head2);
	std::cout << "Palindrome List (Stack) : " << (list.isPalindromeListWithStack(head2) ? "True" : "False") << std::endl;
	std::cout << "Palindrome List (Stack & 2 Points) : " << (list.isPalindromeListWithStackAndTwoPoints(head2) ? "True" : "False") << std::endl;
	std::cout << "Palindrome List (2 Points) : " << (list.isPalindromeListWithTwoPoints(head2) ? "True" : "False") << std::endl;
	//printList(head2);
	
	std::cout << std::endl;
}

void pivotList() {
	std::cout << "Pivot List" << std::endl;
	int arr[] = {2, 9, 6, 2, 3, 1, 1, 4, 5, 5, 6, 8};
	int len = sizeof(arr) / sizeof(int);
	int pivot = arr[rand() % len];

	LinkedList list;

	std::cout << "List Partition With Pivot And Array <" << pivot << "> :" << std::endl;
	ListNode *head = list.generateList(arr, len);
	printList(head);
	head = list.partitionWithPivotAndArray(head, pivot);
	printList(head);

	std::cout << "List Partition With Pivot By Several Points <" << pivot << "> :" << std::endl;
	head = list.generateList(arr, len);
	printList(head);
	head = list.partitionWithPivot(head, pivot);
	printList(head);

	std::cout << std::endl;
}

void copyListWithRandom() {
	std::cout << "Copy List With Random" << std::endl;
	int arr[] = { 4, 3, 2, 1 };
	int len = sizeof(arr) / sizeof(int);

	LinkedList list;
	std::cout << "Copy List With Random By Map" << std::endl;
	ListRandomNode *head = list.generateListWithRandom(arr, len);
	std::cout << "Origin : ";
	list.printListWithRandom(head);
	list.copyListWithRandomByMap(head);
	std::cout << "Copy : ";
	list.printListWithRandom(head);

	std::cout << "Copy List With Random By Next" << std::endl;
	head = list.generateListWithRandom(arr, len);
	std::cout << "Origin : ";
	list.printListWithRandom(head);
	list.copyListWithRandom(head);
	std::cout << "Copy : ";
	list.printListWithRandom(head);

	std::cout << std::endl;
}

void hasCycle() {
	std::cout << "List With Cycle" << std::endl;
	int arr[] = { 1, 2, 3, 4, 5, 6};
	int len = sizeof(arr) / sizeof(int);

	LinkedList list;
	ListNode *head = list.generateList(arr,len);
	ListNode *node = list.hasCycleBySet(head);
	std::cout << "Has Cycle By Set : " << (node ? "True" : "False" ) << std::endl;
	node = list.hasCycle(head);
	std::cout << "Has Cycle By 2 Pointers: " << (node ? "True" : "False") << std::endl;

	ListNode *cur = head;
	ListNode *tmp = nullptr;
	while (cur->next) {
		if (cur->val == 3) tmp = cur;
		cur = cur->next;
	}
	cur->next = tmp;
	node = list.hasCycleBySet(head);
	std::cout << "Has Cycle By Set : " << (node ? "True" : "False" ) << std::endl;
	node = list.hasCycle(head);
	std::cout << "Has Cycle By 2 Pointers: " << (node ? "True" : "False") << std::endl;

	std::cout << std::endl;
}

void findFirstIntersection() {
	ListNode *tail1 = new ListNode(5, nullptr);
	ListNode *p1 = new ListNode(4, tail1);
	p1 = new ListNode(3, p1);
	p1 = new ListNode(2, p1);
	ListNode *head1 = new ListNode(1, p1);
	tail1->next = head1->next->next;

	p1 = new ListNode(6, head1->next);
	ListNode *head2 = new ListNode(7, p1);

	printList(head1);
	printList(head2);

	LinkedList list;
	ListNode *node = list.findFirstIntersection(head1, head2);

	std::cout << node->val << std::endl;
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	srand((unsigned int)time(nullptr));

	// reverse linked list
	//reverseList();
	
	// print common part
	//printCommonPart();

	// Palindrome List
	//isPalindromeList();

	// list partition with pivot 
	//pivotList();

	// copy list with random pointers
	//copyListWithRandom();

	// has or not cycle
	// hasCycle();

	// find first intersection
	findFirstIntersection();

	return 0;
}