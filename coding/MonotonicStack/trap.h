#pragma once
#include <vector>
#include <stack>

using namespace std;

class Solution {
	struct ListNode {
		int val;
		ListNode *next;
	};
public:
	int min(int a, int b) {
		return a < b ? a : b;
	}
	int trap(vector<int>& height) {
		// 1. 通过单调栈先计算每个位置，左右最近的较大值；
		stack<ListNode*> stk;
		vector<pair<int, int>> greater(height.size(), pair<int, int>(-1, -1));
		int sum = 0;
		for (int i = 0; i < height.size(); i++) {
			ListNode *node = new ListNode;
			node->val = i;
			node->next = nullptr;
			while (!stk.empty() && height[i] > height[stk.top()->val]) {
				ListNode *top_node = stk.top();
				stk.pop();
				if (!stk.empty()) {
					// 3. 按行计算雨水的体积：
					// (左右两侧较高柱子的较小值 - 当前柱子的高度) * (右侧索引 - 1 - 左侧索引)
					int l_idx = stk.top()->val;
					int h = min(height[l_idx], height[i]);
					sum += (i - 1 - l_idx) * (h - height[top_node->val]);
				}
			}
			/* 当存在相同长度的柱子时，仅保留右侧柱子 */
			if (!stk.empty() && height[i] == height[stk.top()->val]) {
				stk.pop();
			}
			stk.push(node);
		}
		return sum;
	}
};