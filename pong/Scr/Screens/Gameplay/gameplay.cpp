#include "gameplay.h"

#include "raylib.h"

#include<iostream>

#include "Game/game.h"
#include "Screens/Controls/controls.h"


namespace gameplay {

	void initPlayer();
	void updateInput();
	void updateGame();
	void draw();

	game::GameScreen Screens;

	const int screenWidth = 800;
	const int screenHeight = 450;

	bool collision = false;
	bool collision2 = false;
	bool collisionPower = false;

	const int COLLIDER_RANGE = 100;

	bool collisionPower2 = false;
	bool collisionPower3 = false;
	bool collisionPower4 = false;
	bool collisionPower5 = false;
	bool collisionPower6 = false;

	bool inicio = false;
	bool mach = false;
	bool singlePlay = false;

	bool activePower;
	bool activePower2;
	bool activePower3;
	bool activePower4;
	int points1;
	int points2;

	int mauseradius;

	Wave wallWav;
	Wave playerWav;
	Sound playerColition;
	Sound wallColition;
	Music music;

	Rectangle player1;
	int count2;
	int endPoint1;
	bool lastPlayer1 = false;

	Rectangle player2;
	int endPoint2;
	bool lastPlayer2 = false;

	Rectangle power1;
	Rectangle power2;
	Rectangle power3;
	Rectangle power4;

	Vector2 powerSpeed1;
	Vector2 powerSpeed2;
	Vector2 powerSpeed3;
	Vector2 powerSpeed4;

	Rectangle retry;
	Rectangle menu;

	Rectangle menu_button;

	Rectangle shield;
	Rectangle shield2;

	Rectangle obstacle;
	Rectangle obstacle2;

	bool shieldActive = false;
	bool shieldActive2 = false;
	bool collisionShield = false;
	bool collisionShield2 = false;
	bool obstacleActive = false;
	bool collisionObstacle = false;
	bool collisionObstacle2 = false;

	Texture2D background;
	Vector2 mause;
	Color mauseColor;

	Vector2 ballPosition;
	Vector2 ballSpeed;
	Vector2 ballSpeedRef;
	Color ballColor;
	int ballRadius;
	Vector2 pointTop;
	Vector2 pointBot;
	Vector2 pointLeft;
	Vector2 pointRigth;

	int impact;
	bool off = true;
	float time;

	void initPoints() {

		endPoint1 = 0;

		endPoint2 = 0;

	}

	void initPlayer() {

		player1.height = 80;
		player1.width = 10;


		player2.height = 80;
		player2.width = 10;
	}

	void initGame() {

		//inicia el audio

		InitWindow(screenWidth, screenHeight, "PONG");

		background = LoadTexture("../res/assets/images/Background.png");

		if (off == true) {
			wallWav = LoadWave("../res/assets/sounds/Wall_colition.wav");
			playerWav = LoadWave("../res/assets/sounds/Player_colition.wav");

			playerColition = LoadSoundFromWave(playerWav);
			wallColition = LoadSoundFromWave(wallWav);
			music = LoadMusicStream("../res/assets/sounds/Electronic Fantasy.ogg");
		}

		mause = { -100.0f, -100.0f };
		mauseColor = DARKBLUE;

		initPlayer();

		player1.x = static_cast<float>(screenWidth) / 6 - 90;
		player1.y = static_cast<float>(screenHeight) / 4 + 50;

		player2.x = static_cast<float>(screenWidth) - 50;
		player2.y = static_cast<float>(screenHeight) / 4 + 50;

		points1 = 0;
		points2 = 0;

		//Botones
		menu.height = 40;
		menu.width = 90;
		menu.x = static_cast<float>(screenWidth) / 2 + 80;
		menu.y = static_cast<float>(screenHeight) / 4 + 50;

		retry.height = 40;
		retry.width = 100;
		retry.x = static_cast<float>(screenWidth) / 2 + 80;
		retry.y = static_cast<float>(screenHeight) / 4 + 100;

		menu_button.x = static_cast<float>(GetScreenWidth()) - 100;
		menu_button.y = 0;
		menu_button.height = 50;
		menu_button.width = 100;

		//escudo
		shield.x = 0;
		shield.y = 0;
		shield.width = 20;
		shield.height = static_cast<float>(GetScreenHeight());

		shield2.x = static_cast<float>(GetScreenWidth()) - 20;
		shield2.y = 0;
		shield2.width = 20;
		shield2.height = static_cast<float>(GetScreenHeight());

		//pelota
		ballPosition = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
		ballSpeed = { 6.0f, 4.0f };
		ballSpeedRef = ballSpeed;
		ballColor = MAROON;
		ballRadius = 20;
		pointRigth = { (ballPosition.x + ballRadius), ballPosition.y };
		pointTop = { ballPosition.x, (ballPosition.y + ballRadius) };
		pointBot = { ballPosition.x, (ballPosition.y - ballRadius) };
		pointLeft = { (ballPosition.x - ballRadius), ballPosition.y };

		impact = 0;

		//power ups
		power1.height = 20;
		power1.width = 20;
		power1.x = 100;
		power1.y = 100;

		power2.height = 20;
		power2.width = 20;
		power2.x = static_cast<float>(GetScreenWidth()) / 2 + 240;
		power2.y = static_cast<float>(GetScreenHeight()) / 2 + 120;

		power3.height = 20;
		power3.width = 20;
		power3.x = static_cast<float>(GetScreenWidth()) / 2 + 140;
		power3.y = static_cast<float>(GetScreenHeight()) + 99;

		power4.height = 20;
		power4.width = 20;
		power4.x = static_cast<float>(GetScreenWidth()) / 2 + 100;
		power4.y = static_cast<float>(GetScreenHeight()) / 2;

		powerSpeed1 = { 6.0f, 4.0f };
		powerSpeed2 = { 6.0f, 2.0f };
		powerSpeed3 = { 10.0f, 8.0f };
		powerSpeed4 = { 10.0f, 8.0f };

		//obstaculos	
		obstacle.height = 100;
		obstacle.width = 20;
		obstacle.x = static_cast<float>(GetScreenWidth()) / 2 + 100;
		obstacle.y = static_cast<float>(0);

		obstacle2.height = 100;
		obstacle2.width = 20;
		obstacle2.x = static_cast<float>(GetScreenWidth()) / 2 - 100;
		obstacle2.y = static_cast<float>(GetScreenHeight()) - 100;

		mauseradius = 10;

		activePower = true;
		activePower2 = true;
		activePower3 = true;
		activePower4 = true;

		//timer
		time = 0;

		SetTargetFPS(60);
	}

