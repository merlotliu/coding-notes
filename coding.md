# 算法&数据结构

## 时间复杂度

1. 常数操作：一个操作如果与样本数据量没有关系，每次都是固定时间内完成的操作；
2. 去掉低阶项，忽略高阶项系数，如果为f(N)，则时间复杂度为O(f(N))；
3. 多个算法理论值相同时（如都为O(N)），比较实际运行时间，即“常数项时间”；
4. O 表示最差情况下的时间复杂度（通常所说的时间复杂都也是指这个）；

## 选择排序

对于一组共有 N 个数的数组，共进行 N-1 轮移动：

- 第一轮：1~N中找到最小的数，移动到第1个位置；
- 第二轮：2~N中找到最小的数，移动到第2个位置；
- 第N-1轮：N-1~N中找到最小的数，移动到第N-1个位置；

### 时间复杂度

$$O(n^2)$$

### 代码

```c++
#pragma once

class Code01SelectionSort {
public:
	void static selectionSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return ;
		}
		for (int i = 0; i < len - 1; i++) {
			int min_idx = i;
			for (int j = i + 1; j < len; j++) {
				if (arr[min_idx] > arr[j]) {
					min_idx = j;
				}
			}
			if (min_idx != i) {
				swap(arr, i, min_idx);
			}
		}
		return ;
	}

	void static swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};
```



## 冒泡排序

对于一组共有 N 个数的数组，共进行 N-1 轮移动：

- 第一轮：12比较将大数换到2，23比较将大数换到3，直到 N-1 和 N 比较将本轮最大数换到 N 位置；
- 第二轮：直到本轮最大的数放置到 N-1；
- 第 N-1 轮：将12中最大的数放到 2 。

### 时间复杂度

$$O(n^2)$$

### 代码

```
#pragma once
class Code02BubbleSort {
public:
	void static bubbleSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}

		for (int j = len - 1; j > 0; j--) {
			for (int i = 0; i < j; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr, i, i + 1);
				}
			}
		}
		return;
	}

	void static swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};
```



## 异或运算

- 相同为0，不同为1；
- 无进位相加；

性质：

- 0 ^ N = N, N ^ N = 0;
- 满足交换律和结合律；

### 交换两个数不引入新变量

```
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b; // b = a ^ b ^ b = a
	a = a ^ b; // a = a ^ b ^ a = b
}
```

#### Notes

- 两数值可以一样，但内存一样，异或会变成0；

### 题型一

一组数中，有一个数出现了奇数次，其他所有数出现了偶数次，求该出现了奇数次的数。

#### 解法

将这组数从头异或到尾，得到的结果就是该数。

### 题型二

一组数中，有两个数出现了奇数次，其他所有数出现了偶数次，求这两个出现了奇数次的数。

#### 解法

- 首先，全部异或得到两个数a和b的异或结果eor；
- 对于eor，进行eor&(~eor+1)的操作，获得最右侧为1的位置，这一位表示，a和b不相同的其中一位。对所有这一位为1或不为1的数异或，得到的结果就是其中一个数，在与eor异或可得到另外一个数。

## 插入排序

对于一组共有 N 个数的数组，共进行 N-1 轮移动。每一轮从当前位置向前看，依次比较前面的数，比前面的数小则交换，比前面的数大或者相等或前面没有数则停止，此时该部分的数已经有序：

- 第一轮：从第2个位置往前看，调整为有序；
- 第二轮：从第3个位置往前看，调整为有序

类似，打扑克抓牌顺牌的过程。

### 时间复杂度

数据状况会影响插入排序的时间复杂度

$$O(n^2)$$表示最差状况下的时间复杂度

### 代码

```
#pragma once
class Code03InsertionSort {
public:
	void static insertionSort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		for (int i = 1; i < len; i++) {
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
				swap(arr, j - 1, j);
			}
		}
	}

	void static swap(int *arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};

```



## 二分法

### 有序数组中某数是否存在

#### 时间复杂度

$$log_{2}n$$

### 有序数组中大于等于某数最左侧的位置

#### 解法

求大于等于时：记录大于等于的位置并保持更新；

求小于等于时：记录小于等于的位置并保持更新；

### 局部最小问题

无序数组，任何两个相邻数一定不相等，求一个局部最小（小于他的两个邻居）。



## 对数器

1. 有一个需要测的方法a，和一个暴力解法方法b；
2. 通过对数器测试方法a的正确性；
3. 小样本修改a、b保证正确性，大样本测试确定真的正确； 