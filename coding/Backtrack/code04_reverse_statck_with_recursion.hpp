#pragma once
#include <stack>
#include <iostream>

/* 
 * base case : stack is empty
 * 先出栈元素，如果为null，返回一直该栈底元素，不为空继续递归出栈
 */
int getStackBottom(std::stack<int> &stk) {
	int cur = stk.top();
	stk.pop();
	if (stk.empty()) {
		return cur;
	}
	int bottom = getStackBottom(stk);
	stk.push(cur);
	return bottom; 
}

/*
 * base case : stack is empty
 */
void backtrack(std::stack<int> &stk) {
	if (stk.empty()) {
		return;
	}
	int num = getStackBottom(stk);
	backtrack(stk);
	stk.push(num);
}

void reverseStack(std::stack<int> &stk) {
	backtrack(stk);
}

void printStack(std::stack<int> stk) {
	while (!stk.empty()) {
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;
}