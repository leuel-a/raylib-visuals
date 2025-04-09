#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "binary_tree.h"

BinaryTree* create_binary_tree(Point root_position) {
	BinaryTree* tree =  malloc(sizeof(BinaryTree));

	tree->root = NULL;
	tree->root_position = root_position;

	return tree;
}

TreeNode* create_binary_tree_node(int value, Point position) {
	TreeNode* new = malloc(sizeof(TreeNode));

	new->value = value;
    new->position = position;

    /** this is just to be sure it will always be null no need to worry */
	new->left = NULL;
	new->right = NULL;

	return new;
}

void insert(BinaryTree* tree, int value) {
	TreeNode* new = NULL;
	TreeNode* root = tree->root;
    Point root_position = tree->root_position;

	if (root == NULL) {
		new = create_binary_tree_node(value, root_position);
		tree->root = new;
		return;
	} else {
        insert_helper(root, value);
    }
}

void insert_helper(TreeNode* node, int value) {
    Point curr_node_position, new_position;

	if (node == NULL) {
		return;
	}

    curr_node_position = node->position;
	if (node->value > value) {
		if (node->left != NULL) {
			insert_helper(node->left, value);
        } else {
            new_position = (Point){ .x = curr_node_position.x - 150, .y = curr_node_position.y + 100 };
			node->left = create_binary_tree_node(value, new_position);
        }
	} else {
		if (node->right != NULL) {
			insert_helper(node->right, value);
        } else {
            new_position = (Point){ .x = curr_node_position.x + 150, .y = curr_node_position.y + 100 };
			node->right = create_binary_tree_node(value, new_position);
        }
	}
}

/** visualization functions for a binary tree */
void draw_binary_tree(BinaryTree* tree, int node_radius) {
	if (tree == NULL)
		return;
    draw_binary_tree_helper(tree->root, node_radius);
}

void draw_binary_tree_helper(TreeNode* node, int node_radius) {
    if (node == NULL) return;

    DrawCircle(node->position.x, node->position.y, node_radius, BLUE);                              // Draw a color-filled circle

    draw_binary_tree_helper(node->left, node_radius);
    draw_binary_tree_helper(node->right, node_radius);
}

/** search functions for a binary tree */
void dfs(BinaryTree* tree) {
	if (tree == NULL)
		return;
	dfs_helper(tree->root);
	putchar('\n');
}

void dfs_helper(TreeNode* node) {
	if (node == NULL)
		return;


	dfs_helper(node->left);
	printf("%d position { .x = %d, .y = %d}", node->value, node->position.x, node->position.y);
	dfs_helper(node->right);
}

