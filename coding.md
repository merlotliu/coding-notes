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

```
int getOnlyOddTimesNum(int *arr, int len) {
	int eor = 0;
	for (int i = 0; i < len; i++) {
		eor ^= arr[i];
	}
	return eor;
}
```



### 题型二

一组数中，有两个数出现了奇数次，其他所有数出现了偶数次，求这两个出现了奇数次的数。

#### 解法

- 首先，全部异或得到两个数a和b的异或结果eor；
- 对于eor，进行eor&(~eor+1)的操作，获得最右侧为1的位置，这一位表示，a和b不相同的其中一位。对所有这一位为1或不为1的数异或，得到的结果就是其中一个数，在与eor异或可得到另外一个数。

```
std::vector<int> getTwoOddTimesNum(int *arr, int len) {
	int eor = 0;
	for (int i = 0; i < len; i++) {
		eor ^= arr[i];
	}
	int opp_byte = eor & (~eor + 1);
	int a = 0;
	for (int i = 0; i < len; i++) {
		if ((opp_byte & arr[i]) == 0) {
			a ^= arr[i];
		}
	}
	int b = eor ^ a;
	return {a, b};
}
```



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





## 递归

递归的时间复杂度分析。

### Master公式

$$T(N)=a*T(N/b)+O(N^d)$$

其中，N为母问题的规模，a为子问题的次数，N/b为子问题的规模，O(N^d)为除去递归子问题以外其他部分的时间复杂度。

在知道a、b、d的值以后，通过以下3种情况可以知道该问题的时间复杂度：

- $$log_{b}a>d$$时，时间复杂度为$$O(N*log_{b}a)$$；
- $$log_{b}a=d$$时，时间复杂度为$$O(N^d*logN)$$；
- $$log_{b}a<d$$时，时间复杂度为$$O(N^d)$$。

### 示例

对于求解一个数组中的最大值的递归解法：

可以通过二分递归的方法，将找数组中的最大值拆解为找数组左半部分的最大值和数组右半部分的最大值，在从这两个最大值的中找到最大值。对于左半部分和右半部分仍然可以这么做，直到每一部分只剩下一个数（递归结束条件），剩下一个数自然这个数就是这一部分最大值，返回即可。

```c++
#pragma once
class GetMax {
public:
	static int getMax(int *arr, int len) {
		return getMax(arr, 0, len - 1);
	}

	static int getMax(int *arr, int l, int r) {
		// end condition
		if (l == r) {
			return arr[l];
		}
		// recursion
		int m = l + (r - l) >> 1; // prevent overflow
		int left_max = getMax(arr, l, m);
		int right_max = getMax(arr, m+1, r);
		return max(left_max, right_max);
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}
};
```

#### 分析

在这一问题中，总问题每次被拆解为2个子问题，则子问题的规模为总问题的1/2，即b=2，每一次子问题被计算2次，即a=2。除去子问题的递归，我们每次需要计算一次中间值m，比较一次大小，这些操作都是常数操作，故这一部分时间复杂度为O(1)，即d=0。

所以，$$log_{b}a=log_{2}2=1>d=0$$，即时间复杂度为$$O(N*log_{2}2)=O(N)$$。



## 归并排序

将数组分为左右两部分，分别对这两部分进行排序，排序完成后，合并两部分的结果。

实际上，不断的将数组进行拆解，拆解到每一部分只剩下一个数的时候，一定是有序的。

合并时，首先申请一个额外的数组，然后同时遍历并依次比较两个部分的内容，每次将数小的添加进辅助数组，直到其中一部分内容遍历完，将另外一个部分全部添加到辅助数组的末尾。最后将辅助数组的内容赋值到原数组的对应位置即可。

```c++
class MergeSort{
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		mergeSort(arr, 0, len - 1);
	}

	void mergeSort(int *arr, int l, int r) {
		if (l == r) {
			return;
		}
		int m = l + ( (r - l) >> 1 ); // >> 优先级低于 +，应该加括号
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
		return;
	}

	void merge(int *arr, int l, int m, int r) {
		int *help = new int[r - l + 1];
		int i = 0; 
		int p1 = l;
		int p2 = m+1;
		while (p1 <= m && p2 <= r) {
			help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
		}
		while (p1 <= m) {
			help[i++] = arr[p1++];
		}
		while (p2 <= r) {
			help[i++] = arr[p2++];
		}
		for (int j = l, i = 0; j <= r; ) { 
			arr[j++] = help[i++];
		}
		delete[] help;
		return;
	}
};
```

