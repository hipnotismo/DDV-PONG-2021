#include "raylib.h"

#include "Controls.h"

#include <iostream>

#include "Game/Game.h"

namespace controls {

	void updateControls();
	void drawControls();

	Texture2D background;

	int foo[] = { 16, 2, 77, 40, 12071 };
	int* ptr = foo;

	static Rectangle rect1;
	static Rectangle rect2;
	static Rectangle rect3;

	static Rectangle player1;
	static Rectangle player2;

	Vector2 mause;
	Color mauseColor;

	Color player1Color = DARKBLUE;
	Color player2Color = GOLD;

	bool colorChange = false;
	bool colorChange2 = false;

	bool controlChange = false;
	bool controlChange2 = false;

	int count1;
	int count2;
	int count3;
	int count4;

	int mauseradius;

	char upPlayer1 = 'Q';
	char downPlayer1 = 'A';
	char upPlayer2 = 'P';
	char downPlayer2 = 'L';

	void initControls() {

		background = LoadTexture("../res/assets/images/Background.png");

		player1.x = static_cast<float>(GetScreenWidth()) / 6 - 120;
		player1.y = static_cast<float>(GetScreenHeight()) / 4 + 50;
		player1.height = 80;
		player1.width = 10;

		player2.x = static_cast<float>(GetScreenWidth()) - 30;
		player2.y = static_cast<float>(GetScreenHeight()) / 4 + 50;
		player2.height = 80;
		player2.width = 10;

		rect1.x = 25;
		rect1.y = 25;
		rect1.height = 50;
		rect1.width = 100;

		rect2.x = 0;
		rect2.y = static_cast<float>(GetScreenHeight()) - 50;
		rect2.height = 50;
		rect2.width = 100;

		rect3.x = static_cast<float>(GetScreenWidth()) - 100;
		rect3.y = static_cast<float>(GetScreenHeight()) - 50;
		rect3.height = 50;
		rect3.width = 100;

		int count1 = 0;
		int count2 = 0;

		mause = { -100.0f, -100.0f };
		mauseColor = DARKBLUE;
		mauseradius = 10;



	}

	void updateControls() {

		mause = GetMousePosition();

		if (CheckCollisionPointRec(mause, rect1)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Menu;
			}

		}

		colorChange = CheckCollisionCircleRec(mause, static_cast<float>(mauseradius), player1);
		colorChange2 = CheckCollisionCircleRec(mause, static_cast<float>(mauseradius), player2);
		if (colorChange) {

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {

				count1 = count1 + 1;
				if (count1 >= 2)
					count1 = 2;
			}
		}
		if (colorChange) {

			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {

				count1 = count1 - 1;

				if (count1 <= 0)
					count1 = 0;
			}
		}
		if (count1 == 0) {
			player1Color = DARKBLUE;
		}
		if (count1 == 1) {
			player1Color = PURPLE;
		}
		if (count1 == 2) {
			player1Color = BROWN;
		}
		if (colorChange2) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				count2 = count2 + 1;

