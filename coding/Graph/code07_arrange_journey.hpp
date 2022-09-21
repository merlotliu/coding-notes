#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Edge{
public:
	Edge(Vertex* from, Vertex* to) : from(from), to(to) {}
public:
	Vertex* from;
	Vertex* to;
};

class Vertex {
public:
	Vertex(string v) : val(v) {}
public:
	std::string val;
	std::vector<Vertex*> nexts;
	std::vector<Edge*> edges;
};

class Graph {
public:
	std::unordered_map<std::string, Vertex*> vertex_map;
	std::unordered_set<Edge*> edges;
};

class Solution {
public:
	vector<string> res;
public:
	Graph* generateGraph(vector<vector<string>>& tickets) {
		Graph *graph = new Graph;
		for (auto ticket : tickets) {
			Vertex* from = new Vertex(ticket[0]);
			Vertex* to = new Vertex(ticket[1]);
			if (graph->vertex_map.find(ticket[0]) == graph->vertex_map.end()) {
				graph->vertex_map.insert({ ticket[0], from });
			}
			if (graph->vertex_map.find(ticket[1]) == graph->vertex_map.end()) {
				graph->vertex_map.insert({ ticket[1], to });
			}
			Edge *edge = new Edge(from, to);
			graph->edges.insert(edge);
			from->nexts.push_back(to);
			from->edges.push_back(edge);
		}
		return graph;
	}
	void dfs(Graph *graph) {

	}

	void dfs(Graph *graph, string start) {
		vector<bool> memo(graph->vertex_map.size(), false);
		vector<string> picked;
		for (auto str_ver : graph->vertex_map) {
			if (str_ver.first == start) {
				dfs(graph);
			}
		}
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		// build graph
		Graph *graph = generateGraph(tickets);
		// start point
		// dfs		
		dfs(graph, "JFK");
		
		return res;
	}
};