### 时间复杂度

时间复杂度O(nlogn)，空间复杂度O(n)



### 小和&逆序对

#### 小和问题

在一个数组中，每个数左边比当前数小的数累加起来，叫做这个数组的小和，求一个数组的小和。

例：[1, 3, 4, 2, 5] 1左边没有比1小的数；3左边比三小的数：1；4左边比4小的数：1, 3；2左边比2小的数：1；5左边比5小的数：1, 3, 4, 2；故小和：1+ 1+3 + 1+ 1 + 3 + 4 + 2=16

#### 逆序对问题

在一个数组中，左边的数比右边的数大，则两个数构成一个逆序对，请打印所有逆序对。

#### 解法

对于小和问题，我们发现，问题等价于，右边有几个数比当前数大则累加几次，结合归并排序，我们即可获得优于O(n^2)的解法。

对于合并部分的逻辑需要进行一些改动：

- 判断两部分大小的时候，如果相等，则不产生小和，并且先拷贝右侧内容；
- 如果左侧小于右侧，产生小和，右侧应该有右边界索引减去右侧当前指针索引下标再加1的数量，乘上当前左侧数，即为当前部分小和；例如：左侧为[1,3,4]，右侧为[2,5]时（合并时各部分一定是已经排好序的，这样才能确定后面有几个数比当前数大），对于1来说，右侧当前索引为0，边界索引为1，则小和为(1-0+1)*1=2；

```

```



## 荷兰国旗问题

给定一个数组arr，和一个数num，请将小于num的数放在数组的左边，等于数num的数放在数组的中间，大于num的数放在数组的右边。

要求：额外空间复杂度O(1)，时间复杂度O(N)。

### 解法

首先，考虑一个更为简单的场景，在这个数组arr中，仅把小于等于num的数放在数组的左边，大于num的数放在右边。

要求：额外空间复杂度O(1)，时间复杂度O(N)。

对于这一问题，定义小于等于num的区域为L，起始区域为(-1, l]，标记该区域的右边界的指针l初始为-1。

然后开始遍历数组，数组中i位置的数包含两种情况：

- i 位置数 <= num：指针l+1的位置与i位置数交换，i++，从而区域L向右拓展；
- i 位置数 > num：i++。

遍历完数组后，则问题解决：

```
void easyNetherlandFlag(int num, int *arr, int len) {
	if (arr == nullptr || len < 2) {
		return;
	}
	int l = -1;
	for (int i = 0; i < len; i++) {
		if (arr[i] <= num) {
			swap(arr, i, ++l);
		}
		std::cout << arr[i] << std::endl;
	}
	return;
}
```



接着，解决荷兰国旗问题。定义小于num的区域为L，标记区域L的右边界的指针l初始值为-1，定义大于num的区域为R，标记区域R的左边界的指针r的初始值为n（数组长度）。

遍历数组时，会有三种情况：

- i 位置数 < num：指针l+1的位置与i位置数交换，i++（因为换过来的值一定是小于或等于num的数），从而区域L 向右拓展；
- i 位置数 = num：i++；
- i 位置数 > num：指针r-1的位置与i位置数交换，i不变（因为换过来的值尚未判断），从而区域R 向左拓展；

直到i遇到r时结束，问题也就解决：

```
void netherlandFlag(int num, int *arr, int len) {
	if (arr == nullptr || len < 2) {
		return;
	}
	int l = -1;
	int r = len;
	for (int i = 0; i < r; ) {
		if (arr[i] < num) {
			swap(arr, i++, ++l);
		} else if (arr[i] > num) {
			swap(arr, i, --r);
		} else {
			i++;
		}
	}
	return;
}
```



## 快排

影响快排效率的最重要因素就是，划分值的选取，选取的好时间复杂度趋向于O(n*logn)，反之趋向于O(n^2)。

具体步骤：

- 选取划分值：
  - 选择最后一个数作为划分值；
  - 每次随机选择一个数作为划分值；
