#pragma once
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	/* 1. 通过单调栈求得 nums2 中每一个元素对应的下一个更大的元素值；
	   2. 遍历 nums1 生成结果数组；
	*/
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk; /* 栈底元素为max */
		/* 下标表示 nums2 中的元素，元素表示 nums2 中下一个更大的元素值 */
		/* 当然也可以记录数组元素的下标，只不过要多转化一下 */
		vector<int> greater(10000, -1);
		for (auto num : nums2) {
			while (!stk.empty() && num > stk.top()) {
				int idx = stk.top();
				stk.pop();
				greater[idx] = num;
			}
			stk.push(num);
		}
		/* 因为前面已经初始化了，所以相当于处理了最后栈不为空的情况 */
		// while(!stk.empty()) {
		//     int idx = stk.top();
		//     stk.pop();
		//     greater[idx] = -1;
		// }

		/* 遍历 nums1 生成结果数组 */
		vector<int> res;
		for (auto num : nums1) {
			res.push_back(greater[num]);
		}
		return res;
	}
};