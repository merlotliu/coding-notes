#include "code01_binray_tree_traversal.hpp"
#include "code03_level_traversal.hpp"

int main(int argc, char *argv[]) {
	TreeNode *left1 = new TreeNode(4);
	TreeNode *right1 = new TreeNode(5);
	TreeNode *left2 = new TreeNode(6);
	TreeNode *right2 = new TreeNode(7);
	left1 = new TreeNode(2, left1, right1);
	right1 = new TreeNode(3, left2, right2);
	TreeNode *root = new TreeNode(1, left1, right1);

	BinaryTree tree;
	tree.preorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.preorderTraversal(root);
	std::cout << std::endl;
	tree.inorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.inorderTraversal(root);
	std::cout << std::endl;
	tree.postorderTraversalRecursion(root);
	std::cout << std::endl;
	tree.postorderTraversal(root);
	std::cout << std::endl;

	tree.levelTraversal(root);
	std::cout << std::endl;

	return 0;
}