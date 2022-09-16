#pragma once
#include "Graph.h"

Vertex* findMinDistanceVertex(std::unordered_map<Vertex*, int> &shortest_map, std::unordered_set<Vertex*> &memo) {
	int min = INT_MAX;
	Vertex *min_ver = nullptr;
	for (auto ver_i : shortest_map) {
		if (ver_i.second < min && memo.find(ver_i.first) == memo.end()) {
			min = ver_i.second;
			min_ver = ver_i.first;
		}
	}
	memo.insert(min_ver);
	return min_ver;
}

std::vector<int> Graph::dijkstra(Graph *graph, Vertex *v0) {
	std::unordered_set<Vertex*> memo;
	std::unordered_map<Vertex*, int> shortest_map;
	for (auto ver : graph->vertexs_map) {
		shortest_map.insert({ ver.second, INT_MAX });
	}
	shortest_map[v0] = 0;
	Vertex *min_ver = v0;
	while (min_ver != nullptr) {
		for (auto next : min_ver->edges) {
			int val = next->weight + shortest_map[min_ver];
			Vertex *to = graph->vertexs_map[next->to];
			if (val < shortest_map[to]) {
				shortest_map[to] = val;
			}
		}
	}
}