				if (count2 >= 2)
					count2 = 2;
			}
		}
		if (colorChange2) {

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {

				count2 = count2 - 1;

				if (count2 <= 0)
					count2 = 0;
			}
		}
		if (count2 == 0) {
			player2Color = GOLD;
		}
		if (count2 == 1) {
			player2Color = ORANGE;
		}
		if (count2 == 2) {
			player2Color = RED;
		}

		if (CheckCollisionPointRec(mause, rect1)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				game::Screens = game::Menu;

			}

		}

		controlChange = CheckCollisionCircleRec(mause, static_cast<float>(mauseradius), rect2);
		controlChange2 = CheckCollisionCircleRec(mause, static_cast<float>(mauseradius), rect3);

		if (controlChange) {

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {

				count3 = count3 + 1;

				if (count3 >= 4)

					count3 = 4;
			}
		}
		if (controlChange) {

			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
				count3 = count3 - 1;
				if (count3 <= 0)
					count3 = 0;
			}
		}
		if (count3 == 0) {
			upPlayer1 = 'Q';
			downPlayer1 = 'A';
		}
		if (count3 == 1) {
			upPlayer1 = 'W';
			downPlayer1 = 'S';
		}
		if (count3 == 2) {
			upPlayer1 = 'E';
			downPlayer1 = 'D';
		}
		if (count3 == 3) {
			upPlayer1 = 'R';
			downPlayer1 = 'F';
		}
		if (count3 == 4) {
			upPlayer1 = 'T';
			downPlayer1 = 'G';
		}

		if (controlChange2) {

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {

				count4 = count4 + 1;

				if (count4 >= 3)
					count4 = 3;
			}
		}
		if (controlChange2) {

			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {

				count4 = count4 - 1;

				if (count4 <= 0)
					count4 = 0;
			}
		}
		if (count4 == 0) {
			upPlayer1 = 'P';
			downPlayer1 = 'L';
		}
		if (count3 == 1) {
			upPlayer1 = 'O';
			downPlayer1 = 'K';
		}
		if (count3 == 2) {
			upPlayer1 = 'I';
			downPlayer1 = 'J';
		}
		if (count3 == 3) {
			upPlayer1 = 'U';
			downPlayer1 = 'H';
		}
	}

	void drawControls() {

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, WHITE);

		DrawRectangle(static_cast<int>(player1.x), static_cast<int>(player1.y), static_cast<int>(player1.width), static_cast<int>(player1.height), player1Color);
		DrawRectangle(static_cast<int>(player2.x), static_cast<int>(player2.y), static_cast<int>(player2.width), static_cast<int>(player2.height), player2Color);

		DrawRectangle(static_cast<int>(rect1.x), static_cast<int>(rect1.y), static_cast<int>(rect1.width), static_cast<int>(rect1.height), BLACK);
		DrawRectangle(static_cast<int>(rect2.x), static_cast<int>(rect2.y), static_cast<int>(rect2.width), static_cast<int>(rect2.height), BLACK);
		DrawRectangle(static_cast<int>(rect3.x), static_cast<int>(rect3.y), static_cast<int>(rect3.width), static_cast<int>(rect3.height), BLACK);

		ClearBackground(RAYWHITE);
		DrawText("atras", static_cast<int>(rect1.x) + 18, static_cast<int>(rect1.y) + 10, 20, WHITE);
		DrawText("Toque a los jugadores con el mause para cambiar su color", 40, 100, 20, BLACK);
		DrawText("P para pausar la partida", 40, 120, 20, BLACK);
		DrawText("Presione los botones en la parte inferior", 40, 160, 20, BLACK);
		DrawText(" para cambiar los controles de juego", 40, 180, 20, BLACK);

		//	DrawText("P para pausar", 40, 240, 20, BLACK);

		if (count3 == 0) {
			DrawText("Q/A", static_cast<int>(rect2.x) + 18, static_cast<int>(rect2.y) + 10, 20, WHITE);
		}
		if (count3 == 1) {
			DrawText("W/S", static_cast<int>(rect2.x) + 18, static_cast<int>(rect2.y) + 10, 20, WHITE);
		}
		if (count3 == 2) {
			DrawText("E/D", static_cast<int>(rect2.x) + 18, static_cast<int>(rect2.y) + 10, 20, WHITE);
		}
		if (count3 == 3) {
			DrawText("R/F", static_cast<int>(rect2.x) + 18, static_cast<int>(rect2.y) + 10, 20, WHITE);
		}
		if (count3 == 4) {
			DrawText("T/G", static_cast<int>(rect2.x) + 18, static_cast<int>(rect2.y) + 10, 20, WHITE);
		}

		if (count4 == 0) {
			DrawText("P/L", static_cast<int>(rect3.x) + 18, static_cast<int>(rect3.y) + 10, 20, WHITE);
		}
		if (count4 == 1) {
			DrawText("O/K", static_cast<int>(rect3.x + 18), static_cast<int>(rect3.y) + 10, 20, WHITE);
		}
		if (count4 == 2) {
			DrawText("I/J", static_cast<int>(rect3.x) + 18, static_cast<int>(rect3.y) + 10, 20, WHITE);
		}
		if (count4 == 3) {
			DrawText("U/H", static_cast<int>(rect3.x) + 18, static_cast<int>(rect3.y) + 10, 20, WHITE);
		}

		DrawCircleV(mause, static_cast<float>(mauseradius), mauseColor);

		EndDrawing();
	}

	void updateFrameControls() {
		updateControls();
		drawControls();
	}

}