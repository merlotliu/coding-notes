#include "code01_binray_tree_traversal.hpp"
#include "code03_level_traversal.hpp"
#include "code04_binary_search_tree.hpp"
#include "code05_completed_binary_tree.hpp"
#include "code06_full_binary_tree.hpp"
#include "code07_avl_tree.hpp"
#include "code08_find_common_ancestor.hpp"
#include "code10_serializing_deserializing.hpp"
#include "code11_ms_paper_folding.hpp"
#include "morris.hpp"

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
	std::cout << "Recursion : ";
	tree.preorderTraversalRecursion(root);
	std::cout << std::endl;
	std::cout << "Iteration : ";
	tree.preorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Morris : ";
	tree.morrisPreorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Binary Tree Inordered Traversal" << std::endl;
	std::cout << "Recursion : ";
	tree.inorderTraversalRecursion(root);
	std::cout << std::endl;
	std::cout << "Iteration : ";
	tree.inorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Morris : ";
	tree.morrisInorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Binary Tree Postordered Traversal" << std::endl;
	std::cout << "Recursion : ";
	tree.postorderTraversalRecursion(root);
	std::cout << std::endl;
	std::cout << "Iteration : ";
	tree.postorderTraversal(root);
	std::cout << std::endl;
	std::cout << "Morris : ";
	tree.morrisPostorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Level Traversal" << std::endl;
	tree.levelTraversal(root);
	std::cout << std::endl;

	/*std::cout << "Get Max Width" << std::endl;
	std::cout << tree.getMaxWidthByMap(root) << std::endl;
	std::cout << tree.getMaxWidth(root) << std::endl;

	std::cout << "FBT" << std::endl;
	std::cout << "Is FBT : ";
	std::cout << (isFBT(root) ? "True" : "False") << std::endl;
	std::cout << "Tree Depth : ";
	std::cout << getTreeDepth(root) << std::endl;
	std::cout << "Tree Nodes count : ";
	std::cout << getNodesCount(root) << std::endl;

	std::cout << "AVL" << std::endl;
	std::cout << "Is AVL : ";
	std::cout << (isAVL(root).is_avl ? "True" : "False") << std::endl;

	std::cout << "Common Ancestor" << std::endl;
	TreeNode *node1 = left1;
	TreeNode *node2 = left2;
	std::cout << node1->val << " & " << node2->val << " Common Ancestor : ";
	std::cout << findCommonAncestor(root, node1, node2)->val << std::endl;
	std::cout << node1->val << " & " << node2->val << " Common Ancestor (Recursion) : ";
	std::cout << findCommonAncestorRecur(root, node1, node2)->val << std::endl;

	std::cout << "Successor Node" << std::endl;

	std::cout << "Serializing & Deserializing" << std::endl;
	std::string str;
	serializing(root, str);
	std::cout << str << std::endl;
	tree.preorderTraversal(deserializing(str));
	std::cout << std::endl;

	std::cout << "MS Paper Folding" << std::endl;
	int n = 3;
	printPaperCreaseFacing(n);
	std::cout << std::endl;
	printPaperFolds(1, n, true);
	std::cout << std::endl;
	printPaperFolds(n, true);
	std::cout << std::endl;*/

	std::cout << "Morris Traversal" << std::endl;
	tree.morrisTraversal(root);

	return 0;
}