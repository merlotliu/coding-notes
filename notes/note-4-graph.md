# 图

包含点集和边集。

边通常包含起点、终点和权值。可定义为以下结构：

```cpp
class Edge {
public:
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
public:
	int from;
	int to;
	int val;
};
```

点通常包含点的唯一标识、入度、出度，也可以包含其他相关信息，比如直接邻居、从当前点发出的边。可定义为如下结构：

```cpp
class Vertex {
public:
	int val;
	int in;
	int out;
	std::vector<Vertex*> nexts;
	std::vector<Edge*> edges;
};
```

## 表示方式

选择一种自己较为喜欢的、使用范围较广的表示方法，尽量在之后的图的相关coding中都是用该表示，当表示不同时，将其他方式转化为自己熟悉的方式再编写算法。

### 1 邻接表



### 2 邻接矩阵

对于n个节点的图，需要一个n*n的矩阵

```
// n 为4时
// 	  0  1  2  3
0	[[0, 2, 5, ∞],
1	[2, 0, 7, 4],
2	[5, 7, 0, 3],
3	[∞, 4, 3, 0]]
```

行列表示的都是节点，值表示权值，∞表示不可达（通常用一个最小值或特定的符号表示），0表示自己。

对于无向图，沿对角线都是对称的。

### 3 二维数组

有时题目中会给出如下所示的二维数组

```
[[1, 2, 7],
[1, 3, 4],
[1, 4, 16],
[2, 3, 5],
[2, 4, 5],
[2, 5, 2],
[3, 4, 6]]
```

其中，第1、2列分别表示两个节点，第3个值表示权值。

### 4 一维数组

也有一些特殊的图可以使用一维数组表示

```
  [5, 2, 5, 4, 3, 1]
// 0  1  2  3  4  5
```

下标表示起点，值表示重点，也是可以表示图的，只不过适用范围较窄。

### 偏好表示



## 经典算法

### 1 广度优先遍历 BFS

1. 使用队列，先进先出；
2. 使用哈希表记录已经访问过的节点，防止成环；
3. 随意选择一个节点开始，将该节点压入队列，并使用哈希表记录；
4. 队首元素出队列，处理节点信息，并将与他的直接相连的所有不在哈希表记录中的节点压入队列，并使用哈希表记录；
5. 重复4，直至队列为空；

```cpp
void Graph::BFS(Graph *graph) {
	std::queue<Vertex*> que;
	std::unordered_set<Vertex*> memo;
	memo.insert(graph->vertexs[0]);
	que.push(graph->vertexs[0]);
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
```



### 2 深度优先遍历 DFS

1. 使用栈，先进后出；
2. 使用哈希表记录已经访问过的节点，防止成环；
3. 随意选择一个节点开始，将该节点压入队列，并使用哈希表记录；
4. 获取栈顶元素，处理节点信息，并将与其相连的其中**一个**不在哈希表记录中的节点压入栈中（找到一个就行不能一次性全部压栈），并使用哈希表记录，如果已经没有不在记录中的节点，栈顶元素出栈；
5. 重复4，直至栈空；

```cpp
void Graph::DFS(Graph *graph) {
	std::stack<Vertex*> stk;
	std::unordered_set<Vertex*> memo;
	memo.insert(graph->vertexs[0]);
	stk.push(graph->vertexs[0]);
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
```



### 3 拓扑排序

1. 一个哈希表，记录节点与入度；
2. 一个入度为0的队列；
3. 遍历节点，记录在哈希表，并将初始入度为0的节点加入队列；
4. 弹出队列首元素，加入结果集合，并把该元素所有可达节点的入度-1，将此时入度为0的节点加入队列；
5. 重复4，直至队列为空；

```cpp
std::vector<Vertex*> Graph::topologicalSort(Graph *graph) {
	std::vector<Vertex*> res;
	std::unordered_map<Vertex*, int> in_map;
	std::queue<Vertex*> zero_in_queue;
	for (auto i_ver : graph->vertexs) {
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
```



### 4 Kruskal-最小生成树 

1. 再kruskal中，首先认为每一个点是一个集合；
2. 将所有的边加入一个小根堆中；
3. 取出堆顶元素，即为当前最小的边，如果边的两个顶点不在同一集合中（即没有形成环），则可以加入结果集，反之跳过；
4. 重复3，直至栈空，最后返回结果集；

