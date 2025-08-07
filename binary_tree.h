#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "main.h"

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
    Point root_position;
} BinaryTree;

void dfs(BinaryTree *tree);
void dfs_helper(TreeNode *node);

BinaryTree *create_binary_tree();
TreeNode *create_binary_tree_node(int value);
void insert(BinaryTree *tree, int value);
void insert_helper(TreeNode *tree, int value);

#endif /*BINARY_TREE_H*/
