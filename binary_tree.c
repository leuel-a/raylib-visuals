#include "binary_tree.h"

BinaryTree* create_binary_tree(void) {
	BinaryTree* tree =  malloc(sizeof(BinaryTree));

	tree->root = NULL;
	return tree;
}

TreeNode* create_binary_tree_node(int value) {
	TreeNode* new = malloc(sizeof(TreeNode));

	new->value = value;
	new->Left = NULL;
	new->Right = NULL;

	return new;
}

void insert(BinaryTree* tree, int value) {
	TreeNode* root = tree->root;
	TreeNode* new = NULL;

	if (root == NULL) {
		new = malloc(sizeof(TreeNode));
		new->value = value;

		new->Left = NULL;
		new->Right = NULL;

		tree->root = new;
		return;
	}

	insert_helper(root, value);
}

void insert_helper(TreeNode* node, int value) {
	if (node == NULL) {
		return;
	}

	if (node->value > value) {
		if (node->Left != NULL)
			insert_helper(node->Left, value);
		else
			node->Left = create_binary_tree_node(value);
	} else {
		if (node->Right != NULL) 
			insert_helper(node->Right, value);
		else
			node->Right = create_binary_tree_node(value);
	}
}

void dfs(BinaryTree* tree) {
	if (tree == NULL)
		return;
	dfs_helper(tree->root);
	putchar('\n');
}

void dfs_helper(TreeNode* node) {
	if (node == NULL)
		return;

	dfs_helper(node->Left);

	printf("%d ", node->value);

	dfs_helper(node->Right);
}

