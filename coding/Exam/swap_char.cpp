#include <string>

using namespace std;

bool isTangle(string s1, string s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	int left = -1;
	int right = -1;
	int idx = 0;
	for (; idx < s1.size(); idx++) {
		if (s1[idx] != s2[idx]) {
			if (left == -1) {
				left = idx;
			} else if (right == -1) {
				right = idx;
			} else {
				return false;
			}
		}
	}
	if (left == -1 && right == -1) {
		return true;
	}
	if (left != -1 && right == -1) {
		return false;
	}
	return  (s1[left] == s2[right] && s1[right] == s2[left]);
}

int nmain() {
	string s1 = "attack";
	string s2 = "defend";
	return isTangle(s1, s2);
}