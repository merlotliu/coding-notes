#pragma once
#include <string>
#include <iostream>

// str 全部字符集合
// i 当前在哪一层
void backtrack(std::string &str, int i, std::string memo) {
	if (i >= str.size()) {
		std::cout << memo << " ";
		return;
	}
	// 不要
	backtrack(str, i + 1, memo);
	
	// 要
	memo.push_back(str[i]);
	backtrack(str, i + 1, memo);
}

void printAllSubsequence(std::string &str) {
	backtrack(str, 0, "");
	std::cout << std::endl;
}

