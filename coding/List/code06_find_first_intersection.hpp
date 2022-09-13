#pragma once
#include "LinkedList.h"

ListNode* LinkedList::findFirstIntersection(ListNode *head1, ListNode *head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return nullptr;
	}
	// has cycle
	ListNode *loop1 = hasCycle(head1);
	ListNode *loop2 = hasCycle(head2);
	// 
	if (loop1 == nullptr && loop2 == nullptr) return findFirstIntersectionWithNoLoop(head1, head2);
	if (loop1 != nullptr && loop2 != nullptr) return findFirstIntersectionWithLoops(head1, loop1, head2, loop2);
	return nullptr;
}

ListNode* LinkedList::findFirstIntersectionWithNoLoop(ListNode *head1, ListNode *head2) {
	ListNode *cur1 = head1;
	ListNode *cur2 = head2;
	int diff = 0;
	while (cur1) {
		cur1 = cur1->next;
		diff++;
	}
	while (cur2) {
		cur2 = cur2->next;
		diff--;
	}
	cur1 = diff > 0 ? head1 : head2; // cur1 -> the longer list
	cur2 = cur1 == head2 ? head1 : head2;
	diff = diff < 0 ? -diff : diff; // abs
	// cur1 move diff steps first
	while (diff--) cur1 = cur1->next;
	
	while (cur1 != cur2) {
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

ListNode* LinkedList::findFirstIntersectionWithNoLoopEx(ListNode *head1, ListNode *head2) {
	ListNode *cur1 = head1;
	ListNode *cur2 = head2;
	while (cur1 != cur2) {
		cur1 = cur1->next;
		cur2 = cur2->next;
		if (cur1 == nullptr && cur2 == nullptr) return nullptr;
		if (cur1 == nullptr) cur1 = head2;
		if (cur2 == nullptr) cur2 = head1;
	}
	return cur1;
}

ListNode* LinkedList::findFirstIntersectionWithLoops(ListNode *head1, ListNode *loop1, ListNode *head2, ListNode *loop2) {
	if (loop1 == loop2) {
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		while (cur1 != cur2) {
			cur1 = cur1->next == loop1->next ? head2 : cur1->next;
			cur2 = cur2->next == loop1->next ? head1 : cur2->next;
		}
		return cur1;
	} else {
		ListNode *cur = loop1->next;
		while (cur != loop1) {
			cur = cur->next;
			if (cur == loop2) return cur;
		}
		return nullptr;
	}
}

ListNode* LinkedList::hasCycleBySet(ListNode *head) {
	if (head == nullptr || head->next == nullptr) return nullptr;
	std::unordered_set<ListNode*> set;
	ListNode *cur = head;
	while (cur) {
		if (set.find(cur) != set.end()) {
			return cur;
		}
		set.insert(cur);
		cur = cur->next;
	}
	return nullptr;
}

ListNode* LinkedList::hasCycle(ListNode *head) {
	if (head == nullptr || head->next == nullptr) return nullptr;
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	if (fast == nullptr || fast->next == nullptr) return nullptr;
	
	fast = head;
	while (fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}