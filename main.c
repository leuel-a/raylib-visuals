#include "raylib.h"
#include "main.h"
#include "binary_tree.h"


int main(void)
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;
    const int NODE_RADIUS = 30;

    Point root_position = { .x = SCREEN_WIDTH / 2, .y = 100 };
    BinaryTree* tree = create_binary_tree(root_position);

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

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BINARY TREE VISUALIZATION");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);

            draw_binary_tree(tree, NODE_RADIUS);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
