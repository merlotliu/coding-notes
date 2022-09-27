#pragma once
#include <vector>
#include <iostream>
using namespace std;
 
class Solution {
public:
	void printBoard(vector<vector<char>>& board) {
		for (auto row : board) {
			for (auto ch : row) {
				std::cout << ch << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	bool isValid(vector<vector<char>>& board, int row, int col, int num) {
		// col
		char ch = '0' + num;
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == ch) return false;
		}
		// nine 
		int urow = 3 * (row / 3);
		int lrow = 3 * (row / 3 + 1);
		int lcol = 3 * (col / 3);
		int rcol = 3 * (col / 3 + 1);
		for (int i = row + 1; i <= lrow; i++) {
			for (int j = lcol; j <= rcol; j++) {
				if (board[i][col] == ch) return false;
			}
		}
		return true;
	}

	bool backtrack(vector<vector<char>>& board, vector<bool> alters, int row, int col) {
		printBoard(board);
		if (row >= 9) {
			return true;
		}
		if (col >= 9) {
			row += 1;
			alters.assign(10, true);
		}
		while (board[row][col] != '.') {
			alters[board[row][col++] - '0'] = false;
		}
		for (int i = 1; i < 10; i++) {
			if (alters[i] == false) {
				continue;
			}
			if (!isValid(board, row, col, alters[i])) {
				alters[alters[i]] = false;
				continue;
			}
			alters[i] = false;
			board[row][col++] = '0' + i;
			if (backtrack(board, alters, row, col)) return true;
			board[row][--col] = '.';
			alters[i] = true;
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		vector<bool> alters(10, true);
		backtrack(board, alters, 0, 0);
	}
};