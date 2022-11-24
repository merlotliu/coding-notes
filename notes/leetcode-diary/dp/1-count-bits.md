---
title: Count Bits
date: 2022-11-24
updated: 2022-11-24
tags: 
categories: 
comments: true
---

# 剑指 Offer II 003. 前 n 个数字二进制中 1 的个数

[剑指 Offer II 003. 前 n 个数字二进制中 1 的个数 - 力扣（Leetcode）](https://leetcode.cn/problems/w3tCBm/description/)

给定一个非负整数 `n` ，请计算 `0` 到 `n` 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。

## 题解

方法1：最高有效位（2的倍数，需要一个变量 highbit 记录）：highbit（小于等于 x 的2的倍数的最大值），x 位置的值一定是等于 x - highbit 的 1 的个数 + 1；

方法2：最低有效位，偶数和其一半的值相同，奇数与其一半的值 + 1 ，(x >> 1) 的操作会将第 0 位的 1 或 0 去掉，如果时偶数则没有减少 1，如果是奇数，减少了一个 1。

方法3：最低设置位，y = (x & (x - 1)) 操作可以将左右侧的 1 设置为 0，这样 y 的值一定是小于 x 的，而小于 x 的值的 1 的个数我们已经知道，再加上 1，就是 x 的 1 的个数。

## Reference 

1. 
