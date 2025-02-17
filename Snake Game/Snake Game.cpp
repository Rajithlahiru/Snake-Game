#include <iostream>
#include <raylib.h>
using namespace std;
#include <deque>

Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

int cellSize = 30;
int cellCount = 25;

class Snake
{
public:
	deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };

	void Draw()
	{
		for(unsigned int i = 0; i < body.size(); i++)
		{
			float x = body[i].x;
			float y = body[i].y;
			Rectangle segment = { x * cellSize, y * cellSize, (float)cellSize, (float)cellSize };
			DrawRectangleRounded(segment, 0.8, 6, darkGreen);
		}
	
	}
};

class Food
{
public:
	Vector2 position;
	Texture2D texture;

	Food()
	{
		Image image = LoadImage("Graphic/food.png");
		texture = LoadTextureFromImage(image);
		UnloadImage(image);
		position = GetRandomPos();
	}

	~Food()
	{
		UnloadTexture(texture);
	}

	Vector2 GetRandomPos()
	{
		
		float x = GetRandomValue(0, cellCount - 1);
		float y = GetRandomValue(0, cellCount - 1);
		return Vector2{x,y};
	}

	void Draw()
	{
		DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
	}
};

int main()
{
    cout << "Starting the game ........ " << endl;
    InitWindow(cellCount* cellSize, cellSize*cellCount, "Snake Game");
	SetTargetFPS(60);

	Food food = Food();
	Snake snake = Snake();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Drawing
		ClearBackground(green);
		food.Draw();
		snake.Draw();

		EndDrawing();
	}

    CloseWindow();
	return 0;
}

