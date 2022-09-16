#pragma once
#include "Graph.h"

class UnionSet {
public:
	void unionSet(int a, int b) {
		int a_p = findParent(a);
		int b_p = findParent(b);
		arr[b_p] = a_p;
	}

	int isSameSet(int a, int b) {
		return findParent(a) == findParent(b);
	}

	int findParent(int cur) {
		while(cur != arr[cur])
			cur = arr[cur];
		return cur;
	}

	UnionSet(int len) : _len(len) {
		arr = new int[len+1];
		for (int i = 0; i <= len; i++) {
			arr[i] = i;
		}
	}
private:
	int _len;
	int *arr;
};

std::vector<Edge*> Graph::kruskal(Graph *graph) {
	UnionSet *union_set = new UnionSet(graph->vertexs_map.size());
	std::vector<Edge*> res;
	auto cmp = [](Edge *left, Edge *right) {
		return (left->weight > left->weight) - (left->weight < left->weight);
	};
	std::priority_queue<Edge*, std::vector<Edge*>, decltype(cmp)> small_heap(cmp);
	for (auto edge : graph->edges) {
		small_heap.push(edge);
	}
	while (!small_heap.empty()) {
		Edge *edge = small_heap.top();
		small_heap.pop();
		if (!union_set->isSameSet(edge->from, edge->to)) {
			res.push_back(edge);
			union_set->unionSet(edge->from, edge->to);
		}
	}
	return res;
}