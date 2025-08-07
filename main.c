#include "main.h"
#include "binary_tree.h"
#include "draw_binary_tree.h"
#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int TARGET_FPS = 60;

int main(void) {
    int CURRENT_X = 0, ROOT_POSITION = 0, IS_ROOT = 1;
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
