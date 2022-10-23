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
		// 1. ͨ������ջ�ȼ���ÿ��λ�ã���������Ľϴ�ֵ��
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
					// 3. ���м�����ˮ�������
					// (��������ϸ����ӵĽ�Сֵ - ��ǰ���ӵĸ߶�) * (�Ҳ����� - 1 - �������)
					int l_idx = stk.top()->val;
					int h = min(height[l_idx], height[i]);
					sum += (i - 1 - l_idx) * (h - height[top_node->val]);
				}
			}
			/* ��������ͬ���ȵ�����ʱ���������Ҳ����� */
			if (!stk.empty() && height[i] == height[stk.top()->val]) {
				stk.pop();
			}
			stk.push(node);
		}
		return sum;
	}
};