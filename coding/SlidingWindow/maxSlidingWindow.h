#pragma once
#include <vector>
#include <stack>
#include <deque>

using namespace std;

//class Solution {
//public:
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		vector<int> res;
//		/* 维持一个 k 长度的滑动窗口,记录数字索引 */
//		deque<int> win;
//		int L = -1;
//		int R = -1;
//		while (++R < nums.size()) {
//			/* 弹出队列直到能够满足队列单调 */
//			while (!win.empty() && nums[R] > nums[win.back()]) {
//				win.pop_back();
//			}
//			win.push_back(R);
//			if (R >= k - 1) {
//				res.push_back(nums[win.front()]);
//				if (++L >= win.front()) {
//					win.pop_front();
//				}
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		/* 输入异常处理 */
		if (nums.size() < 1 || k < 1 || nums.size() < k) {
			return {};
		}
		/* 双端队列记录下标 */
		deque<int> win;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			/* 窗口右移动，不能保持队列单调则出队列，直至可以满足单调 */
			while (!win.empty() && nums[win.back()] <= nums[i]) {
				win.pop_back();
			}
			win.push_back(i);
			/* 有元素已经在窗口外 L = R - k */
			if (win.front() <= i - k) {
				win.pop_front();
			}
			/* 窗口已经形成，获取最大值 */
			if (i >= k - 1) {
				res.push_back(nums[win.front()]);
			}
		}
		return res;
	}
};