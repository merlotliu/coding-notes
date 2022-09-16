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

1. 使用哈希表记录已经访问过的节点，防止成环；
2. 遍历节点列表，找到入度为0且未被记录的节点，加入结果数组，哈希表记录，将与他所关联的边的终点的入度--；
3. 重复2，直至没有未记录节点；

```cpp
Vertex* getZeroInVertex(Graph *graph, std::unordered_set<Vertex*> &memo) {
	std::unordered_map<int, Vertex*>::iterator iter = graph->vertexs.begin();
	for (auto i_vertex : graph->vertexs) {
		Vertex* ver = i_vertex.second;
		if (0 == ver->in && memo.find(ver) == memo.end()) {
			memo.insert(ver);
			for (auto next : ver->nexts) {
				next->in--;
			}
			return ver;
		}
	}
	return nullptr;
}

std::vector<Vertex*> Graph::topologicalSort(Graph *graph) {
	std::vector<Vertex*> res;
	std::unordered_set<Vertex*> memo;
	Vertex* ver = getZeroInVertex(graph, memo);
	while (ver != nullptr) {
		res.push_back(ver);
		ver = getZeroInVertex(graph, memo);
	}
	return res;
}
```



### 4 Kruskal-最小生成树 



### 5 Prim-最小生成树 



### 6 Dijstra 算法-最短路径





