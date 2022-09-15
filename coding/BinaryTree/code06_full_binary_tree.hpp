#pragma once
#include "BinaryTree.h"

int getTreeDepth(TreeNode *root) {
	if (root == nullptr) return 0;
	int left_depth = getTreeDepth(root->left) + 1;
	int right_depth = getTreeDepth(root->right) + 1;
	return left_depth >= right_depth ? left_depth : right_depth;
}

int getNodesCount(TreeNode *root) {
	if (root == nullptr) return 0;
	return getNodesCount(root->left) + getNodesCount(root->right) + 1;
}

bool isFBT(TreeNode *root) {
	return (getNodesCount(root) == ((1 << getTreeDepth(root)) - 1));
}