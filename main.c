#include "raylib.h"
#include <string.h>

#define MAX_INPUT 2048

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Libft Typing App - Copy Mode");

	SetTargetFPS(60);

	char userInput[MAX_INPUT] = {0};
	int letterCount = 0;

	Rectangle inputBox = {50, 400, 700, 150};

	const char* libftFunction =
		"size_t ft_strlen(const char *s) {\n"
		"    size_t i = 0;\n"
		"    while (s[i])\n"
		"        i++;\n"
		"    return i;\n"
		"}";

	while (!WindowShouldClose()) {
		// Input handling
		int key = GetCharPressed();
		while (key > 0) {
			if (letterCount < MAX_INPUT - 1 && key >= 32 && key <= 126) {
				userInput[letterCount++] = (char)key;
				userInput[letterCount] = '\0';
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE) && letterCount > 0) {
			letterCount--;
			userInput[letterCount] = '\0';
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("Type the implementation of:", 50, 20, 24, BLACK);
		DrawText("ft_strlen", 50, 50, 32, DARKBLUE);
		DrawText(libftFunction, 50, 100, 20, DARKGRAY);

		DrawRectangleLinesEx(inputBox, 2, GRAY);
		DrawText(userInput, (int)inputBox.x + 5, (int)inputBox.y + 10, 20, BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
