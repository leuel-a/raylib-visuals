#ifndef DRAW_BINARY_H
#define DRAW_BINARY_H

#include "binary_tree.h"
#include "main.h"

void draw_binary_tree(BinaryTree *tree, int root_position, Point root_point);
void draw_binary_tree_helper(TreeNode *node, Point node_point, int root_position);
void draw_binary_tree_node(int value, Point position);

#endif