	void unload() {
		UnloadSound(wallColition);
		UnloadWave(wallWav);
		UnloadWave(playerWav);
		UnloadSound(playerColition);
		UnloadMusicStream(music);
		UnloadTexture(background);
		CloseAudioDevice();
	}

	static void updateInput() {

		if (IsKeyPressed(32)) inicio = !inicio;

		if (inicio == false) {

			mause = GetMousePosition();

			if (IsKeyPressed(KEY_ENTER)) singlePlay = !singlePlay;

		}

		if (inicio) {

			if (mach == false) {
				if (singlePlay == false) {
					//controles del jugaDOR
						//jugador 1
					if (IsKeyDown(controls::upPlayer1)) {

						if (player1.y > 0) {

							player1.y -= 5.0f;

						}
					}

					if (IsKeyDown(controls::downPlayer1)) {

						if (player1.y + player1.y / 2 - 50 < GetScreenHeight()) {

							player1.y += 5.0f;

						}
					}

					//jugador 2
					if (IsKeyDown(controls::upPlayer2)) {

						if (player2.y > 0) {

							player2.y -= 5.0f;

						}
					}

					if (IsKeyDown(controls::downPlayer2)) {

						if (player2.y + player2.y / 2 - 50 < GetScreenHeight()) {

							player2.y += 5.0f;

						}
					}
				}
				else {
					if (IsKeyDown(controls::upPlayer1)) {

						if (player1.y > 0) {

							player1.y -= 5.0f;

						}
					}

					if (IsKeyDown(controls::downPlayer1)) {

						if (player1.y + player1.y / 2 - 50 < GetScreenHeight()) {

							player1.y += 5.0f;

						}
					}

					if (player2.y < ballPosition.y) {

						if (player2.y + player2.y / 2 - 50 < GetScreenHeight()) {

							player2.y += 3.0f;

						}
					}

					if (player2.y > ballPosition.y) {

						if (player2.y > 0) {

							player2.y -= 3.0f;

						}
					}
				}
			}
		}

		if (CheckCollisionPointRec(mause, menu_button)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				initPoints();
				initGame();
				game::Screens = game::Menu;

			}
		}

		if (mach == true) {

			if (CheckCollisionPointRec(mause, menu)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

					initPoints();
					initGame();
					mach = !mach;
					inicio = !inicio;
					game::Screens = game::Menu;

				}
			}


