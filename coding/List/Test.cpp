#include <iostream>

//#include "LinkedList.h"
#include "code01_reverse_list.hpp"
#include "code02_print_common_part.h"
#include "code03_palindrome_list.h"

void printLinkedList(ListNode *head) {
	while (head) {
		std::cout << head->val << (head->next ? "->" : " ");
		head = head->next;
	}
	std::cout << std::endl;
}

void reverseLinkedList() {
	int arr[] = { 4, 3, 2, 1 };
	int len = sizeof(arr) / sizeof(int);

	LinkedList list;
	ListNode *head = list.generateList(arr, len);
	printLinkedList(head);

	head = list.reverse(head);
	printLinkedList(head);

	head = list.reverseWithStack(head);
	printLinkedList(head);
}

void isPalindromeList() {

}

void printCommonPart() {
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 2, 3, 5, 6, 7 };
	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);

	LinkedList list;
	ListNode *head1 = list.generateList(arr1, len1);
	printLinkedList(head1);
	ListNode *head2 = list.generateList(arr2, len2);
	printLinkedList(head2);

	std::cout << "Common Part : " << std::endl;
	list.printCommonPart(head1, head2);
}

int main(int argc, char *argv[]) {
	// reverse linked list
	//reverseLinkedList();
	
	// print common part
	printCommonPart();

	// Palindrome List
	isPalindromeList();

	return 0;
}