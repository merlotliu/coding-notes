#pragma once
#include "BinaryTree.h"

void BinaryTree::preorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	std::cout << root->val << " ";
	preorderTraversalRecursion(root->left);
	preorderTraversalRecursion(root->right);
}

void BinaryTree::inorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	inorderTraversalRecursion(root->left);
	std::cout << root->val << " ";
	inorderTraversalRecursion(root->right);
}

void BinaryTree::postorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	postorderTraversalRecursion(root->left);
	postorderTraversalRecursion(root->right);
	std::cout << root->val << " ";
}

void BinaryTree::preorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *cur = stk.top();
		std::cout << cur->val << " ";
		stk.pop();
		if (cur->right) stk.push(cur->right);
		if (cur->left) stk.push(cur->left);
	}
	return;
}

void BinaryTree::inorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	TreeNode *cur = root;
	while (!stk.empty() || cur != nullptr) {
		if (cur != nullptr) {
			while (cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			}
		} else {
			cur = stk.top();
			stk.pop();
			std::cout << cur->val << " ";
			cur = cur->right;
		}
	}
}

void BinaryTree::postorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	std::stack<TreeNode*> help;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *cur = stk.top();
		help.push(cur);
		stk.pop();
		if (cur->left) stk.push(cur->left);
		if (cur->right) stk.push(cur->right);
	}
	while (!help.empty()) {
		std::cout << help.top()->val << " ";
		help.pop();
	}
	return;
}