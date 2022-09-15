#include "code01_binray_tree_traversal.hpp"
#include "code03_level_traversal.hpp"

#include "code06_full_binary_tree.hpp"

int main(int argc, char *argv[]) {
	TreeNode *left1 = new TreeNode(4);
	TreeNode *right1 = new TreeNode(5);
	TreeNode *left2 = new TreeNode(6);
	TreeNode *right2 = new TreeNode(7);
	left1 = new TreeNode(2, left1, right1);
	right1 = new TreeNode(3, left2, right2);
	TreeNode *root = new TreeNode(1, left1, right1);

	std::cout << "Binary Tree Traversal" << std::endl;
	BinaryTree tree;
	std::cout << "Binary Tree Preordered Traversal" << std::endl;
	tree.preorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.preorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Binary Tree Inordered Traversal" << std::endl;
	tree.inorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.inorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Binary Tree Postordered Traversal" << std::endl;
	tree.postorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.postorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Level Traversal" << std::endl;
	tree.levelTraversal(root);
	std::cout << std::endl;

	std::cout << "Get Max Width" << std::endl;
	std::cout << tree.getMaxWidthByMap(root) << std::endl;
	std::cout << tree.getMaxWidth(root) << std::endl;

	std::cout << "FBT" << std::endl;
	std::cout << "Is FBT : ";
	std::cout << (isFBT(root) ? "True" : "False") << std::endl;
	std::cout << "Tree Depth : ";
	std::cout << getTreeDepth(root) << std::endl;
	std::cout << "Tree Nodes count : ";
	std::cout << getNodesCount(root) << std::endl;
	return 0;
}