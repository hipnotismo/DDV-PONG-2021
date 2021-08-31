#include "Menu.h"

#include<iostream>

#include "raylib.h"

#include "Game/Game.h"

namespace menu {


	Texture2D background2;

	static Vector2 mousePoint;
	static Rectangle rec1;
	static Rectangle rec2;
	static Rectangle rec3;
	static Rectangle rec4;


	void initMenu() {

		background2 = LoadTexture("../res/assets/images/Background.png");

		rec1.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec1.y = static_cast<float>(GetScreenHeight()) / 2 - 80;
		rec1.height = 50;
		rec1.width = 100;

		rec2.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec2.y = static_cast<float>(GetScreenHeight()) / 2;
		rec2.height = 50;
		rec2.width = 100;

		rec3.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec3.y = static_cast<float>(GetScreenHeight()) / 2 + 80;
		rec3.height = 50;
		rec3.width = 100;


		rec4.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec4.y = static_cast<float>(GetScreenHeight()) / 2 + 160;
		rec4.height = 50;
		rec4.width = 100;

	}
	void updateMenu() {

		drawMenu();

		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Game;
			}
		}
		if (CheckCollisionPointRec(mousePoint, rec2)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Credits;

			}
		}
		if (CheckCollisionPointRec(mousePoint, rec3)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Controls;
			}
		}
	}

	void drawMenu() {

		ClearBackground(RAYWHITE);

		DrawTexture(background2, 0, 0, WHITE);

		DrawRectangle(static_cast<int>(rec1.x), static_cast<int>(rec1.y), static_cast<int>(rec1.width), static_cast<int>(rec1.height), BLACK);
		DrawRectangle(static_cast<int>(rec2.x), static_cast<int>(rec2.y), static_cast<int>(rec2.width), static_cast<int>(rec2.height), BLACK);
		DrawRectangle(static_cast<int>(rec3.x), static_cast<int>(rec3.y), static_cast<int>(rec3.width), static_cast<int>(rec3.height), BLACK);

		DrawText("jugar", static_cast<int>(rec1.x) + 18, static_cast<int>(rec1.y) + 10, 18, WHITE);
		DrawText("Creditos", static_cast<int>(rec2.x) + 5, static_cast<int>(rec2.y) + 10, 18, WHITE);
		DrawText("Controles", static_cast<int>(rec3.x) + 5, static_cast<int>(rec3.y) + 10, 18, WHITE);
		DrawText("PONG", GetScreenWidth() / 2 - 110, 50, 100, MAROON);

		EndDrawing();
	}

}