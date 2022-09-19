#pragma once
#include <vector>

bool isValid(int row, int col, std::vector<std::vector<bool>> &board){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] && (j == col || (abs(row - i) == abs(col - j)))) {
				return false;
			}
		}
	}
	return true;
}

int backtrack(int level, int n, std::vector<std::vector<bool>> &board) {
	if (level >= n) {
		return 1;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (isValid(level, i, board)) {
			board[level][i] = 1;
			res += backtrack(level + 1, n, board);
			board[level][i] = 0;
		}
	}
	return res;
}

int totalNQueens(int n) {
	std::vector<std::vector<bool>> board(n, std::vector<bool>(n, 0));
	return backtrack(0, n, board);
}

bool isValid(int row, int col, std::vector<std::string> &board) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == 'Q' && (j == col || (abs(row - i) == abs(col - j)))) {
				return false;
			}
		}
	}
	return true;
}

void backtrack(int level, int n, std::vector<std::string> &board, std::vector<std::vector<std::string>> &res) {
	if (level >= n) {
		res.push_back(board);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isValid(level, i, board)) {
			board[level][i] = 'Q';
			backtrack(level + 1, n, board, res);
			board[level][i] = '.';
		}
	}
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
	std::vector<std::string> board(n, std::string(n, '.'));
	std::vector<std::vector<std::string>> res;
	backtrack(0, n, board, res);
	return res;
}


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
		// ��һ��λ����б�ߵ����ƾ��ǵ�ǰ��б�����ƻ��ϵ�ǰѡ���λ��������һλ
		// ��һ��λ����б�ߵ����ƾ��ǵ�ǰ��б�����ƻ��ϵ�ǰѡ���λ��������һλ
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