			if (CheckCollisionPointRec(mause, retry)) {

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

					initGame();
					mach = !mach;
					inicio = !inicio;

				}
			}
		}
	}

	static void updateGame() {

		UpdateMusicStream(music);
		PlayMusicStream(music);

		if (inicio) {

			if (mach == false) {

				//CONTROL DE PUNTOS
				if (ballPosition.x <= ballRadius) {

					points1 = points1 + 1;
					ballPosition.x = screenWidth / 2;
					ballPosition.y = screenHeight / 2;
					ballSpeed = ballSpeedRef;
					initPlayer();

				}

				if (ballPosition.x >= GetScreenWidth() - ballRadius) {

					points2 = points2 + 1;
					ballPosition.x = screenWidth / 2;
					ballPosition.y = screenHeight / 2;
					ballSpeed = ballSpeedRef;
					initPlayer();

				}

				//MOVIMIENTO DE LA PELOTA/

				ballPosition.x += ballSpeed.x;
				ballPosition.y += ballSpeed.y;
				/*
				pointRigth = { (ballPosition.x + ballRadius), ballPosition.y };
				pointTop = { ballPosition.x, (ballPosition.y + ballRadius) };
				pointBot = { ballPosition.x, (ballPosition.y - ballRadius) };
				pointLeft = { (ballPosition.x - ballRadius), ballPosition.y };
				*/
				//ballPosition = mause;
				//movimiento de power up
				power1.y += powerSpeed1.y;
				power2.y += powerSpeed2.y;
				power3.y += powerSpeed3.y;
				power4.y += powerSpeed3.y;


				// colicion con paredes
				if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) {

					ballSpeed.x *= -1.0f;
					PlaySound(wallColition);

				}
				if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) {

					ballSpeed.y *= -1.0f;
					PlaySound(wallColition);

				}

				//limites de los power up
				if ((power1.y >= GetScreenHeight())) powerSpeed1.y *= -1.0f;
				if (power1.y < 0) powerSpeed1.y *= -1.0f;
				if ((power2.y >= GetScreenHeight())) powerSpeed2.y *= -1.0f;
				if (power2.y < 0) powerSpeed2.y *= -1.0f;
				if ((power3.y >= GetScreenHeight() + 100)) powerSpeed3.y *= -1.0f;
				if (power3.y < -100) powerSpeed3.y *= -1.0f;
				if ((power4.y >= GetScreenHeight())) powerSpeed4.y *= -1.0f;
				if (power4.y < 0) powerSpeed4.y *= -1.0f;

				//COLICION DE JUGADORES

				collision = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), player1);
				collision2 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), player2);

				collisionObstacle = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), obstacle);
				collisionObstacle2 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), obstacle2);

				if (collision) {

					ballSpeed.x *= -1.0f;
					ballColor = controls::player1Color;
					PlaySound(playerColition);
					lastPlayer1 = true;
					lastPlayer2 = false;

				}

				if (collision2) {

					ballSpeed.x *= -1.0f;
					ballColor = controls::player2Color;
					PlaySound(playerColition);
					lastPlayer1 = false;
					lastPlayer2 = true;
				}

				if (collisionObstacle) {
					ballSpeed.x *= -1.0f;
				}

				if (collisionObstacle2) {
					ballSpeed.x *= -1.0f;
				}
				//colicion de poder
				collisionPower = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), power1);
				collisionPower2 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), power2);
				collisionPower3 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), power3);
				collisionPower4 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), power4);

				if (activePower == true) {

					if (collisionPower) {

						if (lastPlayer1)player1.height = 120;

						if (lastPlayer2)player2.height = 120;
						activePower = !activePower;

					}
				}

				if (activePower2 == true) {

					if (collisionPower2) {

						ballSpeed.x = ballSpeed.x * 2;
						ballSpeed.y = ballSpeed.y * 2;
						activePower2 = !activePower2;

					}
				}

				if (activePower3 == true) {

					if (collisionPower3) {

						if (lastPlayer1)shieldActive = true;
						if (lastPlayer2)shieldActive2 = true;;
						activePower3 = false;
					}
				}

				if (activePower4 == true) {

					if (collisionPower4) {
						obstacleActive = !obstacleActive;
						activePower4 = false;
						time += GetFrameTime();

						if (time >= 2) {
							obstacleActive = !obstacleActive;
							time = 0;
						}
					}
				}

				//collision shield
				if (shieldActive == true)collisionShield = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), shield);
				if (shieldActive2 == true)collisionShield2 = CheckCollisionCircleRec(ballPosition, static_cast<float>(ballRadius), shield2);

				if (collisionShield) {
					ballSpeed.x *= -1.0f;
					shieldActive = false;
				}

				if (collisionShield2) {
					ballSpeed.x *= -1.0f;
					shieldActive2 = false;
				}

				//chequea los puntos para terminar el mach
				{
					if (points1 > 3) {

						endPoint1 = endPoint1 + 1;
						activePower = true;
						activePower2 = true;
						activePower3 = true;
						activePower4 = true;
						mach = !mach;

					}

					if (points2 > 3) {

						endPoint2 = endPoint2 + 1;
						activePower = true;
						activePower2 = true;
						activePower3 = true;
						activePower4 = true;
						mach = !mach;

					}
				}
			}

			mause = GetMousePosition();

		}
	}
	static void draw() {

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(background, 0, 0, WHITE);

		if (mach == false) {

			//Dibujo de power up

			if (activePower == true) {

				DrawRectangle(static_cast<int>(power1.x), static_cast<int>(power1.y), static_cast<int>(power1.width), static_cast<int>(power1.height), RED);

			}
			if (activePower2 == true) {

				DrawRectangle(static_cast<int>(power2.x), static_cast<int>(power2.y), static_cast<int>(power2.width), static_cast<int>(power2.height), SKYBLUE);

			}
			if (activePower3 == true) {

				DrawRectangle(static_cast<int>(power3.x), static_cast<int>(power3.y), static_cast<int>(power3.width), static_cast<int>(power3.height), DARKBROWN);

			}
			if (activePower4 == true) {

				DrawRectangle(static_cast<int>(power4.x), static_cast<int>(power4.y), static_cast<int>(power4.width), static_cast<int>(power4.height), GOLD);

			}
			if (shieldActive == true) {

				DrawRectangle(static_cast<int>(shield.x), static_cast<int>(shield.y), static_cast<int>(shield.width), static_cast<int>(shield.height), SKYBLUE);

			}
			if (shieldActive2 == true) {

				DrawRectangle(static_cast<int>(shield2.x), static_cast<int>(shield2.y), static_cast<int>(shield2.width), static_cast<int>(shield2.height), SKYBLUE);

			}
			if (obstacleActive == true) {
				DrawRectangle(static_cast<int>(obstacle.x), static_cast<int>(obstacle.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), controls::player2Color);
				DrawRectangle(static_cast<int>(obstacle2.x), static_cast<int>(obstacle2.y), static_cast<int>(obstacle2.width), static_cast<int>(obstacle2.height), controls::player2Color);

			}

			if (inicio == false) {

				DrawCircleV(mause, static_cast<float>(mauseradius), mauseColor);
				DrawText(FormatText("Presione ESPACIO para empezar", points1), 10, 300, 20, BLACK);
				DrawText(FormatText("Presione ENTER para activar single palyer", points1), 10, 350, 20, BLACK);
				DrawRectangle(static_cast<int>(menu_button.x), static_cast<int>(menu_button.y), static_cast<int>(menu_button.width), static_cast<int>(menu_button.height), BLACK);
				DrawText("Menu", static_cast<int>(menu_button.x) + 18, static_cast<int>(menu_button.y) + 10, 20, WHITE);

			}

			DrawRectangle(static_cast<int>(player1.x), static_cast<int>(player1.y), static_cast<int>(player1.width), static_cast<int>(player1.height), controls::player1Color);
			DrawRectangle(static_cast<int>(player2.x), static_cast<int>(player2.y), static_cast<int>(player2.width), static_cast<int>(player2.height), controls::player2Color);

			DrawRectangleRec(player1, controls::player1Color);
			DrawRectangleRec(player2, controls::player2Color);


			DrawCircleV(ballPosition, static_cast<float>(ballRadius), ballColor);

			DrawText(FormatText("Puntos: %i", points1), 10, 40, 20, LIGHTGRAY);
			DrawText(FormatText(" - %i", points2), 110, 40, 20, LIGHTGRAY);

		}

		//Dibujo de pantalla de victoria

		if (mach == true) {

			DrawText(FormatText("Mach"), GetScreenWidth() / 2 - 80, 10, 50, LIGHTGRAY);
			DrawText(FormatText("Player 1: %i", endPoint2), 10, 200, 20, LIGHTGRAY);
			DrawText(FormatText("Player 2: %i", endPoint1), 10, 240, 20, LIGHTGRAY);


			DrawRectangle(static_cast<int>(menu.x), static_cast<int>(menu.y), static_cast<int>(menu.width), static_cast<int>(menu.height), RED);
			DrawRectangle(static_cast<int>(retry.x), static_cast<int>(retry.y), static_cast<int>(retry.width), static_cast<int>(retry.height), BLUE);
			DrawText(FormatText("Menu", points1), static_cast<int>(menu.x) + 10, static_cast<int>(menu.y) + 5, 30, LIGHTGRAY);
			DrawText(FormatText("Retry", points1), static_cast<int>(retry.x) + 10, static_cast<int>(retry.y) + 5, 30, LIGHTGRAY);
			DrawCircleV(mause, static_cast<float>(mauseradius), mauseColor);

		}

		EndDrawing();
	}

	void updateFrame() {

		updateInput();
		updateGame();
		draw();

	}
}



