#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "main.h"

typedef struct TreeNode {
    int value;
    int x_position;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
    Point root_position;
} BinaryTree;

void dfs(TreeNode *);

BinaryTree *create_binary_tree();
void insert(TreeNode *node, int value);
TreeNode *create_binary_tree_node(int value);

#endif /*BINARY_TREE_H*/
