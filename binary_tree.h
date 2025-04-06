#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int value;
	struct TreeNode* Left;
	struct TreeNode* Right;
} TreeNode;

typedef struct BinaryTree {
	TreeNode* root;
} BinaryTree;


/** search functions */
void dfs(BinaryTree* tree);
void dfs_helper(TreeNode* node);

/** utils function to operate on the binary tree */
BinaryTree* create_binary_tree(void);
TreeNode* create_binary_tree_node(int value);
void insert(BinaryTree* tree, int value);
void insert_helper(TreeNode* tree, int value);

#endif /*BINARY_TREE_H*/
