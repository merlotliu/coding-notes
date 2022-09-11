#include <iostream>

//#include "LinkedList.h"
#include "code01_reverse_linked_list.hpp"
#include "code02_print_common_part.hpp"

void printLinkedList(LinkedNode *head) {
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
	LinkedNode *head = list.generateList(arr, len);
	printLinkedList(head);

	head = list.reverse(head);
	printLinkedList(head);

	head = list.reverseWithStack(head);
	printLinkedList(head);
}

void printCommonPart() {

}

int main(int argc, char *argv[]) {
	// reverse linked list
	reverseLinkedList();
	
	// print common part


	return 0;
}