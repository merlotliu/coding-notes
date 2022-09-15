#pragma once

class TreeNodeP {
public:
	TreeNodeP(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}

public:
	int val;
	TreeNodeP *left;
	TreeNodeP *right;
	TreeNodeP *parent;
};

TreeNodeP* getSuccessor(TreeNodeP *node) {
	if (node == nullptr) return nullptr;
	// there is right tree
	TreeNodeP *successor = nullptr;
	if (node->right != nullptr) {
		successor = node->right;
		while (successor->left) {
			successor = successor->left;
		}
		return successor;
	}
	// not
	TreeNodeP *cur = node;
	TreeNodeP *successor = cur->parent;
	while(successor != nullptr && successor->left != cur) {
		cur = successor;
		successor = cur->parent;
	}
	return successor;
}