---
title: {{ title }}
date: {{ date }}
updated: {{ date }}
tags: 
categories: 
comments: true
---

# 单调栈

对于一个存放整形数据的栈，单调栈从栈底到栈顶只能是从小到大，或者从大到小。

例1：求一个**无重复**数据的数组中，每个位置左边和右边离他最近的比他大的值。

解：

- 维护一个从栈底到栈顶递减的单调栈（即数字大的在下面，数字小的在上面）；
- 如果当前数 num，大于栈顶元素，栈顶元素弹栈，生成**栈顶元素**信息：右边最近（num），左边最近（当前栈顶元素，如果弹栈后栈为空，则左边没有比他大的），然后将当前数入栈；
- 当前数小于栈顶元素则入栈；
- 最后如果遍历到数组末尾，但栈不为空，依次弹出栈内元素，栈内元素：右边（无），左边（原来在栈中的下一个元素）；

此外，对于有重复元素的情况下，可以在栈内存放可变的结构，如链表，然后把相同的数的下标用链表连接。

## Leetcode 练习

### 中等

[739. 每日温度 - 力扣（Leetcode）](https://leetcode.cn/problems/daily-temperatures/)

[496. 下一个更大元素 I - 力扣（Leetcode）](https://leetcode.cn/problems/next-greater-element-i/description/)

[503. 下一个更大元素 II - 力扣（Leetcode）](https://leetcode.cn/problems/next-greater-element-ii/description/)

### 困难

这两道题的暴力解法还是挺好想的，O(N)解法有些麻烦。

[42. 接雨水 - 力扣（Leetcode）](https://leetcode.cn/problems/trapping-rain-water/description/)

[84. 柱状图中最大的矩形 - 力扣（Leetcode）](https://leetcode.cn/problems/largest-rectangle-in-histogram/description/)

## Reference 

1. 
