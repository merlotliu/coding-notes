#pragma once
#include <vector>
#include <stack>

using namespace std;

/* ÿ���¶� */
class Solution {
public:
	/* �൱�ڻ�ȡ��ǰλ���ұ�����Ľϴ�ֵ */
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		if (temperatures.size() < 1) {
			return {};
		}
		vector<int> answer(temperatures.size(), 0);
		stack<int> max_stk; /* ��ŵ����±겻��ֵ */
		max_stk.push(0); /* �Ȱѵ�һ��Ԫ�ص��±���ջ */
		for (int i = 1; i < temperatures.size(); i++) {
			while (!max_stk.empty() && temperatures[i] > temperatures[max_stk.top()]) {
				/* ���ε�ջ������ջ��Ԫ����Ϣ��ֱ����ǰԪ�ؿ�����ջ */
				int idx = max_stk.top();
				max_stk.pop();
				answer[idx] = i - idx; /* ����� */
			}
			max_stk.push(i);
		}
		while (!max_stk.empty()) {
			int idx = max_stk.top();
			max_stk.pop();
			answer[idx] = 0;
		}
		return answer;
	}
};