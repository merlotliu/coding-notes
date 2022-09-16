#pragma once
#include "Graph.h"

void Graph::BFS(Graph *graph) {
	std::queue<Vertex*> que;
	std::unordered_set<Vertex*> memo;
	memo.insert(graph->vertexs_map[0]);
	que.push(graph->vertexs_map[0]);
	while (!que.empty()) {
		Vertex *cur = que.front();
		que.pop();
		doHandle(cur); // handle data
		for (auto next : cur->nexts) {
			if (memo.find(next) == memo.end()) {
				memo.insert(next);
				que.push(next);
			}
		}
	}
}