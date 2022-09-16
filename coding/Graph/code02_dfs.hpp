#pragma once
#include "Graph.h"

void Graph::DFS(Graph *graph) {
	std::stack<Vertex*> stk;
	std::unordered_set<Vertex*> memo;
	memo.insert(graph->vertexs_map[0]);
	stk.push(graph->vertexs_map[0]);
	while (!stk.empty()) {
		Vertex *cur = stk.top();
		stk.pop();
		doHandle(cur);
		for (auto next : cur->nexts) {
			if (memo.find(next) == memo.end()) {
				memo.insert(next);
				stk.push(cur);
				stk.push(next);
				break;
			}
		}
	}
}