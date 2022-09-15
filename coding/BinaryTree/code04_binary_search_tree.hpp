#pragma once
#include "BinaryTree.h"

int pre_val = INT_MIN;

bool isBST(TreeNode *root) {
	if (root == nullptr) return true;
	bool left = isBST(root->left);
	if (left == false) return false;
	if (pre_val >= root->val) {
		return false;
	} else {
		pre_val = root->val;
	}
	return isBST(root->right);
}