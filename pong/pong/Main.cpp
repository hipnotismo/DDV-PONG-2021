#include "raylib.h"

#define MAX_POWERUP 3

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	bool collision = false;
	bool collision2 = false;
	bool inicio = false;
	bool mach = false;
	bool colorChange = false;
	bool colorChange2 = false;
	bool exit_button = false;
	bool retry_button = false;
	int points1 = 0;
	int points2 = 0;

	InitWindow(screenWidth, screenHeight, "PONG");


	Rectangle player1;
	Rectangle player2;

	Rectangle retry;
	Rectangle menu;

	Vector2 mause = { -100.0f, -100.0f };
	Color mauseColor = DARKBLUE;
	int mauseradius = 10;

	player1.x = (float)screenWidth / 6 - 80;
	player1.y = (float)screenHeight / 4 + 50;
	player1.height = 80;
	player1.width = 10;
	Color player1Color = MAROON;
	int count2 = 0;
	int endPoint1 = 0;

	player2.x = (float)screenWidth - 80;
	player2.y = (float)screenHeight / 4 + 50;
	player2.height = 80;
	player2.width = 10;
	Color player2Color = GOLD;
	int count1 = 3;
	int endPoint2 = 0;

	menu.height = 40;
	menu.width = 90;
	menu.x = (float)screenWidth / 2 + 80;
	menu.y = (float)screenHeight / 4 + 50;

	retry.height = 40;
	retry.width = 100;
	retry.x = (float)screenWidth / 2 + 80;
	retry.y = (float)screenHeight / 4 + 100;

	Vector2 ballPosition = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
	Vector2 ballSpeed = { 6.0f, 4.0f };
	int ballRadius = 20;
	Color ballColor = MAROON;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		if (IsKeyPressed('P')) inicio = !inicio;


		if (inicio == false) {

			mause = GetMousePosition();

			colorChange = CheckCollisionCircleRec(mause, mauseradius, player1);
			colorChange2 = CheckCollisionCircleRec(mause, mauseradius, player2);


			if (colorChange) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					if (count1 = 0) {
						player1Color = DARKBLUE;
						count1 = 1;
					}
					if (count1 = 1) {
						player1Color = PURPLE;
						count1 = 2;
					}
					if (count1 = 2) {
						player1Color = BROWN;
						count1 = 0;
					}
				}
			}


			if (colorChange2) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					if (count2 = 0) {
						player2Color = GOLD;
						count2 = 1;
					}
					if (count2 = 1) {
						player2Color = ORANGE;
						count2 = 2;
					}
					if (count2 = 2) {
						player2Color = RED;
						count2 = 0;
					}
				}
			}
		}

		if (inicio) {
			if (mach == false) {

				//controles del jugaDOR
				if (IsKeyDown(KEY_W)) {
					if (player1.y > 0) {
						player1.y -= 5.0f;
					}
				}

				if (IsKeyDown(KEY_S)) {
					if (player1.y + player1.y / 2 - 50 < GetScreenHeight()) {
						player1.y += 5.0f;
					}
				}

				if (IsKeyDown(KEY_UP)) {
					if (player2.y > 0) {
						player2.y -= 5.0f;
					}
				}

				if (IsKeyDown(KEY_DOWN)) {
					if (player2.y + player2.y / 2 - 50 < GetScreenHeight()) {
						player2.y += 5.0f;
					}
				}

				//CONTROL DE PUNTOS
				if (ballPosition.x <= ballRadius) {
					points1 = points1 + 1;
					ballPosition.x = screenWidth / 2;
					ballPosition.y = screenHeight / 2;
				}

				if (ballPosition.x >= GetScreenWidth() - ballRadius) {
					points2 = points2 + 1;
					ballPosition.x = screenWidth / 2;
					ballPosition.y = screenHeight / 2;
				}

				//MOVIMIENTO DE LA PELOTA
				ballPosition.x += ballSpeed.x;
				ballPosition.y += ballSpeed.y;

				// Check walls collision for bouncing
				if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
				if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

				//COLICION DE JUGADORES
				collision = CheckCollisionCircleRec(ballPosition, ballRadius, player1);
				collision2 = CheckCollisionCircleRec(ballPosition, ballRadius, player2);

				if (collision) {
					ballSpeed.x *= -1.0f;
					ballColor = player1Color;
				}

				if (collision2) {
					ballSpeed.x *= -1.0f;
					ballColor = player2Color;
				}

				if (points1 > 3) {
					endPoint1 = endPoint1 + 1;
					mach = !mach;
				}

				if (points2 > 3) {
					endPoint2 = endPoint2 + 1;
					mach = !mach;
				}

			}

			mause = GetMousePosition();
			exit_button = CheckCollisionCircleRec(mause, mauseradius, menu);
			retry_button = CheckCollisionCircleRec(mause, mauseradius, retry);

			if (exit_button) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					points1 = 0;
					points2 = 0;
					mach = !mach;
					inicio = !inicio;
				}
			}

			if (retry_button) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					points1 = 0;
					points2 = 0;
					mach = !mach;
				}
			}


		}


		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (inicio == false) {
			DrawCircleV(mause, mauseradius, mauseColor);
		}

		if (mach == false) {

			DrawRectangle(player1.x, player1.y, player1.width, player1.height, player1Color);
			DrawRectangle(player2.x, player2.y, player2.width, player2.height, player2Color);

			DrawCircleV(ballPosition, ballRadius, ballColor);

			DrawText(FormatText("Puntos: %i", points1), 10, 40, 20, LIGHTGRAY);
			DrawText(FormatText(" - %i", points2), 110, 40, 20, LIGHTGRAY);
		}

		if (mach == true) {
			DrawText(FormatText("Mach"), GetScreenWidth() / 2 - 80, 10, 50, LIGHTGRAY);
			DrawText(FormatText("Player 1: %i", endPoint1), 10, 200, 20, LIGHTGRAY);
			DrawText(FormatText("Player 2: %i", endPoint2), 10, 240, 20, LIGHTGRAY);


			DrawRectangle(menu.x, menu.y, menu.width, menu.height, RED);
			DrawRectangle(retry.x, retry.y, retry.width, retry.height, BLUE);
			DrawText(FormatText("Menu", points1), menu.x + 10, menu.y + 5, 30, LIGHTGRAY);
			DrawText(FormatText("Retry", points1), retry.x + 10, retry.y + 5, 30, LIGHTGRAY);
			DrawCircleV(mause, mauseradius, mauseColor);

		}


		//if (collision)ClearBackground(LIME);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}