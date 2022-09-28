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
		// row
		for (int j = 0; j < 9; j++) {
			if (board[row][j] == ch) return false;
		}
		// nine 
		int urow = 3 * (row / 3);
		int lrow = 3 * (row / 3 + 1);
		int lcol = 3 * (col / 3);
		int rcol = 3 * (col / 3 + 1);
		for (int i = urow; i < lrow; i++) {
			for (int j = lcol; j < rcol; j++) {
				if (board[i][j] == ch) return false;
			}
		}
		return true;
	}

	bool backtrack(vector<vector<char>>& board, int row, int col) {
		printBoard(board);
		if (row >= 9) {
			return true;
		}
		if (col >= 9) {
			if (backtrack(board, row + 1, 0)) return true;
			return false;
		}
		if (board[row][col] != '.') {
			if (backtrack(board, row, col + 1)) return true;
			return false;
		}
		for (int i = 1; i < 10; i++) {
			if (!isValid(board, row, col, i)) {
				continue;
			}
			board[row][col] = '0' + i;
			if (backtrack(board, row, col + 1)) return true;
			board[row][col] = '.';
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		vector<bool> alters(10, true);
		backtrack(board, 0, 0);
	}
};