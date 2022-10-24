#pragma once
#include "BinaryTree.h"

/* morris �����������ӵĽڵ��������Σ�û�����ӵĽڵ�ֻ�ᱻ����һ�� */
void BinaryTree::morrisTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* ������ */
			/* �ҵ����������Һ��� */
			mostRight = cur->left;
			/* ��ָ�벻Ϊnull�������ڵ�ǰ�ڵ�ʱ���� */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* ��һ�α����˽ڵ� */
				//![1] �����ڵ� 
				printf("%d ", cur->val);
				//[1]
				mostRight->right = cur;
				cur = cur->left;
				continue;
			} else if (mostRight->right == cur) { /* �ڶ��α����˽ڵ� */
				//![2] �����ڵ�

				//[2]
				mostRight->right = nullptr;
			}
		}
		//![3] �����ڵ�
		printf("%d ", cur->val);
		//[3]
		cur = cur->right; /* �������������û������������������� */
	}
	printf("\n");
	return;
}

/* morris ǰ�����: �����Ǳ������εĽڵ㣬���ڵ�һ�α���ʱ�����ӡ */
void BinaryTree::morrisPreorderTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* ������ */
			/* �ҵ����������Һ��� */
			mostRight = cur->left;
			/* ��ָ�벻Ϊnull�������ڵ�ǰ�ڵ�ʱ���� */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* ��һ�α����˽ڵ� */
				//![1] �����ڵ�
				printf("%d ", cur->val);
				//[1]
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* �ڶ��α����˽ڵ� */
				mostRight->right = nullptr;
			}
		} else {
			//![2] �����ڵ�
			printf("%d ", cur->val);
			//[2]
		}
		cur = cur->right; /* �������������û������������������� */
	}
	printf("\n");
	return;
}

/* morris �������: ����һ�εĽڵ��һ�δ�ӡ���������εĽڵ�ڶ��δ�ӡ */
void BinaryTree::morrisInorderTraversal(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	TreeNode *cur = root;
	TreeNode *mostRight = nullptr;
	while (cur != nullptr) {
		if (cur->left != nullptr) {/* ������ */
			/* �ҵ����������Һ��� */
			mostRight = cur->left;
			/* ��ָ�벻Ϊnull�������ڵ�ǰ�ڵ�ʱ���� */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* ��һ�α����˽ڵ� */
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* �ڶ��α����˽ڵ� */
				
				mostRight->right = nullptr;
			}
		}
		//![1] �����ڵ� 
		printf("%d ", cur->val);
		//[1]
		cur = cur->right; /* �������������û������������������� */
	}
	printf("\n");
	return;
}

/* morris ������� ��
- �����Ǳ������εĽڵ㣬�ڵ�һ�α���ʱ���������κδ���
- ���ڱ������εĽڵ㣬�������ڶ���ʱ��**�����ӡ�ýڵ�����ӵ��ұ߽�** �����������򣩣�
- ���������󣬵�����ӡ���������ұ߽磻 */

/* ��ת�ұ߽������ rightָ�� */
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
		if (cur->left != nullptr) {/* ������ */
			/* �ҵ����������Һ��� */
			mostRight = cur->left;
			/* ��ָ�벻Ϊnull�������ڵ�ǰ�ڵ�ʱ���� */
			while (mostRight->right != nullptr && mostRight->right != cur) {
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) { /* ��һ�α����˽ڵ� */
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else if (mostRight->right == cur) { /* �ڶ��α����˽ڵ� */
				mostRight->right = nullptr;
				//![1] �����ڵ� 
				printfEdge(cur->left);
				//[1]
			}
		}
		cur = cur->right; /* �������������û������������������� */
	}
	printfEdge(root);
	printf("\n");
	return;
}