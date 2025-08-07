#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_binary_tree - Allocates and initializes a binary tree.
 *
 * Return: Pointer to the new binary tree.
 */
BinaryTree *create_binary_tree(void) {
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    tree->root = NULL;
    return (tree);
}

/**
 * create_binary_tree_node - Creates a new binary tree node with a given value.
 * @value: The integer value to store in the node.
 *
 * Return: Pointer to the new node.
 */
TreeNode *create_binary_tree_node(int value) {
    TreeNode *new = malloc(sizeof(TreeNode));
    new->value = value;
    new->left = NULL, new->right = NULL;
    return (new);
}

/**
 * insert_helper - Recursively finds the correct position and inserts a new value.
 * @node: current node in the binary tree.
 * @value: value to insert.
 */
void insert(TreeNode *node, int value) {
    if (node == NULL)
        return;
    if (node->value > value) {
        if (node->left != NULL) {
            insert(node->left, value);
            return;
        }
        node->left = create_binary_tree_node(value);
        return;
    }
    if (node->right != NULL) {
        insert(node->right, value);
        return;
    }
    node->right = create_binary_tree_node(value);
}

/**
 * assign_positions - Assigns x positions for the binary tree nodes
 *
 * @node: pointer to the tree node to assign position to
 * @current_x: the current x position to use for the binary tree
 *
 * Returns: Nothing
 */
void assign_positions(TreeNode *node, int *current_x, int *root_position, int is_root) {
    if (node == NULL)
        return;

    assign_positions(node->left, current_x, root_position, 0);

    node->x_position = (*current_x)++;
    if (is_root == 1) {
        *root_position = *current_x;
    }

    assign_positions(node->right, current_x, root_position, 0);
}

/**
 * dfs - Performs a depth-first search on a binary tree.
 * @tree: Pointer to the BinaryTree structure.
 *
 * This function initiates an in-order depth-first traversal
 * of the binary tree starting from the root node.
 */
void dfs(TreeNode *node) {
    if (node == NULL)
        return;
    dfs(node->left);
    dfs(node->right);
}
