#pragma once
#include "Graph.h"

std::vector<Vertex*> Graph::topologicalSort(Graph *graph) {
	std::vector<Vertex*> res;
	std::unordered_map<Vertex*, int> in_map;
	std::queue<Vertex*> zero_in_queue;
	for (auto i_ver : graph->vertexs_map) {
		Vertex *ver = i_ver.second;
		in_map.insert({ver, ver->in});
		if (ver->in == 0) {
			zero_in_queue.push(ver);
		}
	}
	while (!zero_in_queue.empty()) {
		Vertex *ver = zero_in_queue.front();
		zero_in_queue.pop();
		res.push_back(ver);
		for (Vertex* next : ver->nexts) {	
			if (--in_map[next] == 0) {
				zero_in_queue.push(next);
			}
		}
	}
	return res;
}	