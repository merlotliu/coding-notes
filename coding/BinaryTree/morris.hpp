#pragma once
#include "BinaryTree.h"

/* morris 遍历，有左孩子的节点会遍历两次，没有左孩子的节点只会被遍历一次 */
void BinaryTree::morrisTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* 有左孩子 */
			/* 找到左子树最右孩子 */
			mostRight = cur->left;
			/* 右指针不为null，不等于当前节点时继续 */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* 第一次遍历此节点 */
				//![1] 操作节点 
				printf("%d ", cur->val);
				//[1]
				mostRight->right = cur;
				cur = cur->left;
				continue;
			} else if (mostRight->right == cur) { /* 第二次遍历此节点 */
				//![2] 操作节点

				//[2]
				mostRight->right = nullptr;
			}
		}
		//![3] 操作节点
		printf("%d ", cur->val);
		//[3]
		cur = cur->right; /* 左子树遍历完或没有左子树则遍历右子树 */
	}
	printf("\n");
	return;
}

/* morris 前序遍历: 不管是遍历几次的节点，都在第一次遍历时候处理打印 */
void BinaryTree::morrisPreorderTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* 有左孩子 */
			/* 找到左子树最右孩子 */
			mostRight = cur->left;
			/* 右指针不为null，不等于当前节点时继续 */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* 第一次遍历此节点 */
				//![1] 操作节点
				printf("%d ", cur->val);
				//[1]
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* 第二次遍历此节点 */
				mostRight->right = nullptr;
			}
		} else {
			//![2] 操作节点
			printf("%d ", cur->val);
			//[2]
		}
		cur = cur->right; /* 左子树遍历完或没有左子树则遍历右子树 */
	}
	printf("\n");
	return;
}

/* morris 中序遍历: 遍历一次的节点第一次打印，遍历两次的节点第二次打印 */
void BinaryTree::morrisInorderTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* 有左孩子 */
			/* 找到左子树最右孩子 */
			mostRight = cur->left;
			/* 右指针不为null，不等于当前节点时继续 */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* 第一次遍历此节点 */
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* 第二次遍历此节点 */
				
				mostRight->right = nullptr;
			}
		}
		//![1] 操作节点 
		printf("%d ", cur->val);
		//[1]
		cur = cur->right; /* 左子树遍历完或没有左子树则遍历右子树 */
	}
	printf("\n");
	return;
}

/* morris 后序遍历 ：
- 不管是遍历几次的节点，在第一次遍历时，不进行任何处理；
- 而在遍历两次的节点，遍历到第二次时，**逆序打印该节点的左孩子的右边界** （单链表逆序）；
- 遍历结束后，单独打印整棵树的右边界； */

/* 反转右边界仅操作 right指针 */
TreeNode *reverse(TreeNode *root) {
	TreeNode *next = root->right;
	root->right = nullptr;
	while (next != nullptr) {
		TreeNode *tmp = next->right;
		next->right = root;
		root = next;
		next = tmp;
	}
	return root;
}

void printfEdge(TreeNode *root) {
	TreeNode *tmp = reverse(root);
	TreeNode *cur = tmp;
	while (cur != nullptr) {
		printf("%d ", cur->val);
		cur = cur->right;
	}
	reverse(tmp);
}

void BinaryTree::morrisPostorderTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* 有左孩子 */
			/* 找到左子树最右孩子 */
			mostRight = cur->left;
			/* 右指针不为null，不等于当前节点时继续 */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* 第一次遍历此节点 */
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* 第二次遍历此节点 */
				mostRight->right = nullptr;
				//![1] 操作节点 
				printfEdge(cur->left);
				//[1]
			}
		}
		cur = cur->right; /* 左子树遍历完或没有左子树则遍历右子树 */
	}
	printfEdge(root);
	printf("\n");
	return;
}