#pragma once
#include <vector>
#include <stack>

using namespace std;

//class Solution {
//public:
//	/* �Ȳ�����ѭ������� */
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
//		/* ��δѭ��������£��Ҳ�û�и���ֵ��ջ��Ԫ��һ����������������ֵ��
//			�����λ�õ���һ��λ��������һ��ѭ�������λ��Ϊֹ */
//		int max_idx = 0;
//		/* �ҵ����ֵ��λ�ã����ֵһ���ǵ�һ��-1��λ�ã� */
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
	/* ��ϵ���ջ ���� 2 �����鼴�� */
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