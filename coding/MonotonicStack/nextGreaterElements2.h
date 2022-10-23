#pragma once
#include <vector>
#include <stack>

using namespace std;

//class Solution {
//public:
//	/* 先不考虑循环的情况 */
//	vector<int> nextGreaterElements(vector<int>& nums) {
//		stack<int> stk;
//		vector<int> greater(nums.size(), -1);
//		for (int i = 0; i < nums.size(); i++) {
//			while (!stk.empty() && nums[i] > nums[stk.top()]) {
//				int idx = stk.top();
//				stk.pop();
//				greater[idx] = nums[i];
//			}
//			stk.push(i);
//		}
//		/* 在未循环的情况下，右侧没有更大值，栈底元素一定是整个数组的最大值，
//			从这个位置的下一个位置在搜索一轮循环到这个位置为止 */
//		int max_idx = 0;
//		/* 找到最大值的位置（最大值一定是第一个-1的位置） */
//		while (greater[max_idx] != -1) max_idx++;
//		int i = 0;
//		while (i <= max_idx) {
//			while (!stk.empty() && nums[i] > nums[stk.top()]) {
//				int idx = stk.top();
//				stk.pop();
//				greater[idx] = nums[i];
//			}
//			i++;
//		}
//		return greater;
//	}
//};

class Solution {
public:
	/* 配合单调栈 遍历 2 次数组即可 */
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<int> stk;
		vector<int> greater(nums.size(), -1);
		for (int i = 0; i < 2 * nums.size(); i++) {
			int idx = i % nums.size();
			while (!stk.empty() && nums[idx] > nums[stk.top()]) {
				greater[stk.top()] = nums[idx];
				stk.pop();
			}
			stk.push(idx);
		}
		return greater;
	}
};