#include "main.h"
#include "binary_tree.h"
#include "draw_binary_tree.h"
#include "raylib.h"
#include <stdio.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int TARGET_FPS = 60;

int main(void) {
    int CURRENT_X = 0, ROOT_POSITION = 0, IS_ROOT = 1;
    BinaryTree *tree = create_binary_tree();

    insert(tree, 10);
    insert(tree, 50);
    insert(tree, 12);
    insert(tree, 20);
    insert(tree, 15);
    insert(tree, 0);
    insert(tree, -1);
    insert(tree, -4);
    insert(tree, -3);
    insert(tree, 2);

    assign_positions(tree->root, &CURRENT_X, &ROOT_POSITION, IS_ROOT);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BINARY TREE VISUALIZATION");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            draw_binary_tree(tree, ROOT_POSITION, (Point){.x = SCREEN_WIDTH / 2, .y = 100});
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
