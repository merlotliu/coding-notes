#include "code01_hanoi_tower.hpp"
#include "code02_all_subsequence_of_string.hpp"
#include "code03_all_permutation.hpp"
#include "code04_reverse_statck_with_recursion.hpp"
#include "code05_number_convert_to_letter.hpp"
#include "code06_01_bag.hpp"
#include "code08_n_queens.hpp"

#include <iostream>

void hanoiTower() {
	hanoi();
}

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

void numConvertToLetter() {
	std::string num = "112312121223343556";
	std::cout << numConvertToLetter(num) << std::endl;
	std::cout << letterRecur(num, 0) << std::endl;
}

void bag01() {
	std::vector<int> weights = {2, 4, 5, 8, 10};
	std::vector<int> values = {4, 3, 1, 4, 3};
	int bag = 20;
	std::cout << getMaxVal(weights, values, bag) << std::endl;
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
	// 1 hanoi tower
	//hanoiTower();

	// 2 print all subsequence of string
	//allSubsequence();
	
	// 3 print all permutation
	//allPermutation();
	
	// 4 reverse stack with recursion
	//reverseStackWithRecursion();

	// 5 number convert to letter
	numConvertToLetter();

	// 6 01bag
	//bag01();

	// n queens
	//NQueens();

	return 0;
}