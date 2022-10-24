#pragma once

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

#include <iostream>

class TreeNode {
public:
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(std::string v) : val_str(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
public:
	int val;
	std::string val_str;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {
public:
	// recursion
	void preorderTraversalRecursion(TreeNode *root);
	void inorderTraversalRecursion(TreeNode *root);
	void postorderTraversalRecursion(TreeNode *root);
	// iterator
	void preorderTraversal(TreeNode *root);
	void inorderTraversal(TreeNode *root);
	void postorderTraversal(TreeNode *root);

	// level traversal
	void levelTraversal(TreeNode *root);
	int getMaxWidthByMap(TreeNode *root);
	int getMaxWidth(TreeNode *root);

	// morris traversal
	void morrisTraversal(TreeNode *root);
	void morrisPreorderTraversal(TreeNode *root); 
	void morrisInorderTraversal(TreeNode *root);
	void morrisPostorderTraversal(TreeNode *root);
};