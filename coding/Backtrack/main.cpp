#include "code02_all_subsequence_of_string.hpp"
#include "code03_all_permutation.hpp"
#include "code04_reverse_statck_with_recursion.h"
#include "code08_n_queens.hpp"

#include <iostream>

void allPermutation() {
	std::string str = "abc";
	printAllPermutation(str);
}

void allSubsequence() {
	std::string str = "abc";
	printAllSubsequence(str);
}

void reverseStackWithRecursion() {
	std::stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	printStack(stk);
	reverseStack(stk);
	printStack(stk);
}

void NQueens() {
	int n = 4;
	std::cout << totalNQueensBit(n) << std::endl;
	std::cout << totalNQueens(n) << std::endl;
	std::vector<std::vector<std::string>> res = solveNQueens(n);
	for (auto board : res) {
		std::cout << std::endl;
		for (auto str : board) {
			for (auto ch : str) {
				std::cout << ch << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	// 2 print all subsequence of string
	//allSubsequence();
	
	// 3 print all permutation
	//allPermutation();
	
	// 4 reverse stack with recursion
	reverseStackWithRecursion();

	// n queens
	//NQueens();

	return 0;
}