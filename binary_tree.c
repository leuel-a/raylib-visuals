#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "binary_tree.h"

// BINARY TREE FUNCTIONS
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
            new_position = (Point){ .x = curr_node_position.x - 150, .y = curr_node_position.y + 120 };
			node->left = create_binary_tree_node(value, new_position);
        }
	} else {
		if (node->right != NULL) {
			insert_helper(node->right, value);
        } else {
            new_position = (Point){ .x = curr_node_position.x + 150, .y = curr_node_position.y + 120 };
			node->right = create_binary_tree_node(value, new_position);
        }
	}
}

// VISUALIZATION FUNCTIONS
void draw_binary_tree(BinaryTree* tree, int node_radius) {
	if (tree == NULL)
		return;
    draw_binary_tree_helper(tree->root, node_radius, NULL);
}

void draw_binary_tree_helper(TreeNode* node, int node_radius, Point *parent_position) {
    if (node == NULL) return;

    DrawCircleLines(node->position.x, node->position.y, node_radius, WHITE);

    draw_binary_tree_node_value(node);

    if (parent_position != NULL) {
        draw_parent_child_line(*parent_position, node->position, node_radius);
    }

    draw_binary_tree_helper(node->left, node_radius, &node->position);
    draw_binary_tree_helper(node->right, node_radius, &node->position);
}

void draw_parent_child_line(Point parent_position, Point node_position, int node_radius) {
    float dx = node_position.x - parent_position.x;
    float dy = node_position.y - parent_position.y;
    float d = sqrtf(dx * dx + dy * dy);
    float ux = dx / d, uy = dy / d;

    Point parent_slide = { .x = parent_position.x + ux * node_radius, .y = parent_position.y + uy * node_radius };
    Point node_slide = { .x = node_position.x - ux * node_radius, .y = node_position.y - uy * node_radius };

    DrawLine(parent_slide.x, parent_slide.y, node_slide.x, node_slide.y, WHITE);
}

void draw_binary_tree_node_value(TreeNode* node) {
    Vector2 textSize;
    const char* text = NULL;
    int fontSize = 30, textY, textX;
    Font font = GetFontDefault();

    text = TextFormat("%d", node->value);
    textSize = MeasureTextEx(font, text, fontSize, 1);

    textX = node->position.x - textSize.x / 2;
    textY = node->position.y - textSize.y / 2;

    DrawTextEx(font, text, (Vector2){textX, textY}, fontSize, 1, WHITE);
}

// SEARCH FUNCTIONS
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

	printf("%d (%d, %d)", node->value, node->position.x, node->position.y);
	dfs_helper(node->right);

}

