#include "code01_n_queens.hpp"
#include <iostream>

int backtrack(int col_lim, int left_dia_lim, int right_dia_lim, int limit_range) {
	if (col_lim == limit_range) {
		return 1;
	}
	int res = 0;
	// calculate current all of possible position
	int pos = limit_range & (~(col_lim | left_dia_lim | right_dia_lim));
	while (pos != 0) {
		int most_right_one = pos & (~pos + 1); // get most right one
		pos -= most_right_one; // mark to limit
		// 下一个位置左斜线的限制就是当前左斜线限制或上当前选择的位置再左移一位
		// 下一个位置右斜线的限制就是当前右斜线限制或上当前选择的位置再右移一位
		res += backtrack(col_lim | most_right_one,
			(left_dia_lim | most_right_one) << 1,
			(right_dia_lim | most_right_one) >> 1,
			limit_range);
	}
	return res;
}

int totalNQueensBit(int n) {
	return backtrack(0, 0, 0, (1 << n) - 1);
}

int main(int argc, char *argv[]) {
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
	return 0;
}