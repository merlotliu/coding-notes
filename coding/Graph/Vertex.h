#pragma once
#include <vector>

#include "Edge.h"

class Vertex {
public:
	int val;
	int in;
	int out;
	std::vector<Vertex*> nexts;
	std::vector<Edge*> edges;
};