```cpp
class UnionSet {
public:
	void unionSet(int a, int b) {
		int a_p = findParent(a);
		int b_p = findParent(b);
		arr[b_p] = a_p;
	}

	int isSameSet(int a, int b) {
		return findParent(a) == findParent(b);
	}

	int findParent(int cur) {
		while(cur != arr[cur])
			cur = arr[cur];
		return cur;
	}

	UnionSet(int len) : _len(len) {
		arr = new int[len+1];
		for (int i = 0; i <= len; i++) {
			arr[i] = i;
		}
	}
private:
	int _len;
	int *arr;
};

std::vector<Edge*> Graph::kruskal(Graph *graph) {
	UnionSet *union_set = new UnionSet(graph->vertexs_map.size());
	std::vector<Edge*> res;
	auto cmp = [](Edge *left, Edge *right) {
		return (left->weight > left->weight) - (left->weight < left->weight);
	};
	std::priority_queue<Edge*, std::vector<Edge*>, decltype(cmp)> small_heap(cmp);
	for (auto edge : graph->edges) {
		small_heap.push(edge);
	}
	while (!small_heap.empty()) {
		Edge *edge = small_heap.top();
		small_heap.pop();
		if (!union_set->isSameSet(edge->from, edge->to)) {
			res.push_back(edge);
			union_set->unionSet(edge->from, edge->to);
		}
	}
	return res;
}
```

#### 并查集

- 集合合并；
- 是否在一个集合的判断；

### 5 Prim-最小生成树 

1. 设定一个集合，从点集中任选一个点加入集合，将其边加入优先级队列中（小根堆）；
2. 从其边中选择权值最小的（且不成环）加入结果数组，并将连接的点加入集合，将其边加入优先级队列；

3. 重复2，直至没有节点可选；
4. 将结果数组返回；

```cpp
std::vector<Edge*> Graph::prim(Graph *graph) {
	std::vector<Edge*> res;
	std::unordered_set<Vertex*> memo;
	auto cmp = [](Edge *left, Edge *right) { 
		return (left->weight > right->weight) - (left->weight < right->weight);
	};
	std::priority_queue<Edge*, std::vector<Edge*>, decltype(cmp)> small_heap(cmp);
	
	for (auto i_ver : graph->vertexs) {
		Vertex *ver = i_ver.second;
		if(memo.find(ver) == memo.end()) {
			memo.insert(ver);
			for (auto edge : ver->edges) {
				small_heap.push(edge);
			}
			while (!small_heap.empty()) {
				Edge *min_edge = small_heap.top();
				small_heap.pop();
				Vertex *from = graph->vertexs[min_edge->from];
				Vertex *to = graph->vertexs[min_edge->to];
				if (memo.find(to) == memo.end()) {
					res.push_back(min_edge);
					memo.insert(to);
					for (auto edge : to->edges) {
						small_heap.push(edge);
					}
				}
			}
		}
	}
	return res;
}
```



### 6 Dijkstra 算法-最短路径

对于给定起点v，计算他到其他所有点的最小距离。

这个算法，会根据路径递增的顺序产生最短路径：

1. 建立一张所有节点的map，值表示从起点v到自己的总权值；
2. 初始为从起点v直接到当前节点的权值，自己为0，不可直接到为无穷（特殊符号或者最大值）；
3. 选择离起点最近且没有被选过的节点，通过该节点延伸出的边，依次更新对应节点的最小权值；
4. 重复3，直到没有未被选过的点；

Notes：不能够有和为负数的环，否则或一直循环，将值刷为负数。

```cpp
Vertex* findMinDistanceVertex(std::unordered_map<Vertex*, int> &shortest_map, std::unordered_set<Vertex*> &memo) {
	int min = INT_MAX;
	Vertex *min_ver = nullptr;
	for (auto ver_i : shortest_map) {
		if (ver_i.second < min && memo.find(ver_i.first) == memo.end()) {
			min = ver_i.second;
			min_ver = ver_i.first;
		}
	}
	memo.insert(min_ver);
	return min_ver;
}

std::vector<int> Graph::dijkstra(Graph *graph, Vertex *v0) {
	std::unordered_set<Vertex*> memo;
	std::unordered_map<Vertex*, int> shortest_map;
	for (auto ver : graph->vertexs_map) {
		shortest_map.insert({ ver.second, INT_MAX });
	}
	shortest_map[v0] = 0;
	Vertex *min_ver = v0;
	while (min_ver != nullptr) {
		for (auto next : min_ver->edges) {
			int val = next->weight + shortest_map[min_ver];
			Vertex *to = graph->vertexs_map[next->to];
			if (val < shortest_map[to]) {
				shortest_map[to] = val;
			}
		}
	}
}
```

#### 优化

自定义堆结构，可以在某些节点权值改变时，调整堆结构。
