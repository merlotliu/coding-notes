# 回溯算法

回溯算法，即为暴力穷举。

暴力递归就是尝试

1. 把问题转化为规模缩小了的同类问题的子问题;
2. 有明确的不需要继续进行递归的条件(basecase);
3. 有当得到了子问题的结果之后的决策过程;
4. 不记录每一个子问题的解；

## 经典题型

### 1 汉诺塔问题

> 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
> (1) 每次只能移动一个盘子;
> (2) 盘子只能从柱子顶端滑出移到下一根柱子;
> (3) 盘子只能叠在比它大的盘子上。

打印n层汉诺塔从最左边移动到最右边的全部过程。

```

```



### 2 字符串的全部子序列

打印一个字符串的全部子序列，包括空字符串。

```cpp
// str 全部字符集合
// i 当前在哪一层
void backtrack(std::string &str, int i, std::string memo) {
	if (i >= str.size()) {
		std::cout << memo << " ";
		return;
	}
	// 不要
	backtrack(str, i + 1, memo);
	
	// 要
	memo.push_back(str[i]);
	backtrack(str, i + 1, memo);
}

void printAllSubsequence(std::string &str) {
	backtrack(str, 0, "");
	std::cout << std::endl;
}
```



### 3 字符串的全排列

打印一个字符串的全部排列，要求不要出现重复的排列。

打印一个字符串的全部排列（**非去重**）

```cpp
/* alt : 选择列表
 * selected : 已选择列表
 * i : 第几层
 * base case : i >= alt.size() 打印 selected
 */
void backtrack(std::string &alt, std::string &picked, int i) {
	// base case & end condition
	if (i >= alt.size()) {
		std::cout << picked << std::endl;
		return;
	}
	// for( one : alternative)
	for (auto ch : alt) {
		picked.push_back(ch); // picked
		backtrack(alt, picked, i + 1);
		picked.pop_back(); // unpicked
	}
}

void printAllPermutation(std::string &str) {
	std::string picked;
	backtrack(str, picked, 0);
}
```

去重剪枝的全排列

```cpp
/* alt : 选择列表
 * selected : 已选择列表
 * i : 第几层
 * base case : i >= alt.size() 打印 selected
 */
void backtrack(std::string &alt, std::string &picked, int i, std::unordered_set<char> &memo) {
	// base case & end condition
	if (i >= alt.size()) {
		std::cout << picked << std::endl;
		return;
	}
	// for( one : alternative)
	for (auto ch : alt) {
		if(memo.find(ch) == memo.end()) {
			picked.push_back(ch); // picked
			memo.insert(ch);
			backtrack(alt, picked, i + 1, memo);
			memo.erase(ch);
			picked.pop_back(); // unpicked
		}
	}
}

void printAllPermutation(std::string &str) {
	std::string picked;
	std::unordered_set<char> memo;
	backtrack(str, picked, 0, memo);
}
```



### 4 逆序给定栈

给你一个栈，请你逆序这个栈，不能申请额外的数据结构，只能使用递归函数。如何实现?

```cpp
#pragma once
#include <stack>
#include <iostream>

/* 
 * base case : stack is empty
 * 先出栈元素，如果为null，返回一直该栈底元素，不为空继续递归出栈
 */
int getStackBottom(std::stack<int> &stk) {
	int cur = stk.top();
	stk.pop();
	if (stk.empty()) {
		return cur;
	}
	int bottom = getStackBottom(stk);
	stk.push(cur);
	return bottom; 
}

/*
 * base case : stack is empty
 */
void backtrack(std::stack<int> &stk) {
	if (stk.empty()) {
		return;
	}
	int num = getStackBottom(stk);
	backtrack(stk);
	stk.push(num);
}

void reverseStack(std::stack<int> &stk) {
	backtrack(stk);
}

void printStack(std::stack<int> stk) {
	while (!stk.empty()) {
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;
}
```



### 5 数字与26字母的转化

规定1和A对应、2和B对应、3和C对应...那么一个数字字符串比如"111"，就可以转化为"AAA"、"KA"和"AK"。给定一个只有数字字符组成的字符串str，返回有多少种转化结果。

