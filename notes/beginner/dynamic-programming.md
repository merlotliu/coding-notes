---
title: Dynamic Programming
date: 2022-12-05
updated: 2022-12-05
tags: 
categories: 
comments: true
---

# Dynamic Programming

##### tips

- 对于 dp 问题，必须清楚 dp 数组中每个位置的含义；
- 可以将 dp 数组打印出来，方便排查出错；

## 0-1 背包

给定两个数组重量 **weight** 和价值 **value** ，对于最大承重为 **maxWeight** 的背包，如何选取物品以获取最大价值？输出最大值。

示例：

maxWeight 最大承重为 4 的情况下，选取以下物品：

| 重量（weight） | 价值（value） |
| :------------: | :-----------: |
|       1        |       5       |
|       3        |       8       |
|       4        |      10       |

输出：13；

解释：选取重量为 1 价值为 5 和 重量为 3 价值为 8 的物品。

### 二维 dp 数组01背包

#### 1 dp 数组及下标含义

dp\[i][j] 表示最大重量为 j 的情况下，从 0 - i 的物品中，能够获取的最大总价值。

#### 2 dp 数组转移方程

在 dp\[i][j] 的位置，如果：

- **不**选取当前物品 i ，则 dp\[i][j] = dp\[i-1][j] 的值；
- 选取当前物品 i，则 dp\[i][j] = dp\[i-1][j - weight[i]] + value[i]，因为获取到了当前物品 i 的价值，同时也获取到其重量，那么前面能够获取的最大重量应该是 **当前最大重量 - 当前物品重量**。

值得注意的是，j - weight[i] 的值一定是正数，如果为负数，即当前物品的重量大于当前最大承重，那么背包一定是放不下的，只能够获取不选择当前物品 i 的值。

**如果两种方案都可以选择的情况下，则取最大值。**

#### 3 dp 数组初始化

> **关于初始化，一定要和dp数组的定义吻合，否则到递推公式的时候就会越来越乱**。

- 当前最大承重 j 为 0 时，一定是无法承载任何物品的，所以需要将 dp\[i][0] 均置为 0；
- 然后就是物品 0 的位置，因为 i = 0，所以不存在 i - 1 的值，将第 0 行中 [0, weight[0] - 1] 列的值都置为 0，将 [weight[0], maxWeight] 的位置均置为 weight[0] 即可。

```c++
/* weight 为重量数组 */
int dp[weight.size()][maxWeight + 1]{0};
for(int j = weight[0]; j < maxWeight; j++) dp[0][j] = weight[0];
```

#### 4 确定遍历顺序

##### 先遍历物品，再遍历重量

```c++
for(int i = 1; i < weight.size(); i++) { // 遍历物品
    for(int j = 0; j <= maxWeight; j++) { // 遍历背包容量
        if (j < weight[i]) dp[i][j] = dp[i - 1][j]; 
        else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
}
```

##### 先遍历重量，再遍历物品

```c++
for(int j = 0; j <= maxWeight; j++) { // 遍历背包容量
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        if (j < weight[i]) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
}
```

#### 完整代码

```c++
int bag01(vector<int>& weight, vector<int>& value, int maxWeight) {
    /* weight 为重量数组 */
    int dp[weight.size()][maxWeight]{0};
    for(int j = weight[0]; j < maxWeight; j++) dp[0][j] = value[0];
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= maxWeight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j]; 
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
}
```

### 一维 dp 数组01背包

一维 dp 数组实际上，是二维数组中 i 行覆盖 i - 1 行的结果。

#### 1 dp 数组及下标含义

dp[j] 表示当前最大重量为 j 的背包所能达到的最大价值。

#### 2 dp 数组转移方程

dp[j] = max(dp[j], dp[j - weight[i]] + value[i])

#### 3 dp 数组初始化

> **关于初始化，一定要和dp数组的定义吻合，否则到递推公式的时候就会越来越乱**。

在给定价值为 0 的情况下，将所有位置初始化为 0 即可。

#### 4 确定遍历顺序

- 遍历物品数组表示每次选取一个物品；
- 遍历最大背包重量，**注意需要逆序遍历**，因为在转移方程中 j 位置的值依赖 j - weight[i] 位置的值，而该值一定是小于 j ，所以在更新完后面的值，才能够放心的将前面的值覆盖；

```c++
for(int i = 1; i < weight.size(); i++) { // 遍历物品
    for(int j = maxWeight; j >= 0 && j >= weight[i]; j--) { // 遍历背包容量 
		dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

####  完整代码

```c++
int bag01(vector<int>& weight, vector<int>& value, int maxWeight) {
    /* weight 为重量数组 */
    /* 值得注意的是dp数组的长度为最大重量+1 */
    int dp[weight.size()][maxWeight + 1]{0};
    for(int i = 1; i < weight.size(); i++) { // 遍历物品    
        for(int j = maxWeight; j >= 0 && j >= weight[i]; j--) { // 遍历背包容量         
        	dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);    
        }
    }
}
```

## Reference 

1. [代码随想录 (programmercarl.com)](https://www.programmercarl.com/背包理论基础01背包-1.html#二维dp数组01背包)
