#include "binary_tree.h"

int main(void) {
    BinaryTree *tree = create_binary_tree();

    insert(tree->root, 10);
    insert(tree->root, 50);
    insert(tree->root, 12);
    insert(tree->root, 20);
    insert(tree->root, 15);
    insert(tree->root, 0);
    insert(tree->root, -1);
    insert(tree->root, -4);
    insert(tree->root, -3);
    insert(tree->root, 2);

    return 0;
}
