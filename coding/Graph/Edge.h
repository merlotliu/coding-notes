#pragma once

class Edge {
public:
	Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
public:
	int from;
	int to;
	int weight;
};

