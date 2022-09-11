#include "LinkedList.h"

LinkedNode* LinkedList::generateList(int *arr, int len) {
	if (arr == nullptr || len < 1) {
		return nullptr;
	}
	LinkedNode *head = new LinkedNode(arr[0], nullptr);
	LinkedNode *cur = head;
	for (int i = 1; i < len; i++) {
		cur->next = new LinkedNode(arr[i], nullptr);
		cur = cur->next;
	}
	return head;
}

LinkedList::LinkedList() {

}

LinkedList::LinkedList(int *arr, int len) {
	_head = generateList(arr, len);
}