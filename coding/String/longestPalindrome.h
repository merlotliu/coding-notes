#pragma once
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int max(int a, int b) {
//		return a > b ? a : b;
//	}
//	/* ��������ַ� # : abc-> #a#b#c# */
//	string manachterString(string s) {
//		string mstr(s.size() * 2 + 1, 0);
//		for (int i = 0; i < s.size() * 2 + 1; i++) {
//			mstr[i] = i % 2 == 0 ? '#' : s[i / 2];
//		}
//		return mstr;
//	}
//	/* ��ȡstr ��posλ��Ϊ���ĵĻ��Ĵ��İ뾶���� r λ�ÿ�ʼ�ж�, ǰ��ĳ���r - pos��Ϊ�ǻ���  */
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
//		int R = -1; /* ���һ����ұ߽� */
//		int C = -1; /* ���һ������ĵ� */
//		vector<int> radius(str.size(), 1); /* ���İ뾶���� */
//		int max_idx = 0;
//		for (int i = 0; i < str.size(); i++) {
//			if (i > R) { /* ��ǰ���� i �� R ֮��, ������չ */
//				radius[i] = getPalindromeRadius(str, i, i + 1);
//				R = i + radius[i] - 1;
//				C = i;
//			}
//			else {
//				/* i ���� C �ĶԳƵ�������������һ�����߽��Ҳ� : i�Ļ��İ뾶���ڶԳƵ�뾶 */
//				if (radius[2 * C - i] < (R - i + 1)) {
//					radius[i] = radius[2 * C - i];
//					/* i ���� C �ĶԳƵ���������в��������һ������� : i�Ļ��İ뾶����i���ұ߽� */
//				}
//				else if (radius[2 * C - i] > (R - i + 1)) {
//					radius[i] = R - i + 1;
//					/* i ���� C �ĶԳƵ����������߽��� C ����߽��غϣ���Ҫ���������ж� i �߽� */
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
	/* ��������ַ� # : abc-> #a#b#c# */
	string manachterString(string s) {
		string mstr(s.size() * 2 + 1, 0);
		for (int i = 0; i < s.size() * 2 + 1; i++) {
			mstr[i] = i % 2 == 0 ? '#' : s[i / 2];
		}
		return mstr;
	}
	/* ��ȡstr ��posλ��Ϊ���ĵĻ��Ĵ��İ뾶���� r λ�ÿ�ʼ�ж�, ǰ��ĳ���r - pos��Ϊ�ǻ���  */
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
		int R = -1; /* ���һ����ұ߽����һ��λ�� */
		int C = -1; /* ���һ������ĵ� */
		vector<int> radius(str.size(), 1); /* ���İ뾶���� */
		int max_idx = 0;
		for (int i = 0; i < str.size(); i++) {
			radius[i] = i >= R ? 1 : min(radius[2 * C - i], R - i);
			/* �� i + radius[i] ��λ�ÿ�ʼ��չ */
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