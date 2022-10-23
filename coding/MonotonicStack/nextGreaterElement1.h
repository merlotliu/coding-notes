#pragma once
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	/* 1. ͨ������ջ��� nums2 ��ÿһ��Ԫ�ض�Ӧ����һ�������Ԫ��ֵ��
	   2. ���� nums1 ���ɽ�����飻
	*/
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stk; /* ջ��Ԫ��Ϊmax */
		/* �±��ʾ nums2 �е�Ԫ�أ�Ԫ�ر�ʾ nums2 ����һ�������Ԫ��ֵ */
		/* ��ȻҲ���Լ�¼����Ԫ�ص��±ֻ꣬����Ҫ��ת��һ�� */
		vector<int> greater(10000, -1);
		for (auto num : nums2) {
			while (!stk.empty() && num > stk.top()) {
				int idx = stk.top();
				stk.pop();
				greater[idx] = num;
			}
			stk.push(num);
		}
		/* ��Ϊǰ���Ѿ���ʼ���ˣ������൱�ڴ��������ջ��Ϊ�յ���� */
		// while(!stk.empty()) {
		//     int idx = stk.top();
		//     stk.pop();
		//     greater[idx] = -1;
		// }

		/* ���� nums1 ���ɽ������ */
		vector<int> res;
		for (auto num : nums1) {
			res.push_back(greater[num]);
		}
		return res;
	}
};