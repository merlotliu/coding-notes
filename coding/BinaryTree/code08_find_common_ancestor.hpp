#pragma once
#include "BinaryTree.h"

void findParent(TreeNode *root, TreeNode *parent, std::unordered_map<TreeNode*, TreeNode*> &parentMap) {
	if (root == nullptr) return;
	parentMap.insert({ root, parent });
	findParent(root->left, root, parentMap);
	findParent(root->right, root, parentMap);
}

TreeNode* findCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2) {
	std::unordered_map<TreeNode*, TreeNode*> parentMap;
	findParent(root, nullptr, parentMap);
	
	std::unordered_set<TreeNode*> node1_path;
	TreeNode *cur = node1;
	while (cur != nullptr) {
		node1_path.insert(cur);
		cur = parentMap[cur];
	}

	cur = node2;
	while (cur != nullptr) {
		if(node1_path.find(cur) != node1_path.end()) return cur;
		cur = parentMap[cur];
	}
	return nullptr;
}

TreeNode* findCommonAncestorRecur(TreeNode *root, TreeNode *node1, TreeNode *node2) {
	if (root == nullptr || root == node1 || root == node2) return root;

	TreeNode *left = findCommonAncestorRecur(root->left, node1, node2);
	TreeNode *right = findCommonAncestorRecur(root->right, node1, node2);

	if (left != nullptr || right != nullptr) return root;
	return (left == nullptr ? right : left);
}