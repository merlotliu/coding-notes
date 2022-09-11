# 链表

## 链表解题技巧

- 额外的数据结构（哈希表）；
- 快慢指针；

## 反转链表

分别实现单向链表和双向链表的反转。

要求：长度为N的链表，时间复杂度为O(N)，额外空间复杂度为O(1)。

### 反转单向链表：

#### 方法1（使用栈，时：O(N)，空：O(N)）：

1. 第一次遍历将数据添加至栈中；
2. 定义一个空节点，tmp记录，cur指向该节点；
3. 栈不为空开始循环出栈：
   1. cur的next指向的栈顶元素；
   2. 栈顶元素出栈；
   3. cur移动到next的位置；
4. cur现在在最后一个位置，将其next赋值为nullptr；
5. cur指向tmp（空节点）的next位置，并删除tmp；
6. 返回cur（新的头节点）；

```cpp
LinkedNode* LinkedList::reverseWithStack(LinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	std::stack<LinkedNode*> stk;
	LinkedNode* cur = head;
	while (cur) {
		stk.push(cur);
		cur = cur->next;
	}
	LinkedNode* tmp = new LinkedNode();
	cur = tmp;
	while (!stk.empty()) {
		cur->next = stk.top();
		stk.pop();
		cur = cur->next;
	}
	cur->next = nullptr;
	cur = tmp->next;
	delete tmp;
	return cur;
}
```

#### 方法2（双指针，时：O(N)，空：O(1)）：

双指针解法：

1. 定义两个指针new_head，cur，初始new_head指向head，cur指向head的next；
2. cur不为nullptr则开始循环：
   1. head的next赋值为cur的next；
   2. cur的next赋值为new_head；
   3. new_head移动到cur；
   4. cur移动到head的next；
3. 最后返回new_head即可。

```cpp
LinkedNode* LinkedList::reverse(LinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	LinkedNode *new_head = head;
	LinkedNode *cur = head->next;
	while (cur) {
		head->next = cur->next;
		cur->next = new_head;
		new_head = cur;
		cur = head->next;
	}
	return new_head;
}
```

### 反转双链表

```cpp
DoubleLinkedNode* LinkedList::reverseDoubleLinkedList(DoubleLinkedNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	DoubleLinkedNode *pre = head;
	DoubleLinkedNode *cur = head->next;
	while (cur) {
		DoubleLinkedNode *tmp = pre->next;
		pre->next = pre->pre;
		pre->pre = tmp;
		
		pre = cur;
		cur = cur->next;
	}
	return pre;
} 
```



### 打印两个链表的公共部分

两个链表有序

要求：长度为N的链表，时间复杂度为O(N)，额外空间复杂度为O(1)。

两个链表只要有一个为空或到达空，则后续无需在遍历，直接返回。

使用head1和head2遍历两个链表：

- head1->val == head2->val：打印数据，两个指针同时向后移动一步；
- head1->val < head2->val：head1指针同时向后移动一步；
- head1->val > head2->val：head2指针同时向后移动一步；

```cpp
void LinkedList::printCommonPart(LinkedNode *head1, LinkedNode *head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return;
	}
	while (head1 && head2) {
		if (head1->val == head2->val) {
			std::cout << head1->val << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head1->val < head2->val) {
			head1 = head1->next;
		}
		else {
			head2 = head2->next;
		}
	}
	std::cout << std::endl;
	return;
}
```



## 判断链表是否回文

要求：时间辅助度O(N)，空间复杂度O(1)

### 方法1：栈（不考虑空间复杂度）

1. 遍历一次链表，将节点地址依次压栈；
2. 再此遍历链表，每遍历一个节点，与栈顶元素比对，相等则栈顶元素出栈。
3. 如果直到链表结束和栈空元素都相等，则为回文，中间只要有一个不相等，返回false。

```

```



# 面试&笔试

在面试和笔试中，对算法的要求应有所区分。

在笔试中，题量多时间少，我们要尽量采取写出容易想到并且时间复杂度符合要求的算法，通常可以以空间换时间。

而在面试中的题，通常难度更小，为了给面试官留下深刻的影响，应尽量写出低时间复杂度，低空间复杂度，能体现代码水平的代码。