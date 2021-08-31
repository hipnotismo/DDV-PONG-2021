#include "credits.h"

#include "raylib.h"

#include "Game/game.h"

namespace credits {

	void updateCredits();
	void drawCredits();

	static Vector2 mousePoint;
	static Rectangle rec1;
	Texture2D background;

	void initCredits() {

		background = LoadTexture("../res/assets/images/Background.png");

		rec1.x = 25;
		rec1.y = 25;
		rec1.height = 50;
		rec1.width = 100;
	}
	void updateCredits() {

		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Menu;

			}
		}
	}

	void drawCredits() {

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, WHITE);

		DrawRectangle(static_cast<int>(rec1.x), static_cast<int>(rec1.y), static_cast<int>(rec1.width), static_cast<int>(rec1.height), BLACK);

		DrawText("atras", static_cast<int>(rec1.x) + 18, static_cast<int>(rec1.y) + 10, 20, WHITE);

		DrawText("Pong, por Martin Concetti", 20, 260, 20, BLACK);
		DrawText("Creado usando raylib y sfxr", 130, 280, 20, BLACK);

		EndDrawing();
	}

	void updateFrameCredits() {
		updateCredits();
		drawCredits();
	}
}