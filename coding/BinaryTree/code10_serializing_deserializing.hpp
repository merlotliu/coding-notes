#pragma once
#include "BinaryTree.h"

void serializing(TreeNode *root, std::string &res) {
	if (root == nullptr) {
		res += "#_";
		return;
	}
	res += std::to_string(root->val);
	res += "_";
	serializing(root->left, res);
	serializing(root->right, res);
}

void split(std::vector<std::string> &res, std::string &str, char delim) {
	std::stringstream ss(str);   //��ȡstr���ַ�������
	std::string tmp;
	//ʹ��getline�������ַ������ж�ȡ,�����ָ���ʱֹͣ,�ʹ�cin�ж�ȡ����
	//ע��,getlineĬ���ǿ��Զ�ȡ�ո��
	while (std::getline(ss, tmp, delim)) {
		res.push_back(tmp);
	}
	return ;
}

TreeNode* deserializing(std::vector<std::string> &arr, int &idx) {
	if (arr[idx] == "#") {
		idx++;  
		return nullptr;
	}
	TreeNode *root = new TreeNode(atoi(arr[idx++].c_str()));
	root->left = deserializing(arr, idx);
	root->right = deserializing(arr, idx);
	return root;
}

TreeNode* deserializing(std::string &str) {
	std::vector<std::string> res;
	char delim = '_';
	split(res, str, delim);
	int idx = 0;
	return deserializing(res, idx);
}