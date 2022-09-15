#pragma once
#include "BinaryTree.h"

TreeNode* generateTree(TreeNode *cur, int n) {
	if (n == 1) return nullptr;
	cur->left = new TreeNode("down");
	cur->right = new TreeNode("up");
	generateTree(cur->left, n - 1);
	generateTree(cur->right, n - 1);
	return cur;
}

void inorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	inorderTraversal(root->left);
	std::cout << root->val_str << " ";
	inorderTraversal(root->right);
} 

// down °¼ up Í¹
void printPaperCreaseFacing(int n) {
	if (n < 1) return;
	TreeNode *root = new TreeNode("down");
	generateTree(root, n);
	inorderTraversal(root);
}

void printPaperFolds(int level, int N, bool down) {
	if (level > N) return;
	printPaperFolds(level + 1, N, true);
	std::cout << (down ? "down" : "up") << " ";
	printPaperFolds(level + 1, N, false);
}

void printPaperFolds(int n, bool down) {
	if (n < 1) return;
	printPaperFolds(n - 1, true);
	std::cout << (down ? "down" : "up") << " ";
	printPaperFolds(n - 1, false);
}