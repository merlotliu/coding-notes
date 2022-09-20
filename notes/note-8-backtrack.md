# 回溯算法

回溯算法，即为暴力穷举。

暴力递归就是尝试

1. 把问题转化为规模缩小了的同类问题的子问题;
2. 有明确的不需要继续进行递归的条件(base case);
3. 有当得到了子问题的结果之后的决策过程;
4. 不记录每一个子问题的解；

对于一个问题里面的某个小决策，会有做与不做两个选择。

## 经典题型

### 1 汉诺塔问题

> 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
> (1) 每次只能移动一个盘子;
> (2) 盘子只能从柱子顶端滑出移到下一根柱子;
> (3) 盘子只能叠在比它大的盘子上。

打印n层汉诺塔从最左边移动到最右边的全部过程。

- 仅有一个圆盘时，可以直接从左移动到右；
- 2个时，先把上面的移到中间，再把下面的移动到右边，最后把上面再移动到右边；
- 3个，先把上面两个移动到中间，再把下面的移动到右边，最后把上面的移动到右边；
- n个时，先把n-1个移动到中间，再把下面的移动到右边，最后把上面n-1个移动到右边；

- ... ... 
- 事实上，把下面的从左移到右就是只剩一个的时候；
- 而把n-1从左移动到中间，还是从中间移动到右边，最终又会被拆解为2个圆盘或1个的情况；
- 因为最底层圆盘仅需要移动一次。

```cpp
void recursion(int i, std::string from, std::string to, std::string other) {
	if (i == 1) {
		std::cout << i << " " << from << " -> " << to << std::endl;
		return;
	}
	recursion(i - 1, from, other, to); // move 1-(i-1) from -> other
	std::cout << i << " " << from << " -> " << to << std::endl; // move i from -> to
	recursion(i - 1, other, to, from); // move 1-(i-1) other - > from
}

void hanoi() {
	int n = 4;
	recursion(n, "left", "right", "mid");
}
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

对于长度为n的字符串而言，在i位置的情况：

- i为0：不能转化；
- i为1：两种方式，i或（i，i+1）；
- i为2：
  - i+1在[0, 6]：i或（i，i+1）；
  - i；
- i在[3, 9]：i；

到达末尾结算。

```cpp
int res = 0;
void backtrack(std::string &num, int i) {
	if ('0' == num[i]) {
		return;
	}
	if (i == num.size()) {
		res++;
	}
	if ('1' == num[i]) {
		backtrack(num, i + 1);
		backtrack(num, i + 2);
	}
	if ('2' == num[i]) {
		backtrack(num, i + 1);
		if (i + 1 != num.size() && num[i + 1] >= '0' && num[i + 1] <= '6') {
			backtrack(num, i + 2);
		}
	}
	if (num[i] >= '3' && num[i] <= '9') {
		backtrack(num, i + 1);
	}
}

int numConvertToLetter(std::string &num) {
	backtrack(num, 0);
	return res;
}
```

不使用全局变量，让递归函数最后返回结果：

- 能产生多种情况的位置只有1和2，每次分叉的和为此次的返回值；
- 遇到0则返回0；
- 数组结束也返回0；

```

```



### 6 01背包问题

给定两个长度都为N的数组weights和values，weights[i]和values[i]分别代表i号物品的重量和价值。给定一个正数bag，表示一个载重bag的袋子，你装的物品不能超过这个重量。返回你能装下最多的价值是多少？

```cpp
#pragma once
#include <vector>
#include <algorithm>

int backtrack(std::vector<int> &weights, std::vector<int> &values, int bag, int i, int picked_weights, int picked_values) {
	if (picked_weights > bag) {
		return 0;
	}
	if(i == weights.size()) {
		return picked_values;
	}
	int unpicked = backtrack(weights, values, bag, i + 1, picked_weights, picked_values);
	int picked = backtrack(weights, values, bag, i + 1, picked_weights + weights[i], picked_values + values[i]);
	return std::max(unpicked, picked);
}

//std::vector<int> weights = { 2, 4, 5, 8, 10 };
//std::vector<int> values = { 4, 2, 1, 4, 3 };
int getMaxVal(std::vector<int> &weights, std::vector<int> &values, int bag) {
	return backtrack(weights, values, bag, 0, 0, 0);
}
```

完整的递归树如下：

```shell
.
├── n_0_0_0
│?? ├── n_1_0_0
│?? │?? ├── n_2_0_0
│?? │?? │?? ├── n_3_0_0
│?? │?? │?? │?? ├── n_4_0_0
│?? │?? │?? │?? └── p_4_10_3
│?? │?? │?? └── p_3_8_4
│?? │?? │??     ├── n_4_0_0
│?? │?? │??     └── p_4_8_3
│?? │?? └── p_2_5_1
│?? │??     ├── n_3_0_0
│?? │??     │?? ├── n_4_0_0
│?? │??     │?? └── p_4_10_3
│?? │??     └── p_3_8_4
│?? │??         ├── n_4_0_0
│?? │??         └── p_4_8_3
│?? └── p_1_4_2
│??     ├── n_2_0_0
│??     │?? ├── n_3_0_0
│??     │?? │?? ├── n_4_0_0
│??     │?? │?? └── p_4_10_3
│??     │?? └── p_3_8_4
│??     │??     ├── n_4_0_0
│??     │??     └── p_4_8_3
│??     └── p_2_5_1
│??         ├── n_3_0_0
│??         │?? ├── n_4_0_0
│??         │?? └── p_4_10_3
│??         └── p_3_8_4
│??             ├── n_4_0_0
│??             └── p_4_8_3
└── p_0_2_4
    ├── n_1_0_0
    │?? ├── n_2_0_0
    │?? │?? ├── n_3_0_0
    │?? │?? │?? ├── n_4_0_0
    │?? │?? │?? └── p_4_10_3
    │?? │?? └── p_3_8_4
    │?? │??     ├── n_4_0_0
    │?? │??     └── p_4_8_3
    │?? └── p_2_5_1
    │??     ├── n_3_0_0
    │??     │?? ├── n_4_0_0
    │??     │?? └── p_4_10_3
    │??     └── p_3_8_4
    │??         ├── n_4_0_0
    │??         └── p_4_8_3
    └── p_1_4_2
        ├── n_2_0_0
        │?? ├── n_3_0_0
        │?? │?? ├── n_4_0_0
        │?? │?? └── p_4_10_3
        │?? └── p_3_8_4
        │??     ├── n_4_0_0
        │??     └── p_4_8_3
        └── p_2_5_1
            ├── n_3_0_0
            │?? ├── n_4_0_0
            │?? └── p_4_10_3
            └── p_3_8_4
                ├── n_4_0_0
                └── p_4_8_3
