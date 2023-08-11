#include"header.h"
#include"audio.h"
void Eat()
{
	EatSound();
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	SCORE++;
	if (FOOD_INDEX == MAX_SIZE_FOOD - 2)
		BonusSound();
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		DeleteGate();//xoa cong khi qua man moi
		if (LEVEL < 5)
		{
			LEVEL++;
			FOOD_INDEX = 0;
			SIZE_SNAKE = 6;
		}
		else
		{
			FOOD_INDEX = 0;
		}
		if (LEVEL == 2) {
			if (MOVING == 'A')
			{
				snake[5] = { 30, 5 }; snake[4] = { 31, 5 };	 //reset vi tri khi qua man moi va di ben trai
				snake[3] = { 32, 5 }; snake[2] = { 33, 5 };
				snake[1] = { 34, 5 }; snake[0] = { 35, 5 };
			}
			else
			{
				snake[0] = { 30, 5 }; snake[1] = { 31, 5 };	  //reset vi tri khi qua man moi cac huong con lai
				snake[2] = { 32, 5 }; snake[3] = { 33, 5 };
				snake[4] = { 34, 5 }; snake[5] = { 35, 5 };
			}
			Wall2();
		}
		if (LEVEL == 3)
		{
			if (MOVING == 'A')
			{
				snake[5] = { 30, 5 }; snake[4] = { 31, 5 };	 //reset vi tri khi qua man moi va di ben trai
				snake[3] = { 32, 5 }; snake[2] = { 33, 5 };
				snake[1] = { 34, 5 }; snake[0] = { 35, 5 };
			}
			else
			{
				snake[0] = { 30, 5 }; snake[1] = { 31, 5 };	  //reset vi tri khi qua man moi cac huong con lai
				snake[2] = { 32, 5 }; snake[3] = { 33, 5 };
				snake[4] = { 34, 5 }; snake[5] = { 35, 5 };
			}
			Wall3();
		}
		if (LEVEL == 4)
		{
			if (MOVING == 'A')
			{
				snake[5] = { 30, 5 }; snake[4] = { 31, 5 };	 //reset vi tri khi qua man moi va di ben trai
				snake[3] = { 32, 5 }; snake[2] = { 33, 5 };
				snake[1] = { 34, 5 }; snake[0] = { 35, 5 };
			}
			else
			{
				snake[0] = { 30, 5 }; snake[1] = { 31, 5 };	  //reset vi tri khi qua man moi cac huong con lai
				snake[2] = { 32, 5 }; snake[3] = { 33, 5 };
				snake[4] = { 34, 5 }; snake[5] = { 35, 5 };
			}
			Wall4();
		}
		if (LEVEL == 5 && CountDownR5 ==0)
		{
			Wall5();
			CountDownR5++;
		}
		else
		{
			if (LEVEL == 5)
			{
				SPEED += 4;
			}
			else
				SPEED++;
		}
		GenerateFood(FOOD_INDEX);
	}
	else
	{
		FOOD_INDEX++;
		SIZE_SNAKE++;
	}
	if (LEVEL == 2){
		ReDrawWall2();}//ve lai wall2 bi loi countdown, khi food < maxfoodsize
	if (LEVEL == 3) {
		ReDrawWall3();//ve lai wall3 bi loi countdown, khi food < maxfoodsize
	}
	if (LEVEL == 4) {
		ReDrawWall4();//ve lai wall4 bi loi countdown, khi food < maxfoodsize
	}
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);// ve lai board khi gap loi mat tuong sau khi spawn gate
}
void ProcessDead() {
	GameOverScreen();
	STATE = 0; // Ran da chet, ket thuc thread
	GotoXY(0, HEIGH_CONSOLE + 2);
	cout << "Dead, type y to continue or anykey to exit";
}
