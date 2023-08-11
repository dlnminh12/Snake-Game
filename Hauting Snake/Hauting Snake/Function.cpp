#include"header.h"
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool IsValid(int x, int y) {
	for (int i = 0; i < SIZE_SNAKE; i++) {//food ko trung snake
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	if (LEVEL == 1)//gate ko trung wall2
	{
		for (int i = 0; i <= 37; i++)
		{
			if (WALL2[i].x == x && WALL2[i].y == y)
				return false;
		}
	}
	if (LEVEL == 2) {//food khong trung wall2 va gate ko trung wall3
		for (int i = 0; i <= 37; i++)
		{
			if (WALL2[i].x == x && WALL2[i].y == y)
				return false;
		}
		if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
		{
			for (int i = 0; i <= 25; i++)
			{
				if (WALL3[i].x == x && WALL3[i].y == y)
					return false;
			}
		}
	}
	if (LEVEL == 3) {//food khong trung wall3 va gate ko trung wall4
		for (int i = 0; i <= 25; i++)
		{
			if (WALL3[i].x == x && WALL3[i].y == y)
				return false;
		}
		if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
		{
			for (int i = 0; i <= 168; i++)
			{
				if (WALL4[i].x == x && WALL4[i].y == y)
					return false;
			}
		}
	}
	if (LEVEL == 4) {
		for (int i = 0; i <= 168; i++)
		{
			if (WALL4[i].x == x && WALL4[i].y == y)
				return false;
		}
	}
	return true;
}
void ResetData() {
	//Initialize the global values
	SCORE = 0;
	LEVEL = 1;
	GetHighScore(HIGHSCORE);
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 10; FOOD_INDEX = 0, WIDTH_CONSOLE = 70, HEIGH_CONSOLE = 25, SIZE_SNAKE = 6;
	// Initialize default values for snake
	snake[0] = { 10, 5 }; snake[1] = { 11, 5 };
	snake[2] = { 12, 5 }; snake[3] = { 13, 5 };
	snake[4] = { 14, 5 }; snake[5] = { 15, 5 };
	GenerateFood(FOOD_INDEX);//Create food array
}
void StartGame() {
	system("cls");
	ResetData(); // Intialize original data
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	Countdown();
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	STATE = 1;//Start running Thread
}
//Function exit game
void ExitGame(HANDLE t) {
	SuspendThread(t);
	char choice;
	choice= _getch();
	if (choice == 'y')
	{
		STATE = 0;
		system("cls");
		Menu1();
		ResumeThread(t);
	}
	else
	{
		ResumeThread(t);
	}
	return;
}
//Function pause game
void PauseGame(HANDLE t) {
	SuspendThread(t);
}
void ThreadFunc() {
	int z = 0;
	while (1) {
		if (STATE == 1) {//If my snake is alive
			DrawBack(" ");
			switch (MOVING) {
			case 'A':
				MoveLeft();
			
				break;
			case 'D':
				MoveRight();
				
				break;
			case 'W':
				MoveUp();
				
				break;
			case 'S':
				MoveDown();
				
				break;
			}
			DrawScore();
			DrawFood("*");
			DrawSnake();
			DrawLevel();
			DrawIngameIns();
			Sleep(1000 / SPEED);//Sleep function with SPEEED variable
		}
	}
}
void SavenLoad(int SCORE, int LEVEL, int SIZE_SNAKE, int FOOD_INDEX, int SPEED, POINT food, POINT snake[], HANDLE t)
{
	system("cls");
	string Name;
	SuspendThread(t);
	cout << "Enter the name you want to save (Less than 10 characters,enter exit if you want to get back to the game)" << endl;
loop:getline(cin, Name);
	string fileName = Name + ".txt";
	ifstream file(fileName.c_str());
	if (!file && fileName!="exit.txt")
	{
		savedFile(fileName, 1);
		ofstream out;
		out.open(fileName.c_str());
		out << timeTH() << endl;
		out << SCORE << endl;
		out << LEVEL << endl;
		out << SIZE_SNAKE << endl;
		out << FOOD_INDEX << endl;
		out << SPEED << endl;
		out << MOVING << endl;
		out << CHAR_LOCK << endl;
		out << food.x << " " << food.y << endl;
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			out << snake[i].x << " " << snake[i].y << endl;
		}
		cout << "Save file " << fileName << " successfully !";
		Sleep(1000);
		file.close();
		out.close();
		system("cls");
		switch (LEVEL)
		{
		case 1:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			break;
		case 2:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall2();
			break;
		case 3:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall3();
			break;

		case 4:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall4();
			break;
		case 5:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		}

		 ResumeThread(t);
	}
	else if (fileName == "exit.txt")
	{
		system("cls");
		switch (LEVEL)
		{
		case 1:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			break;
		case 2:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall2();
			break;
		case 3:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall3();
			break;

		case 4:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
			ReDrawWall4();		
			break;
		case 5:
			DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		}
		ResumeThread(t);
	}
	else
	{
		cout << endl << "Name already exists, please re-enter" << endl;
		goto loop;
	}
}
void LoadGame()
{
	string filename;
	string Date;
	nhap: getline(cin, filename);
	filename += ".txt";
	ifstream in(filename);
	if (!in.is_open())
	{
		cout << "Can not find the file, re-enter" << endl;
		goto nhap;
	}
	system("cls");
	while (in >> Date )
	{
		in >> SCORE;
		in >> LEVEL;
		in >> SIZE_SNAKE;
		in >> FOOD_INDEX;
		in >> SPEED;
		in >> MOVING;
		in >> CHAR_LOCK;
		in >> food[FOOD_INDEX].x;
		in >> food[FOOD_INDEX].y;
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			in >> snake[i].x;
			in >> snake[i].y;
		}
	}
	in.close();

	GenerateFood(FOOD_INDEX+1);
	WIDTH_CONSOLE = 70, HEIGH_CONSOLE = 25;
	GetHighScore(HIGHSCORE);
	switch (LEVEL)
	{
	case 1:
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		Countdown();
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		break;
	case 2:
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall2();
		Countdown();
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall2();
		break;
	case 3:
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall3();
		Countdown();
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall3();
		break;

	case 4:
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall4();
		Countdown();
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		ReDrawWall4();
		break;
	case 5:
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
		Countdown();
		DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	}
	STATE = 1;
}
string timeTH()
{
	int giayTH = time(NULL);
	int giay = giayTH % 60;
	giayTH /= 60;
	int phut = giayTH % 60;
	giayTH /= 60;
	int gio = giayTH % 24;
	gio += 7;
	giayTH /= 24;
	int nam = giayTH / 365.25;
	int ngayTN = giayTH - nam * 365.25;
	nam += 1970;
	int thang = 0;
	int ngay = 0;
	int ngayXet = 0;
	for (int i = 1; i <= 12; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			ngayXet += 31;
			if (ngayXet > ngayTN)
			{
				ngayXet -= 31;
				thang = i;
				goto het;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			ngayXet += 30;
			if (ngayXet > ngayTN)
			{
				ngayXet -= 30;
				thang = i;
				goto het;
			}
			break;
		case 2:
			ngayXet += 28;
			if (ngayXet > ngayTN)
			{
				ngayXet -= 28;
				thang = i;
				goto het;
			}
			break;
		}
	}
het:
	if (nam % 4 == 0)
	{
		if (thang > 2)
		{
			ngayXet += 1;
		}
	}
	ngay = ngayTN - ngayXet + 2;
	string gioPhutGiay, ngayThangNam, timeRL;
	gioPhutGiay = to_string(gio) + ":" + to_string(phut) + ":" + to_string(giay);
	ngayThangNam = to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam);
	timeRL = gioPhutGiay + "|" + ngayThangNam;
	return timeRL;
}
void savedFile(string in, int choice)
{
	string str;
	if (choice == 1)
	{
		ifstream infile("savedmaps.txt");
		ofstream outtemp("temp.txt");
		while (infile >> str)
		{
			outtemp << str << endl;
		}
		infile.close();
		outtemp.close();
		ofstream outfile("savedmaps.txt");
		ifstream intemp("temp.txt");
		while (intemp >> str)
		{
			outfile << str << endl;
		}
		outfile << in;
		outfile.close();
		intemp.close();
	}
	else
	{
		ifstream infile("savedmaps.txt");
		ofstream outtemp("temp.txt");
		string rac;
		while (infile >> str)
		{
			if (str != in)
				outtemp << str << endl;
		}
		infile.close();
		outtemp.close();
		ofstream outfile("savedmaps.txt");
		ifstream intemp("temp.txt");
		while (intemp >> str)
		{
			if (!str.empty())
				outfile << str << endl;
		}
		outfile.close();
		intemp.close();
		remove(in.c_str());
	}
}