#include"header.h"

void Wall2()//dung trong eat
{
	int temp = 17;
	int temp2 = 0;
	for (int i = 0; i <= 37; i++)
	{
		WALL2[i].x = temp;
		WALL2[i].y = HEIGH_CONSOLE / 2+1;
		GotoXY(temp, HEIGH_CONSOLE / 2+1);
		cout << "X";
		temp++;
	}
		Countdown();
}
void ReDrawWall2()//dung trong eat, ve lai wall2 vi wall2 bi loi countdown vong lap
{
	int temp = 17;
	for (int i = 0; i <= 37; i++)
	{
		WALL2[i].x = temp;
		WALL2[i].y = HEIGH_CONSOLE / 2 + 1;
		GotoXY(temp, HEIGH_CONSOLE / 2 + 1);
		cout << "X";
		temp++;
	}
}
void Wall3()
{
	for (int i = 0; i <= 37; i++)
	{
		GotoXY(WALL2[i].x, WALL2[i].y);
			cout << " ";
	}
	int tempw = 19;
	int temph = 7;
	for (int i = 0; i <= 12; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		temph++;
	}
	tempw = 52;
	temph = 7;
	for (int i = 13; i <= 25; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		temph++;
	}
	Countdown();
}
void ReDrawWall3()
{
	int tempw = 19;
	int temph = 7;
	for (int i = 0; i <= 12; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		temph++;
	}
	tempw = 52;
	temph = 7;
	for (int i = 13; i <= 25; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		temph++;
	}
}
void Wall4()
{
	int tempw = 19;
	int temph = 7;
	for (int i = 0; i <= 12; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		temph++;
	}
	tempw = 52;
	temph = 7;
	for (int i = 13; i <= 25; i++)
	{
		WALL3[i].x = tempw;
		WALL3[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		temph++;
	}
	 tempw = 0;
	 temph = HEIGH_CONSOLE / 4;
	for (int i = 0; i <= 60; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw += 5;
	for (int i = 61; i <= 64; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw = 29;
	temph = HEIGH_CONSOLE / 2-1;
	for (int i = 65; i <= 105; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw = 1;
	temph = HEIGH_CONSOLE * 3 / 4;
	for (int i = 105; i <= 168; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	Countdown();
}
void ReDrawWall4()
{
	int tempw = 0;
	int temph = HEIGH_CONSOLE / 4;
	for (int i = 0; i <= 60; i++)
	{
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw += 5;
	for (int i = 61; i <= 64; i++)
	{
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw = 29;
	temph = HEIGH_CONSOLE / 2-1;
	for (int i = 65; i <= 105; i++)
	{
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
	tempw = 1;
	temph = HEIGH_CONSOLE * 3 / 4;
	for (int i = 105; i <= 168; i++)
	{
		GotoXY(tempw, temph);
		cout << "X";
		tempw++;
	}
}
void Wall5()
{
	int tempw = 0;
	int temph = HEIGH_CONSOLE / 4;
	for (int i = 0; i <= 60; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		tempw++;
	}
	tempw += 5;
	for (int i = 61; i <= 64; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		tempw++;
	}
	tempw = 29;
	temph = HEIGH_CONSOLE / 2 - 1;
	for (int i = 65; i <= 105; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		tempw++;
	}
	tempw = 1;
	temph = HEIGH_CONSOLE * 3 / 4;
	for (int i = 105; i <= 168; i++)
	{
		WALL4[i].x = tempw;
		WALL4[i].y = temph;
		GotoXY(tempw, temph);
		cout << " ";
		tempw++;
	}
	Countdown();
}
