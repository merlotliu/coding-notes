#pragma once
#include "BinaryTree.h"

bool isCBT(TreeNode *root) {
	std::queue<TreeNode*> que;
	que.push(root);
	bool leaf = false;
	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();
		if (cur->left) {
			que.push(cur->left);
		}
		if (cur->right) {
			que.push(cur->right);
		}
		if ((leaf && (cur->left != nullptr || cur->right != nullptr)) 
			|| (cur->left == nullptr && cur->right != nullptr)) {
			return false;
		}
		if (cur->right == nullptr) {
			leaf = true;
		}
	}
	return true;
}