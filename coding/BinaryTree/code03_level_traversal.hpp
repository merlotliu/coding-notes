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