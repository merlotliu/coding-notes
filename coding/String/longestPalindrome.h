#pragma once
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int max(int a, int b) {
//		return a > b ? a : b;
//	}
//	/* 添加特殊字符 # : abc-> #a#b#c# */
//	string manachterString(string s) {
//		string mstr(s.size() * 2 + 1, 0);
//		for (int i = 0; i < s.size() * 2 + 1; i++) {
//			mstr[i] = i % 2 == 0 ? '#' : s[i / 2];
//		}
//		return mstr;
//	}
//	/* 获取str 中pos位置为中心的回文串的半径，从 r 位置开始判断, 前面的长度r - pos认为是回文  */
//	int getPalindromeRadius(string str, int pos, int r) {
//		int l = 2 * pos - r;
//		int radius = r - pos;
//		while (l >= 0 && r < str.size() && str[l--] == str[r++]) radius++;
//		return radius;
//	}
//
//	string longestPalindrome(string s) {
//		if (s.size() <= 1) {
//			return s;
//		}
//		string str = manachterString(s);
//		int R = -1; /* 最右回文右边界 */
//		int C = -1; /* 最右回文中心点 */
//		vector<int> radius(str.size(), 1); /* 回文半径数组 */
//		int max_idx = 0;
//		for (int i = 0; i < str.size(); i++) {
//			if (i > R) { /* 当前索引 i 在 R 之外, 暴力扩展 */
//				radius[i] = getPalindromeRadius(str, i, i + 1);
//				R = i + radius[i] - 1;
//				C = i;
//			}
//			else {
//				/* i 关于 C 的对称点回文区域在最右回文左边界右侧 : i的回文半径等于对称点半径 */
//				if (radius[2 * C - i] < (R - i + 1)) {
//					radius[i] = radius[2 * C - i];
//					/* i 关于 C 的对称点回文区域有部分在最右回文外面 : i的回文半径等于i到右边界 */
//				}
//				else if (radius[2 * C - i] > (R - i + 1)) {
//					radius[i] = R - i + 1;
//					/* i 关于 C 的对称点回文区域左边界与 C 的左边界重合，需要暴力扩充判断 i 边界 */
//				}
//				else {
//					radius[i] = getPalindromeRadius(str, i, R + 1);
//					R = i + radius[i] - 1;
//					C = i;
//				}
//			}
//			//printf("%d %d\n", i, radius[i]);
//			if (radius[i] > radius[max_idx]) {
//				max_idx = i;
//			}
//		}
//		return s.substr((max_idx - radius[max_idx] + 1) / 2, radius[max_idx] - 1);
//	}
//};

class Solution {
public:
	int min(int a, int b) {
		return a < b ? a : b;
	}
	/* 添加特殊字符 # : abc-> #a#b#c# */
	string manachterString(string s) {
		string mstr(s.size() * 2 + 1, 0);
		for (int i = 0; i < s.size() * 2 + 1; i++) {
			mstr[i] = i % 2 == 0 ? '#' : s[i / 2];
		}
		return mstr;
	}
	/* 获取str 中pos位置为中心的回文串的半径，从 r 位置开始判断, 前面的长度r - pos认为是回文  */
	int getPalindromeRadius(string str, int pos, int r) {
		int l = 2 * pos - r;
		int radius = r - pos;
		while (l >= 0 && r < str.size() && str[l--] == str[r++]) radius++;
		return radius;
	}

	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}
		string str = manachterString(s);
		int R = -1; /* 最右回文右边界的下一个位置 */
		int C = -1; /* 最右回文中心点 */
		vector<int> radius(str.size(), 1); /* 回文半径数组 */
		int max_idx = 0;
		for (int i = 0; i < str.size(); i++) {
			radius[i] = i >= R ? 1 : min(radius[2 * C - i], R - i);
			/* 从 i + radius[i] 的位置开始扩展 */
			int l = i - radius[i];
			int r = i + radius[i];
			while (l > -1 && r < str.size() && str[l--] == str[r++]) {
				radius[i]++;
			}
			if (i + radius[i] > R) {
				R = i + radius[i];
				C = i;
			}
			printf("%d %d\n", i, radius[i]);
			if (radius[i] > radius[max_idx]) {
				max_idx = i;
			}
		}
		return s.substr((max_idx - radius[max_idx] + 1) / 2, radius[max_idx] - 1);
	}
};