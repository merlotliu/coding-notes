#pragma once
#include "Graph.h"

std::vector<Edge*> Graph::prim(Graph *graph) {
	std::vector<Edge*> res;
	std::unordered_set<Vertex*> memo;
	auto cmp = [](Edge *left, Edge *right) { 
		return (left->weight > right->weight) - (left->weight < right->weight);
	};
	std::priority_queue<Edge*, std::vector<Edge*>, decltype(cmp)> small_heap(cmp);
	
	for (auto i_ver : graph->vertexs) {
		Vertex *ver = i_ver.second;
		if(memo.find(ver) == memo.end()) {
			memo.insert(ver);
			for (auto edge : ver->edges) {
				small_heap.push(edge);
			}
			while (!small_heap.empty()) {
				Edge *min_edge = small_heap.top();
				small_heap.pop();
				Vertex *from = graph->vertexs[min_edge->from];
				Vertex *to = graph->vertexs[min_edge->to];
				if (memo.find(to) == memo.end()) {
					res.push_back(min_edge);
					memo.insert(to);
					for (auto edge : to->edges) {
						small_heap.push(edge);
					}
				}
			}
		}
	}
	return res;
}