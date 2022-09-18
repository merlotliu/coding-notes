#include "TrieTree.h"

/*
 * insert string str
 * return the end count of the end node
 */
int TrieTree::insert(std::string &str) {
	TrieNode *cur = _root;
	for (auto ch : str) {
		cur->pass++;
		if (cur->char_map.find(ch) == cur->char_map.end()) {
			cur->char_map.insert({ch, new TrieNode()});
		}
		cur = cur->char_map[ch];
	}
	cur->pass++;
	return ++(cur->end);
}

// find string & return end count
int TrieTree::search(std::string &str) {
	TrieNode *cur = _root;
	for (auto ch : str) {
		if (cur->char_map.find(ch) == cur->char_map.end()) {
			return 0;
		}
		cur = cur->char_map[ch];
	}
	return cur->end;
}

// find prefix count (return pass)
int TrieTree::prefixSearch(std::string &str) {
	TrieNode *cur = _root;
	for (auto ch : str) {
		if (cur->char_map.find(ch) == cur->char_map.end()) {
			return 0;
		}
		cur = cur->char_map[ch];
	}
	return cur->pass;
}

int TrieTree::del(std::string &str) {
	if (search(str) == 0) {
		return 0;
	}
	TrieNode *cur = _root;
	TrieNode *zero_node = nullptr;
	for (auto ch : str) {
		int pass = --(cur->pass);
		zero_node = cur;
		cur = cur->char_map[ch];
		if (pass == 0) {
			delete zero_node;
			continue;
		}
	}
	int end = --(cur->end);
	if (--(cur->pass) == 0) delete cur;
	return end;
}

TrieTree::TrieTree() {
	_root = new TrieNode;
}