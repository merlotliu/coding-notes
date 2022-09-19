#pragma once
#include <string>
#include <iostream>

// str ȫ���ַ�����
// i ��ǰ����һ��
void backtrack(std::string &str, int i, std::string memo) {
	if (i >= str.size()) {
		std::cout << memo << " ";
		return;
	}
	// ��Ҫ
	backtrack(str, i + 1, memo);
	
	// Ҫ
	memo.push_back(str[i]);
	backtrack(str, i + 1, memo);
}

void printAllSubsequence(std::string &str) {
	backtrack(str, 0, "");
	std::cout << std::endl;
}

