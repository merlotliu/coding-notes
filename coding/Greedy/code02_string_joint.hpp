#pragma once
#include <vector>
#include <string>
#include <algorithm>

std::string getMinJointString(std::vector<std::string> &strs) {
	auto cmp = [](std::string &a, std::string &b) {
		std::string str1 = a + b;
		std::string str2 = b + a;
		return str1.compare(str2);
	};
	std::sort(strs.begin(), strs.end(), cmp);
	std::string res;
	for (auto str : strs) {
		res += str;
	}
	return res;
}