```



### 7 获胜者

给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走每张纸牌，规定玩家A先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家A和玩家B都绝顶聪明。请返回最后获胜者的分数。

【举例】arr=[1,2,100,4]。

开始时，玩家A只能拿走1或4。如果开始时玩家A拿走1，则排列变为[2,100,4]，接下来玩家B可以拿走2或4，然后继续轮到玩家A...如果开始时玩家A拿走4，则排列变为[1,2,100]，接下来玩家B可以拿走1或100，然后继续轮到玩家A...

玩家A作为绝顶聪明的人不会先拿4，因为拿4之后，玩家B将拿走100。所以玩家A会先拿1，让排列变为[2,100,4]，接下来玩家B不管怎么选，100都会被玩家A拿走。玩家A会获胜，分数为101。所以返回101。

arr=[1,100,2]。

开始时，玩家A不管拿1还是2，玩家B作为绝顶聪明的人，都会把100拿走。玩家B会获胜，分数为100。所以返回100。



对于其中**一个玩家**来说：

- 先手：一定会选择最有利的决策使得收益最大化，而使得对手的收益最低。

- 后手：从另外一个玩家选择之后，收益降低的选择下，保证自己的收益最大化。

- base case：剩下最后一张牌：先手获取全部收益，后手为0；

```cpp
/* 这里的先后手都是相对于一个人而言 */
int firstPick(std::vector<int> &nums, int l, int r);
int secondPick(std::vector<int> &nums, int l, int r);

int firstPick(std::vector<int> &nums, int l, int r) {
	if (l == r) return nums[l];
	int left = secondPick(nums, l + 1, r) + nums[l];
	int right = secondPick(nums, l, r - 1) + nums[r];
	return std::max(left, right);
}

int secondPick(std::vector<int> &nums, int l, int r) {
	if (l == r) return 0;
	return std::min(firstPick(nums, l + 1, r), firstPick(nums, l, r - 1));
}

int winnerScore(std::vector<int> &nums) {
	return std::max(firstPick(nums, 0, nums.size() - 1), secondPick(nums, 0, nums.size() - 1));
}
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



## LeetCode & 代码随想录

### 1 组合

[77. 组合 - 力扣（LeetCode）](https://leetcode.cn/problems/combinations/)

base case : i > k 將當前選取的内容放入結果數組

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, int idx, vector<int> &picked) {
        if(picked.size() == k) {
            res.push_back(picked);
            return ;
        }
        // selcted list
        // idx : index of array [1 ... n]
        for(int i = idx; i <= n; i++) {
            picked.push_back(i); // picked
            backtrack(n, k, i + 1, picked);
            picked.pop_back(); // unpicked
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> picked;
        backtrack(n, k, 1, picked);
        return res;
    }
};
```

#### 剪枝

设想以下情况，n=4，k=1时的递归树？

可以得知，在第一层for循环中，从1往后的分支都是多余的。为什么是多余的？因为元素个数已经够了。

我们需要的元素个数是k，当前已经有的元素为size，则k-size表示仍需要的个数，所以结束的位置应该为下一次能保证把选择填满的位置。所以，n-(k-size)+1是本轮的最后一个位置，這個+1可以通過舉例子確定。比如n=5，k=3的情況下，在第一輪size=0時，5-(3-0)+1=3，從3往後，還有4、5。

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, int idx, vector<int> &picked) {
        if(picked.size() == k) {
            res.push_back(picked);
            return ;
        }
        // selcted list
        // idx : index of array [1 ... n]
        for(int i = idx; i <= n - (k - picked.size()) + 1; i++) {
            picked.push_back(i); // picked
            backtrack(n, k, i + 1, picked);
            picked.pop_back(); // unpicked
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> picked;
        backtrack(n, k, 1, picked);
        return res;
    }
};
```

### 2 组合总和

[216. 组合总和 III - 力扣（LeetCode）](https://leetcode.cn/problems/combination-sum-iii/)

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int k, int n, int idx, vector<int> &picked) {
        // base case
        if(k == picked.size()) {
            if(n == 0) {
                res.push_back(picked);
            }
            return ;
        }
        // selected list
        for(int i = idx; i <= 9; i++) {
            picked.push_back(i);
            backtrack(k, n - i, i + 1, picked);
            picked.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> picked;
        backtrack(k, n, 1, picked);
        return res;
    }
};
```

#### 剪枝

选择的总和已经大于n的话，则没必要继续遍历了。

```cpp
		// cut off
        if(n < 0) {
            return;
        }
```

