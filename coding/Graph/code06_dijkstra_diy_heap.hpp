#pragma once
#include "Graph.h"

class VertexRecord {
public:
	VertexRecord(Vertex *v, int d) : vertex(v), distance(d) {}
public:
	Vertex *vertex;
	int distance;
};

class VertexHeap {
public:
	void updateVertexRecord(Vertex *vertex, int distance) {
		push(vertex, distance);
		int cur_idx = vertex_idx_map[vertex];
		if (cur_idx == -1) return;
		if (records_heap[cur_idx]->distance > distance) {
			records_heap[cur_idx]->distance = distance;
		}
		heapInsert(vertex_idx_map[vertex]);

		// vertex is or not exist
		// -1 : already pop
		// idx normal : exist
	}
	
	// get top of heap & pop
	VertexRecord* pop() {
		if (_size != 0) {
			// swap head & tail
			swap(records_heap[0], records_heap[_size - 1]); 
			// reheap
			heapify(0, _size);
			// mark to -1 show that the vertex is not in the heap but was exist
			vertex_idx_map[records_heap[_size - 1]->vertex] = -1;
			// return top & pop
			return records_heap[--_size];
		}
		return nullptr;
	}

	bool isEmpty() {
		return _size == 0;
	}

private:
	void push(Vertex *vertex, int distance) {
		if (vertex_idx_map.find(vertex) == vertex_idx_map.end()) {
			VertexRecord *cur = new VertexRecord(vertex, distance);
			if (_size < records_heap.size()) {
				records_heap[_size] = cur;
			} else {
				records_heap.push_back(cur);
			}
			vertex_idx_map[cur->vertex] = _size++;
		}
	}

	void heapInsert(int idx) {
		while (records_heap[idx]->distance < records_heap[(idx - 1) >> 1]->distance) {
			swap(records_heap[idx], records_heap[(idx - 1) >> 1]);
			idx = (idx - 1) >> 1;
		}
	}

	void heapify(int idx, int size) {
		VertexRecord *cur = records_heap[idx];
		int left_idx = idx * 2 + 1;
		while (left_idx < size) {
			int min_child_idx = left_idx + 1 < size
				&& records_heap[left_idx]->distance > records_heap[left_idx + 1]->distance ?
				left_idx + 1 : left_idx;
			if (records_heap[idx]->distance < records_heap[min_child_idx]->distance) {
				break;
			}
			swap(records_heap[idx], records_heap[min_child_idx]);
			idx = min_child_idx;
		}
	}

	void swap(VertexRecord* a, VertexRecord* b) {
		int idx = vertex_idx_map[a->vertex];
		vertex_idx_map[a->vertex] = vertex_idx_map[b->vertex];
		vertex_idx_map[b->vertex] = idx;
		VertexRecord tmp = *a;
		*a = *b;
		*b = tmp;
	}

public:
	VertexHeap() :_size(0) {}

private:
	int _size;
	std::vector<VertexRecord*> records_heap;
	std::unordered_map<Vertex*, int> vertex_idx_map;
};

std::vector<VertexRecord*> dijkstra(Graph *graph, Vertex *v0) {
	std::vector<VertexRecord*> res;
	VertexHeap vertex_heap;
	vertex_heap.updateVertexRecord(v0, 0);
	while (!vertex_heap.isEmpty()) {
		VertexRecord *cur = vertex_heap.pop();
		int distance_to_v0 = cur->distance;
		for (auto edge : cur->vertex->edges) {
			vertex_heap.updateVertexRecord(edge->to, edge->weight + distance_to_v0);
		}
		res.push_back(cur);
	}
	return res;
}