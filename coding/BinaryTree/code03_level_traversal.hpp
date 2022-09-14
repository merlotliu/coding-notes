#pragma once
#include "BinaryTree.h"

void BinaryTree::levelTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode *cur = que.front();
		std::cout << cur->val << " ";
		que.pop();
		if (cur->left) que.push(cur->left);
		if (cur->right) que.push(cur->right);
	}
	return;
}

int BinaryTree::getMaxWidthByMap(TreeNode *root) {
	if (root == nullptr) return 0;
	std::queue<TreeNode*> que;
	que.push(root);
	std::unordered_map<TreeNode*, int> ref;
	int cur_level = 1;
	ref.insert({ root, 1 });
	int max = INT_MIN;
	int cur_count = 0;
	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();
		if (ref[cur] == cur_level) {
			cur_count++;
		}
		else {
			max = max > cur_count ? max : cur_count;
			cur_count = 1;
			cur_level++;
		}
		if (cur->left) {
			que.push(cur->left);
			ref.insert({ cur->left, cur_level + 1 });
		}
		if (cur->right) {
			que.push(cur->right);
			ref.insert({ cur->right, cur_level + 1 });
		}
	}
	max = max > cur_count ? max : cur_count;
	return max;
}

int BinaryTree::getMaxWidth(TreeNode *root) {
	if (root == nullptr) return 0;
	std::queue<TreeNode*> que;
	que.push(root);
	int max = INT_MIN;
	int cur_count = 0;
	TreeNode *cur_end = root;
	TreeNode *next_end = nullptr;
	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();
		if (cur->left) {
			que.push(cur->left);
			next_end = cur->left;
		}
		if (cur->right) {
			que.push(cur->right);
			next_end = cur->right;
		}
		cur_count++;
		if (cur == cur_end) {
			max = max < cur_count ? cur_count : max;
			cur_count = 0;
			cur_end = next_end;
		}
	}
	return max;
}