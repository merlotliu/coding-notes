#pragma once

class Vertex;

class Edge {
public:
	Edge(Vertex *f, Vertex *t, int w) : from(f), to(t), weight(w) {}
public:
	Vertex *from;
	Vertex *to;
	int weight;
};

