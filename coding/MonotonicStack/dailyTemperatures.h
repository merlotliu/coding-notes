#pragma once
#include <vector>
#include <stack>

using namespace std;

/* 每日温度 */
class Solution {
public:
	/* 相当于获取当前位置右边最近的较大值 */
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		if (temperatures.size() < 1) {
			return {};
		}
		vector<int> answer(temperatures.size(), 0);
		stack<int> max_stk; /* 存放的是下标不是值 */
		max_stk.push(0); /* 先把第一个元素的下标入栈 */
		for (int i = 1; i < temperatures.size(); i++) {
			while (!max_stk.empty() && temperatures[i] > temperatures[max_stk.top()]) {
				/* 依次弹栈，生成栈内元素信息，直到当前元素可以入栈 */
				int idx = max_stk.top();
				max_stk.pop();
				answer[idx] = i - idx; /* 几天后 */
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