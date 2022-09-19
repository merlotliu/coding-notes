#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

/* alt : 选择列表
 * selected : 已选择列表
 * i : 第几层
 * base case : i >= alt.size() 打印 selected
 */
void backtrack(std::string &alt, std::string &picked, int i, std::unordered_set<char> &memo) {
	// base case & end condition
	if (i >= alt.size()) {
		std::cout << picked << std::endl;
		return;
	}
	// for( one : alternative)
	for (auto ch : alt) {
		if(memo.find(ch) == memo.end()) {
			picked.push_back(ch); // picked
			memo.insert(ch);
			backtrack(alt, picked, i + 1, memo);
			memo.erase(ch);
			picked.pop_back(); // unpicked
		}
	}
}

void printAllPermutation(std::string &str) {
	std::string picked;
	std::unordered_set<char> memo;
	backtrack(str, picked, 0, memo);
}