- 根据划分值，划分区域（在这一部分遍历时要从区域的左端开始而不是从0开始）：
  - 小于划分值的部分在最左侧；
  - 等于划分值的部分在中间；
  - 大于划分值的部分在最右侧；
- 细分子区域（递归）；

```c++
#pragma once
#include <random>
#include <time.h>
#include <iostream>

class QuickSort {
public:
	void sort(int *arr, int len) {
		if (arr == nullptr || len < 2) {
			return;
		}
		srand((unsigned int)time(nullptr));
		quickSort(arr, 0, len-1);
	}

private:
	void quickSort(int *arr, int L, int R) {
		// end condition
		if (L >= R) {
			return;
		}

		//int flag = arr[R]; // 2.0
		// random flag
		int flag = arr[(rand() % (R - L + 1)) + L]; // 3.0
		//std::cout << (R - L + 1) << " " << r << " " << flag << std::endl;
		// partition
		std::vector<int> bound = partition(flag, arr, L, R);
		// recursion
		quickSort(arr, L, bound[0]);
		quickSort(arr, bound[1], R);
	}

	std::vector<int> partition(int flag, int *arr, int L, int R) {
		// Notes: start from L, not 0
		int less = L - 1; 
		int more = R + 1;

		while (L < more) {
			if (arr[L] < flag) {
				swap(arr, L++, ++less);
			} else if (arr[L] > flag) {
				swap(arr, L, --more);
			} else {
				L++;
			}
		}
		return {less, more};
	}
};
```

### Notes

- 一定要特别注意边界条件；
- 每次遍历的的起始、终止条件；

### 时间复杂度

取决于选取的划分值

最好：O(n*logn) 最差：O(n^2) 

空间复杂度（主要用于记录划分值）：

最好：O(logn) 最差：O(n)



## 堆

本质是一颗完全二叉树，其结构为数组实现的完全二叉树结构。

> 完全二叉树《百度百科》
>
> 一棵深度为k的有n个结点的[二叉树](https://baike.baidu.com/item/二叉树/1602879?fromModule=lemma_inlink)，对树中的结点按从上至下、从左到右的顺序进行编号，如果编号为i（1≤i≤n）的结点与[满二叉树](https://baike.baidu.com/item/满二叉树/7773283?fromModule=lemma_inlink)中编号为i的结点在二叉树中的位置相同，则这棵二叉树称为完全二叉树。

> 满二叉树《百度百科》
>
> 一棵深度为k且有$$2^k-1$$个结点的二叉树称为满二叉树。

大根堆：每颗子树的顶点为最大值；

小根堆：每颗子树的顶点为最小值；

由于堆的底层结构为数组，所以每个数都有一个索引 index，通过这个索引，可以描述与其他位置的关系：

- (index * 2 + 1)表示其左孩子；
- (index * 2 + 2)表示其右孩子；
- ((index - 1) / 2)表示其父节点；

此外，会使用一个变量（如 len）记录堆的大小，在插入和删除数据时，更新该变量的值。这个值对应数组中的长度，数组中这一范围内的值为堆中值，之外的部分为堆外的区域。

### Heap Insert

对于已有的堆，将新的数字插入到堆中形成新的大根堆（或小根堆）的过程，称为heap insert。

对于大根堆的插入：

- 当前数据索引为 index，其父节点索引为 ((index - 1) / 2)。如果前者值大于其父节点值，则交换两者的值，并将 index 移动到父节点位置 ((index - 1) / 2)。

- 调整到什么时候停止？一种情况是 index 位置的值不大于其父节点值。另外一种情况是到达根节点为止。（实际上，因为代码中的使用((index - 1) / 2)计算父节点，所以当到达根节点时，((index - 1) / 2)=(-1/2)=0，判断条件不需要变动，此时计算出的父节点为他本身，他不大于它本身，自然就停下了）

```cpp
void heapInsert(int *arr, int index) {
	int parent = (index - 1) / 2;
	while (arr[index] > arr[parent]) {
		swap(arr, index, parent);
		index = parent;
	}
}
```



### Heapify



### 堆排序



### 优先级队列



## 比较器





## 桶排序





## 基数排序









