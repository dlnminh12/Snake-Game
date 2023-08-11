#include"header.h";
 POINT snake[50]; //snake
 POINT food[7]; // food
 POINT gate[14];//draw
 POINT WALL2[38];//wall
 POINT WALL3[26];//wall
 POINT WALL4[169];//wall
 int CHAR_LOCK;//used to determine the direction my snake cannot move (At a moment, there is one direction my snake cannot move to)
 int MOVING;//used to determine the direction my snake moves (At a moment, there are three directions my snake can move)
 int SPEED;// Standing for level, the higher the level, the quicker the speed
 int HEIGH_CONSOLE, WIDTH_CONSOLE;// Width and height of console-screen
 int FOOD_INDEX; // current food-index
 int SIZE_SNAKE; // size of snake, initially maybe 6 units and maximum size maybe
 int STATE; // State of snake: dead or alive
 int SCORE;
 int HIGHSCORE;
 int LEVEL;
 int MUSIC_OPS;
 int SFX_OPS;
 int MENUCHOICE;
 int CountDownR5; // dem nguoc round 5 1 lan vi round 5 la vo han

 void main()
{
		FixConsoleWindow();
		MUSIC_OPS = 1;
		SFX_OPS = 1;
		MENUCHOICE = 1;
		CountDownR5 = 0;
		LoadingBar();
		Menu1();
	    int temp;
		thread t1(ThreadFunc); //Create thread for snake
		HANDLE handle_t1 = t1.native_handle(); //Take handle of thread
		while (1) {
			temp = toupper(_getch());
		
			if (STATE == 1)
			{
				if (temp == 'P')
				{
					ToggleSound();
					PauseGame(handle_t1);
				}
				else if (temp == 27)
				{
					ToggleSound();
					ExitGame(handle_t1);

				}
				else if (temp == 'T')
				{
					ToggleSound();
					SavenLoad(SCORE, LEVEL, SIZE_SNAKE, FOOD_INDEX, SPEED, food[FOOD_INDEX],snake,handle_t1);
				}
				else
				{
					ResumeThread(handle_t1);
					if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
					{
						if (temp == 'D') CHAR_LOCK = 'A';
						else if (temp == 'W') CHAR_LOCK = 'S';
						else if (temp == 'S') CHAR_LOCK = 'W';
						else CHAR_LOCK = 'D';
						MOVING = temp;
					}
				}
			}

			else
			{
				for (int i = 0; i < SIZE_SNAKE; i++) {
					GotoXY(snake[i].x, snake[i].y);
					cout << " ";
				}
				if (temp == 'Y')
					StartGame();
				else
				{
					system("cls");
					Menu1();
				}
			}
		}
}