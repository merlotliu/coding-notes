#pragma once
#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Vertex;
class Edge;

class Vertex {
public:
	Vertex(string v) : val(v) {}
public:
	std::string val;
	std::vector<Vertex*> nexts;
	std::vector<Edge*> edges;
};

class Edge {
public:
	Edge(Vertex* f, Vertex* t) : from(f), to(t) {}
public:
	Vertex* from;
	Vertex* to;
	string weight;
};

class Graph {
public:
	std::unordered_map<std::string, Vertex*> vertex_map;
	std::unordered_set<Edge*> edges;
};

class Solution {
public:
	vector<string> res;
	vector<string> picked;
public:
	Graph* generateGraph(vector<vector<string>>& tickets) {
		Graph *graph = new Graph;
		for (auto ticket : tickets) {
			if (graph->vertex_map.find(ticket[0]) == graph->vertex_map.end()) {
				graph->vertex_map.insert({ ticket[0], new Vertex(ticket[0]) });
			}
			if (graph->vertex_map.find(ticket[1]) == graph->vertex_map.end()) {
				graph->vertex_map.insert({ ticket[1], new Vertex(ticket[1]) });
			}
			Vertex* from = graph->vertex_map[ticket[0]];
			Vertex* to = graph->vertex_map[ticket[1]];
			Edge *edge = new Edge(from, to);
			edge->weight = ticket[1];
			graph->edges.insert(edge);
			from->nexts.push_back(to);
			from->edges.push_back(edge);
		}
		return graph;
	}

	void DFS(Graph *graph, string start) {
		std::stack<Vertex*> stk;
		std::unordered_set<Vertex*> memo;
		memo.insert(graph->vertex_map[start]);
		stk.push(graph->vertex_map[start]);
		while (!stk.empty()) {
			Vertex *cur = stk.top();
			stk.pop();
			std::cout << cur->val << std::endl;
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
	
	void minDictJourey() {
		if (res.empty()) {
			res = picked;
			return;
		}
		int i = 0;
		while (i < picked.size() && picked[i] == res[i]) i++;
		if (i < picked.size() && picked[i] < res[i]) {
			res = picked;
			return;
		}
		return;
	}

	vector<string> dfs(Graph *graph, Vertex *cur) {
		unordered_set<Edge*> memo;
		while (memo.size() != graph->edges.size()) {
			Edge *min_edge = nullptr;
			for(auto edge : cur->edges) {
				if (memo.find(edge) == memo.end()) {
					if (min_edge == nullptr || min_edge->weight > edge->weight) {
						min_edge = edge;
					}
				}
			}
			if (min_edge) {
				memo.insert(min_edge);
				picked.push_back(min_edge->weight);
				cur = min_edge->to;
			}
		}
		res = picked;
		return picked;
	}

	void dfs(Graph *graph, Vertex *cur, unordered_set<Edge*> &memo) {
		if (picked.size() == graph->edges.size() + 1) {
			minDictJourey();
			return;
		}
		for(auto edge : cur->edges){
			// if the edge is not visited that show the ticket is not used
			if (memo.find(edge) == memo.end()) {
				memo.insert(edge);
				picked.push_back(edge->to->val);
				dfs(graph, edge->to, memo);
				picked.pop_back();
				memo.erase(edge);
			}
		}
	}

	void dfs(Graph *graph, string start) {
		unordered_set<Edge*> memo;
		picked.push_back(start);
		dfs(graph, graph->vertex_map[start]);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		// build graph
		Graph *graph = generateGraph(tickets);
		//DFS(graph, "JFK");
		// start point
		// dfs		
		dfs(graph, "JFK");
		// result
		return res;
	}
};