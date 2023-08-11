#include"header.h";
#include"audio.h"

void MoveRight() {
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x + 1 == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
		{
			DeadSound();
			FlashSnake();
			ProcessDead();

		}
	}
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		for (int i = 0; i < 14; i++)
		{
			if (snake[SIZE_SNAKE - 1].x + 1 == gate[i].x && snake[SIZE_SNAKE - 1].y == gate[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();

			}
		}
	}
	if (LEVEL == 2)
	{
		for (int i = 0; i < 38; i++)
		{
			if (snake[SIZE_SNAKE - 1].x + 1 == WALL2[i].x && snake[SIZE_SNAKE - 1].y == WALL2[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 3)
	{
		for (int i = 0; i < 26; i++)
		{
			if (snake[SIZE_SNAKE - 1].x + 1 == WALL3[i].x && snake[SIZE_SNAKE - 1].y == WALL3[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 4)
	{
		for (int i = 0; i < 169; i++)
		{
			if (snake[SIZE_SNAKE - 1].x + 1 == WALL4[i].x && snake[SIZE_SNAKE - 1].y == WALL4[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE) {
		DeadSound();
		FlashSnake();
		ProcessDead();
	}
	else {
		if (LEVEL <= 5)
		{
			if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
				Eat();
			}
			for (int i = 0; i < SIZE_SNAKE - 1; i++) {
				snake[i].x = snake[i + 1].x;
				snake[i].y = snake[i + 1].y;
			}
			snake[SIZE_SNAKE - 1].x++;
		}

	}
}
void MoveLeft() {
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x - 1 == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
		{
			DeadSound();
			FlashSnake();
			ProcessDead();
		}
	}
	if (LEVEL == 2)
	{
		for (int i = 0; i < 38; i++)
		{
			if (snake[SIZE_SNAKE - 1].x - 1 == WALL2[i].x && snake[SIZE_SNAKE - 1].y == WALL2[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 3)
	{
		for (int i = 0; i < 26; i++)
		{
			if (snake[SIZE_SNAKE - 1].x - 1 == WALL3[i].x && snake[SIZE_SNAKE - 1].y == WALL3[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 4)
	{
		for (int i = 0; i < 169; i++)
		{
			if (snake[SIZE_SNAKE - 1].x - 1 == WALL4[i].x && snake[SIZE_SNAKE - 1].y == WALL4[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		for (int i = 0; i < 14; i++)
		{
			if (snake[SIZE_SNAKE - 1].x - 1 == gate[i].x && snake[SIZE_SNAKE - 1].y == gate[i].y)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();

			}
		}
	}
	if (snake[SIZE_SNAKE - 1].x - 1 == 0) {
		DeadSound();
		FlashSnake();
		ProcessDead();

	}
	else {
		if (LEVEL <= 5) {
			if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
				Eat();
			}
			for (int i = 0; i < SIZE_SNAKE - 1; i++) {
				snake[i].x = snake[i + 1].x;
				snake[i].y = snake[i + 1].y;
			}
			snake[SIZE_SNAKE - 1].x--;
		}
	}

}
void MoveDown() {
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].y + 1 == snake[i].y && snake[SIZE_SNAKE - 1].x == snake[i].x)
		{
			DeadSound();
			FlashSnake();
			ProcessDead();

		}
	}
	if (LEVEL == 2)
	{
		for (int i = 0; i < 38; i++)
		{
			if (snake[SIZE_SNAKE - 1].y + 1 == WALL2[i].y && snake[SIZE_SNAKE - 1].x == WALL2[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 3)
	{
		for (int i = 0; i < 26; i++)
		{
			if (snake[SIZE_SNAKE - 1].y + 1 == WALL3[i].y && snake[SIZE_SNAKE - 1].x == WALL3[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 4)
	{
		for (int i = 0; i < 169; i++)
		{
			if (snake[SIZE_SNAKE - 1].y + 1 == WALL4[i].y && snake[SIZE_SNAKE - 1].x == WALL4[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		for (int i = 0; i < 14; i++)
		{
			if (snake[SIZE_SNAKE - 1].y + 1 == gate[i].y && snake[SIZE_SNAKE - 1].x == gate[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();

			}
		}
	}
	if (snake[SIZE_SNAKE - 1].y + 1 == HEIGH_CONSOLE) {
		DeadSound();
		FlashSnake();
		ProcessDead();

	}
	else {
		if (LEVEL <= 5) {
			if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y)
			{
				Eat();
			}
			for (int i = 0; i < SIZE_SNAKE - 1; i++) {
				snake[i].x = snake[i + 1].x;
				snake[i].y = snake[i + 1].y;
			}
			snake[SIZE_SNAKE - 1].y++;
		}
	}
}
void MoveUp() {
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].y - 1 == snake[i].y && snake[SIZE_SNAKE - 1].x == snake[i].x)
		{
			DeadSound();
			FlashSnake();
			ProcessDead();

		}
	}
	if (LEVEL == 2)
	{
		for (int i = 0; i < 38; i++)
		{
			if (snake[SIZE_SNAKE - 1].y - 1 == WALL2[i].y && snake[SIZE_SNAKE - 1].x == WALL2[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 3)
	{
		for (int i = 0; i < 26; i++)
		{
			if (snake[SIZE_SNAKE - 1].y - 1 == WALL3[i].y && snake[SIZE_SNAKE - 1].x == WALL3[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (LEVEL == 4)
	{
		for (int i = 0; i < 26; i++)
		{
			if (snake[SIZE_SNAKE - 1].y - 1 == WALL4[i].y && snake[SIZE_SNAKE - 1].x == WALL4[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();
			}
		}
	}
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		for (int i = 0; i < 14; i++)
		{
			if (snake[SIZE_SNAKE - 1].y - 1 == gate[i].y && snake[SIZE_SNAKE - 1].x == gate[i].x)
			{
				DeadSound();
				FlashSnake();
				ProcessDead();

			}
		}
	}
	if (snake[SIZE_SNAKE - 1].y - 1 == 0) {
		DeadSound();
		FlashSnake();
		ProcessDead();
	}
	else {
		if (LEVEL <= 5) {
			if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
			{
				Eat();
			}
			for (int i = 0; i < SIZE_SNAKE - 1; i++) {
				snake[i].x = snake[i + 1].x;
				snake[i].y = snake[i + 1].y;
			}
			snake[SIZE_SNAKE - 1].y--;
		}
	}

}