#include <time.h>
#include <iostream>

#include "LinkedList.h"
#include "code01_reverse_list.hpp"
#include "code02_print_common_part.hpp"
#include "code03_palindrome_list.hpp"
#include "code04_pivot_list.hpp"

void printList(ListNode *head) {
	while (head) {
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
	ListNode *head = list.generateList(arr, len);
	printList(head);

	head = list.partitionWithPivotAndArray(head, pivot);
	std::cout << "List Partition With Pivot And Array <" << pivot << "> :" << std::endl;
	printList(head);

	head = list.partitionWithPivot(head, pivot);
	std::cout << "List Partition With Pivot By Several Points <" << pivot << "> :" << std::endl;
	printList(head);
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
	pivotList();

	return 0;
}