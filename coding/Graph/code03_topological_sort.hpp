#pragma once
#include "Graph.h"

Vertex* getZeroInVertex(Graph *graph, std::unordered_set<Vertex*> &memo) {
	std::unordered_map<int, Vertex*>::iterator iter = graph->vertexs.begin();
	for (auto i_vertex : graph->vertexs) {
		Vertex* ver = i_vertex.second;
		if (0 == ver->in && memo.find(ver) == memo.end()) {
			memo.insert(ver);
			for (auto next : ver->nexts) {
				next->in--;
			}
			return ver;
		}
	}
	return nullptr;
}

std::vector<Vertex*> Graph::topologicalSort(Graph *graph) {
	std::vector<Vertex*> res;
	std::unordered_set<Vertex*> memo;
	Vertex* ver = getZeroInVertex(graph, memo);
	while (ver != nullptr) {
		res.push_back(ver);
		ver = getZeroInVertex(graph, memo);
	}
	return res;
}