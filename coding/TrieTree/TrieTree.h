#pragma once
#include <map>
#include <string>
#include <vector>

class TrieNode {
public:
	TrieNode() : pass(0), end(0) {}
public:
	int pass;
	int end;
	std::map<char, TrieNode*> char_map;
};

class TrieTree {
public:
	// insert string
	int insert(std::string &str);
	// find string & return end count
	int search(std::string &str);
	// find prefix count (return pass)
	int prefixSearch(std::string &str);
	int del(std::string &str);

public:
	TrieTree();

private:
	TrieNode *_root;
};