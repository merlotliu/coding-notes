# 二叉树

## 基础

### 节点结构

含有三個成员变量，一个值域，两个指针域。

```cpp
class TreeNode {
public:
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
public:
	int val;
	TreeNode *left;
    TreeNode *right;
};
```

### 二叉树遍历

#### 递归

##### 递归序

```cpp
void recursion(TreeNode *root) {
	//[1]
	if(root == nullptr) {
		return;
	}
	//![1]
	//[2]
	recursion(root->left);
	//![2]
    //[3]
	recursion(root->right);
	//![3]
}
```

对于这一段递归代码，每个节点将会访问3次（每次的访问范围已经标注）。

对于使用以上递归代码遍历如下的二叉树：

​		1

​	2 	   3

4	5	6	7

访问的完整路径：1, 2, 4, 4, 4, 2, 5, 5, 5, 2, 1, 3, 6, 6, 6, 3, 7, 7, 7, 3, 1。

知道这一点之后，通过控制处理数据（如：打印）的在上面3个位置范围的中的一个，即可完成二叉树的前中后序遍历。

##### 前中后序遍历

```cpp
void BinaryTree::preorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	std::cout << root->val << " ";
	preorderTraversalRecursion(root->left);
	preorderTraversalRecursion(root->right);
}

void BinaryTree::inorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	inorderTraversalRecursion(root->left);
	std::cout << root->val << " ";
	inorderTraversalRecursion(root->right);
}

void BinaryTree::postorderTraversalRecursion(TreeNode *root) {
	if (root == nullptr) return;
	postorderTraversalRecursion(root->left);
	postorderTraversalRecursion(root->right);
	std::cout << root->val << " ";
}
```

#### 非递归

在二叉树的递归遍历中，系统会帮助我们压栈弹栈。而在非递归遍历中，前中后序遍历都需要我们自己完成压栈和弹栈的操作。

##### 前序遍历

在前序遍历中，我们首先将根节点压入栈中，因为根节点一定是有，无论他是否为null。然后我们就可以开始做一些重复的迭代工作直至栈空：

- 弹栈并处理该节点；
- 依次将右孩子、左孩子压入栈中（如果存在的话）；（为什么是先右孩子、再左孩子，因为前序遍历的顺序是根、左、右，而出栈的顺序与弹栈的顺序相反）

```cpp
void BinaryTree::preorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *cur = stk.top();
		std::cout << cur->val << " ";
		stk.pop();
		if (cur->right) stk.push(cur->right);
		if (cur->left) stk.push(cur->left);
	}
}
```



##### 中序遍历

每一颗二叉树可以通过**左边界**进行拆分。

在中序遍历（**左根右**）的过程中，我们需要进行以下迭代过程：

- 将左边界压入栈中（当前节点及其左孩子、左孩子的左孩子......）；
- 弹栈，处理数据，并将其右孩子的左边界（右孩子及其左孩子......）压栈（如果存在）；

实际上，这一过程就是**左根右（左根右（左根右（null）））**，即右子树每次都被处理成了**左根**的形式。

```cpp
void BinaryTree::inorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	TreeNode *cur = root;
	while (!stk.empty() || cur != nullptr) {
		if (cur != nullptr) {
			while (cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			}
		} else {
			cur = stk.top();
			stk.pop();
			std::cout << cur->val << " ";
			cur = cur->right;
		}
	}
}
```



##### 后序遍历

后序遍历的顺序是**左右根**，而前序遍历的顺序是**根左右**，我们根据前序遍历可以改变左右孩子入栈的顺序达到**根右左**的效果。而我们在以**根右左**的方式存入一个辅助栈中，最后统一出栈即可得到后序遍历的结果。

```cpp
void BinaryTree::postorderTraversal(TreeNode *root) {
	if (root == nullptr) return;
	std::stack<TreeNode*> stk;
	std::stack<TreeNode*> help;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *cur = stk.top();
		help.push(cur);
		stk.pop();
		if (cur->left) stk.push(cur->left);
		if (cur->right) stk.push(cur->right);
	}
	while (!help.empty()) {
		std::cout << help.top()->val << " ";
		help.pop();
	}
	return;
}
```



### 直观打印二叉树





### 二叉树宽度优先遍历

对于二叉树的宽度优先遍历，需要用到队列。首先将根节点加入队列，然后进行重复的迭代：

- 出队列，数据处理；
- 依次将左、右加入队列（如果存在）；





#### 二叉树最大宽度











## 阅读别人的代码

在纸上写下所有声明的变量，依据算法，记录数据变动的方式。

- 设置的变量；
- 数据的变动；