```

```



### 6 01背包问题

给定两个长度都为N的数组weights和values，weights[i]和values[i]分别代表i号物品的重量和价值。给定一个正数bag，表示一个载重bag的袋子，你装的物品不能超过这个重量。返回你能装下最多的价值是多少？

```

```



### 7 获胜者

给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走每张纸牌，规定玩家A先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家A和玩家B都绝顶聪明。请返回最后获胜者的分数。

【举例】arr=[1,2,100,4]。

开始时，玩家A只能拿走1或4。如果开始时玩家A拿走1，则排列变为[2,100,4]，接下来玩家B可以拿走2或4，然后继续轮到玩家A...如果开始时玩家A拿走4，则排列变为[1,2,100]，接下来玩家B可以拿走1或100，然后继续轮到玩家A...

玩家A作为绝顶聪明的人不会先拿4，因为拿4之后，玩家B将拿走100。所以玩家A会先拿1，让排列变为[2,100,4]，接下来玩家B不管怎么选，100都会被玩家A拿走。玩家A会获胜，分数为101。所以返回101。

arr=[1,100,2]。

开始时，玩家A不管拿1还是2，玩家B作为绝顶聪明的人，都会把100拿走。玩家B会获胜，分数为100。所以返回100。

```

```



### 8 n皇后

N皇后问题是指在N*N的棋盘上要摆N个皇后，要求任何两个皇后不同行、不同列，也不在同一条斜线上。

给定一个整数n，返回n皇后的摆法有多少种。n=1，返回1。

n=2或3，2皇后和3皇后问题无论怎么摆都不行，返回0。

n=8，返回92。

#### n皇后的摆法总数

```cpp
bool isValid(int row, int col, std::vector<std::vector<bool>> &board){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] && (j == col || (abs(row - i) == abs(col - j)))) {
				return false;
			}
		}
	}
	return true;
}

int backtrack(int level, int n, std::vector<std::vector<bool>> &board) {
	if (level >= n) {
		return 1;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (isValid(level, i, board)) {
			board[level][i] = 1;
			res += backtrack(level + 1, n, board);
			board[level][i] = 0;
		}
	}
	return res;
}

int totalNQueens(int n) {
	std::vector<std::vector<bool>> board(n, std::vector<bool>(n, 0));
	return backtrack(0, n, board);
}
```

##### 位运算优化常数时间

```cpp
int backtrack(int col_lim, int left_dia_lim, int right_dia_lim, int limit_range) {
	if (col_lim == limit_range) {
		return 1;
	}
	int res = 0;
	// calculate current all of possible position
	int pos = limit_range & (~(col_lim | left_dia_lim | right_dia_lim));
	while (pos != 0) {
		int most_right_one = pos & (~pos + 1); // get most right one
		pos -= most_right_one; // mark to limit
        // 下一个位置左斜线的限制就是当前左斜线限制或上当前选择的位置再左移一位
       	// 下一个位置右斜线的限制就是当前右斜线限制或上当前选择的位置再右移一位
		res += backtrack(col_lim | most_right_one,
			(left_dia_lim | most_right_one) << 1,
			(right_dia_lim | most_right_one) >> 1,
			limit_range);
	}
	return res;
}

int totalNQueensBit(int n) {
	return backtrack(0, 0, 0, (1 << n) - 1);
}
```

#### n皇后的所有摆法

```cpp
bool isValid(int row, int col, std::vector<std::string> &board) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == 'Q' && (j == col || (abs(row - i) == abs(col - j)))) {
				return false;
			}
		}
	}
	return true;
}

void backtrack(int level, int n, std::vector<std::string> &board, std::vector<std::vector<std::string>> &res) {
	if (level >= n) {
		res.push_back(board);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isValid(level, i, board)) {
			board[level][i] = 'Q';
			backtrack(level + 1, n, board, res);
			board[level][i] = '.';
		}
	}
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
	std::vector<std::string> board(n, std::string(n, '.'));
	std::vector<std::vector<std::string>> res;
	backtrack(0, n, board, res);
	return res;
}
```

