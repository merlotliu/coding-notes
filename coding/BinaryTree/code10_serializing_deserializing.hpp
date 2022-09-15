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
	std::stringstream ss(str);   //读取str到字符串流中
	std::string tmp;
	//使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
	//注意,getline默认是可以读取空格的
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