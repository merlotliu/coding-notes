#pragma once
#include <vector>
#include <stack>
#include <deque>

using namespace std;

//class Solution {
//public:
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		vector<int> res;
//		/* ά��һ�� k ���ȵĻ�������,��¼�������� */
//		deque<int> win;
//		int L = -1;
//		int R = -1;
//		while (++R < nums.size()) {
//			/* ��������ֱ���ܹ�������е��� */
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
		/* �����쳣���� */
		if (nums.size() < 1 || k < 1 || nums.size() < k) {
			return {};
		}
		/* ˫�˶��м�¼�±� */
		deque<int> win;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			/* �������ƶ������ܱ��ֶ��е���������У�ֱ���������㵥�� */
			while (!win.empty() && nums[win.back()] <= nums[i]) {
				win.pop_back();
			}
			win.push_back(i);
			/* ��Ԫ���Ѿ��ڴ����� L = R - k */
			if (win.front() <= i - k) {
				win.pop_front();
			}
			/* �����Ѿ��γɣ���ȡ���ֵ */
			if (i >= k - 1) {
				res.push_back(nums[win.front()]);
			}
		}
		return res;
	}
};