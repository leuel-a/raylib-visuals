#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"
#include "main.h"

BinaryTree *create_binary_tree() {
    BinaryTree *tree = malloc(sizeof(BinaryTree));

    tree->root = NULL;
    return tree;
}

TreeNode *create_binary_tree_node(int value) {
    TreeNode *new = malloc(sizeof(TreeNode));

    new->value = value;

    new->left = NULL;
    new->right = NULL;

    return new;
}

void insert(BinaryTree *tree, int value) {
    TreeNode *new = NULL, *root = tree->root;

    if (root == NULL) {
        new = create_binary_tree_node(value);
        tree->root = new;
        return;
    } else {
        insert_helper(root, value);
    }
}

void insert_helper(TreeNode *node, int value) {
    if (node == NULL)
        return;

    if (node->value > value) {
        if (node->left != NULL) {
            insert_helper(node->left, value);
            return;
        }
        node->left = create_binary_tree_node(value);
        return;
    }

    if (node->right != NULL) {
        insert_helper(node->right, value);
        return;
    }

    node->right = create_binary_tree_node(value);
    return;
}

/**
 * dfs - Performs a depth-first search on a binary tree.
 * @tree: Pointer to the BinaryTree structure.
 *
 * This function initiates an in-order depth-first traversal
 * of the binary tree starting from the root node.
 */
void dfs(BinaryTree *tree) {
    if (tree == NULL)
        return;

    dfs_helper(tree->root);
    putchar('\n');
}

/**
 * dfs_helper - Recursively traverses the binary tree in-order.
 * @node: Pointer to the current TreeNode.
 *
 * This function prints each node's value and position (x, y)
 * in in-order traversal: left subtree, current node, right subtree.
 */
void dfs_helper(TreeNode *node) {
    if (node == NULL)
        return;

    dfs_helper(node->left);

    // printf("%d (%d, %d)", node->value, node->position.x, node->position.y);

    dfs_helper(node->right);
}
