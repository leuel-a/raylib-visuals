#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
	int n;
	struct TreeNode* Left;
	struct TreeNode* Right;
} TreeNode;

typedef struct BinaryTree {
	TreeNode* root;
} BinaryTree;

BinaryTree* create_binary_tree(void);

#endif /*BINARY_TREE_H*/
