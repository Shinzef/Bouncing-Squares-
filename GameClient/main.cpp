#include <raylib.h>
#include <string>

// make a bouncing square
int main()
{
	// stuff
	const int screenWidth = 1000;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Bouncing Square 2"); // 3 bouncing squares not the sequel to bouncing square

	// set up the square 1 
	Rectangle square = { screenWidth / 2, screenHeight / 2, 50, 50 };
	Vector2 squareSpeed = { 1, 1 }; // or change this if you want the square to move faster or slower

	// set up the square 2
	Rectangle square2 = { screenWidth / 2, screenHeight / 2, 50, 50 };
	Vector2 square2Speed = { 1.5, 1.5 }; // or change this if you want the square to move faster or slower

	// set up the square 3
	Rectangle square3 = { screenWidth / 2, screenHeight / 2, 50, 50 };
	Vector2 square3Speed = { 2, 2 }; // or change this if you want the square to move faster or slower

	int countOfBounceSquare1 = 0; // count the number of times the square1 has bounced
	int countOfBounceSquare2 = 0; // count the number of times the square2 has bounced
	int countOfBounceSquare3 = 0; // count the number of times the square3 has bounced

	int frameCount = 0; // count the number of frames
	bool pause = false;
	char pauseText[10] = "pause";
	
	SetTargetFPS(240); // change this if you want the square to move faster or slower
	// end of stuff

	// main loop
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			pause = !pause; // toggle pause
		}

		if (!pause)
		{
			// square 1
			square.x += squareSpeed.x;
			square.y += squareSpeed.y;

			if (square.x <= 0 || square.x + square.width >= screenWidth) // if square hits the left or right wall
			{
				squareSpeed.x *= -1; // reverse direction
			}
			if (square.y <= 0 || square.y + square.height >= screenHeight) // if square hits the top or bottom wall
			{
				squareSpeed.y *= -1; // reverse direction
			}
			else
			{
				++frameCount; // count the number of frames
			}
			// end of square 1

			// start of square 2
			square2.x += square2Speed.x;
			square2.y += square2Speed.y;

			if(square2.x <= 0 || square2.x + square2.width >= screenWidth) // if square hits the left or right wall
			{
				square2Speed.x *= -1; // reverse direction
			}
			if(square2.y <= 0 || square2.y + square2.height >= screenHeight) // if square hits the top or bottom wall
			{
				square2Speed.y *= -1; // reverse direction
			}
			else
			{
				++frameCount; // count the number of frames
			}
			//end of square 2

			// start of square 3
			square3.x += square3Speed.x;
			square3.y += square3Speed.y;

			if(square3.x <= 0 || square3.x + square3.width >= screenWidth) // if square hits the left or right wall
			{
				square3Speed.x *= -1; // reverse direction
			}
			if(square3.y <= 0 || square3.y + square3.height >= screenHeight) // if square hits the top or bottom wall
			{
				square3Speed.y *= -1; // reverse direction
			}
			else
			{
				++frameCount; // count the number of frames
			}
			// end of square 3

			// if square hits other squares bounce off


			if ( frameCount > 480 ) // change this depends on your targetFPS
			{
				if (CheckCollisionRecs(square, square2))
				{
					squareSpeed.x *= -1;
					square2Speed.x *= -1;
					++countOfBounceSquare1;
					++countOfBounceSquare2;
				}
				if (CheckCollisionRecs(square, square3))
				{
					squareSpeed.x *= -1;
					square3Speed.x *= -1;
					++countOfBounceSquare1;
					++countOfBounceSquare3;
				}
				if (CheckCollisionRecs(square2, square3))
				{
					square2Speed.x *= -1;
					square3Speed.x *= -1;
					++countOfBounceSquare2;
					++countOfBounceSquare3;
				}
			}
		}

		// end of main loop
		// now drawing stuff

		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawRectangle(square.x, square.y, square.width, square.height, RED);
		    DrawRectangle(square2.x, square2.y, square2.width, square2.height, GREEN);
			DrawRectangle(square3.x, square3.y, square3.width, square3.height, BLUE);
			// RGB lez goo more fps

			DrawText(TextFormat("Press enter to %s", pauseText), 10, 40, 20, BLACK);

			// print the bounces of each square
			DrawText(TextFormat("Count of bounces of square 1: %i", countOfBounceSquare1), 820, 590, 10, BLACK);
			DrawText(TextFormat("Count of bounces of square 2: %i", countOfBounceSquare2), 820, 580, 10, BLACK);
			DrawText(TextFormat("Count of bounces of square 3: %i", countOfBounceSquare3), 820, 570, 10, BLACK);

			if (pause)
			{
				

				strcpy_s(pauseText, "unpause");



				DrawText("PAUSED", GetScreenWidth() / 2 - MeasureText("PAUSED", 20) / 2, GetScreenHeight() / 2 - 20, 20, BLACK);
			}
			else
			{
				strcpy_s(pauseText, "pause");
			}

			DrawFPS(10, 10);

		EndDrawing();
		// drawing stuff done
	}
	CloseWindow();

	return 0;
}