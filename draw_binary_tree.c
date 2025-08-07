#include "draw_binary_tree.h"
#include "main.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

const int NODE_RADIUS = 30;
const int X_CHANGE = 150;
const int Y_CHANGE = 80;

/**
 * draw_binary_tree - draws a binary tree
 *
 * @tree: The pointer to the binary tree
 * @root_position: The position of the root node
 * Returns: Nothing
 */
void draw_binary_tree(BinaryTree *tree, int root_x_position, Point node_point) {
    printf("%d Root Position Value -> ", root_x_position);
    draw_binary_tree_helper(tree->root, node_point, root_x_position);
}

/**
 * draw_binary_tree_node - draws a node of a binary tree
 * @node: The pointer to the binary tree node
 * @direction: To indicate that the node is either a right child of the parent, or a
 *             left child of the parent.
 *
 * Returns: Nothing
 */
void draw_binary_tree_helper(TreeNode *node, Point position, int root_x_position) {
    if (node == NULL)
        return;

    Point curr_node_position;
    int x_change = node->x_position - root_x_position;

    if (x_change == root_x_position) {
        draw_binary_tree_node(node->value, position);
    } else {
        curr_node_position.x = abs(position.x + (x_change * X_CHANGE));
        curr_node_position.y = abs(position.y + (Y_CHANGE));

        draw_binary_tree_node(node->value, curr_node_position);
    }
}

/**
 * draw_binary_tree_node - draws a node for a binary tree
 * @value: The value for the binary tree node
 * @position: The position where the center of binary tree node will be
 *
 * Returns: Nothing
 */
void draw_binary_tree_node(int value, Point position) {
    (void)value;
    DrawCircleLines(position.x, position.y, NODE_RADIUS, WHITE);
}
