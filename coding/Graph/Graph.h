#pragma once
#include <stack>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "Vertex.h"
#include "Edge.h"

class Graph {
public:
	void generateGraph(std::vector<std::vector<int>> &arr);
	
	void BFS(Graph *graph);
	void DFS(Graph *graph);
	std::vector<Vertex*> topologicalSort(Graph *graph);
	std::vector<Edge*> kruskal(Graph *graph);
	std::vector<Edge*> prim(Graph *graph);
	std::vector<int> dijkstra(Graph *graph, Vertex *v0);
	
	void doHandle(Vertex *ver);
public:
	std::unordered_map<int, Vertex*> vertexs_map;
	std::unordered_set<Edge*> edges;
}; 

