#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "main.h"

typedef struct TreeNode {
	int value;
    Point position;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
	TreeNode* root;
    Point root_position;
} BinaryTree;

// SEARCH FUNCTIONS
void dfs(BinaryTree* tree);

void dfs_helper(TreeNode* node);

// BINARY TREE FUNCTIONS
BinaryTree* create_binary_tree(Point root_position);

TreeNode* create_binary_tree_node(int value, Point position);

void insert(BinaryTree* tree, int value);

void insert_helper(TreeNode* tree, int value);

// VISUALIZATION FUNCTIONS
void draw_binary_tree(BinaryTree* tree, int node_radius);

void draw_binary_tree_helper(TreeNode* node, int node_radius, Point *parent_position);

void draw_parent_child_line(Point parent_position, Point node_position, int node_radius);

void draw_binary_tree_node_value(TreeNode* node);

#endif /*BINARY_TREE_H*/
