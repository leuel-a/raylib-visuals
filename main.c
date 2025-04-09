#include "raylib.h"
#include "main.h"
#include "binary_tree.h"


int main(void)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int NODE_RADIUS = 40;

    Point root_position = { .x = SCREEN_WIDTH / 2, .y = 200 };
    BinaryTree* tree = create_binary_tree(root_position);

    insert(tree, 10);
    insert(tree, 12);
    insert(tree, 0);
    insert(tree, -1);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "BINARY TREE VISUALIZATION");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            draw_binary_tree(tree, NODE_RADIUS);
            DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, NODE_RADIUS, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
