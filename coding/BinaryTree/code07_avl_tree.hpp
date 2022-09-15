#pragma once
#include "BinaryTree.h"

class RetVal {
public:
	RetVal(bool avl, int d) : is_avl(avl), depth(d) {}

public:
	bool is_avl;
	int depth;
};

RetVal isAVL(TreeNode *root) {
	if (root == nullptr) return RetVal(true, 0);

	RetVal left = isAVL(root->left);
	if (!left.is_avl) return RetVal(false, left.depth);
	RetVal right = isAVL(root->right);
	if (!right.is_avl) return RetVal(false, right.depth);
	
	bool is_avl = abs(left.depth - right.depth) <= 1;
	int max_depth = left.depth >= right.depth ? left.depth + 1 : right.depth + 1;
	return RetVal(is_avl, max_depth);
}