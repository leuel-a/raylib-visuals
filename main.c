#include "raylib.h"

int main(void)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Binary Tree Visualization");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 60, BLUE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
