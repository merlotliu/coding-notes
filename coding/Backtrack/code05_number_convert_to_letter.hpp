#pragma once
#include <string>

int res = 0;
void backtrack(std::string &num, int i) {
	if ('0' == num[i]) {
		return;
	}
	if (i == num.size()) {
		res++;
	}
	if ('1' == num[i]) {
		backtrack(num, i + 1);
		backtrack(num, i + 2);
	}
	if ('2' == num[i]) {
		backtrack(num, i + 1);
		if (i + 1 != num.size() && num[i + 1] >= '0' && num[i + 1] <= '6') {
			backtrack(num, i + 2);
		}
	}
	if (num[i] >= '3' && num[i] <= '9') {
		backtrack(num, i + 1);
	}
}

int letterRecur(std::string &num, int i) {
	if ('0' == num[i]) return 0;
	if (i == num.size()) return 1;
	if ('1' == num[i]) {
		int res = letterRecur(num, i + 1);
		return res + letterRecur(num, i + 2);
	}
	if ('2' == num[i]) {
		int res = 0;
		if (i + 1 != num.size() && num[i + 1] >= '0' && num[i + 1] <= '6') {
			res += letterRecur(num, i + 2);
		}
		return res + letterRecur(num, i + 1);
	}
	if (num[i] >= '3' && num[i] <= '9') {
		return letterRecur(num, i + 1);
	}
}

int numConvertToLetter(std::string &num) {
	backtrack(num, 0);
	return res;
}