#include"header.h"
#include"audio.h"
void DrawBack(const char* str) {
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	cout << str;
	for (int i = 0; i < SIZE_SNAKE; i++) {
		GotoXY(snake[i].x, snake[i].y);
		cout << str;
	}
}
void GameOverScreen()
{
	GameOverSound();
	GotoXY(WIDTH_CONSOLE + 6, 13 );
	cout << "  GGGG    AAA   MM    MM EEEEEEE" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 14 );
	cout << " GG  GG  AAAAA  MMM  MMM EE " << endl;
	GotoXY(WIDTH_CONSOLE + 6, 15 );
	cout << "GG      AA   AA MM MM MM EEEEE" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 16 );
	cout << "GG   GG AAAAAAA MM    MM EE" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 17 );
	cout << " GGGGGG AA   AA MM    MM EEEEEEE" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 20 );
	cout << " OOOOO  VV     VV EEEEEEE RRRRRR     !!!" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 21 );
	cout << "OO   OO VV     VV EE      RR   RR    !!!" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 22 );
	cout << "OO   OO  VV   VV  EEEEE   RRRRRR     !!!" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 23 );
	cout << "OO   OO   VV VV   EE      RR  RR" << endl;
	GotoXY(WIDTH_CONSOLE + 6, 24 );
	cout << " OOOO0     VVV    EEEEEEE RR   RR    !!!" << endl;
}
void DrawBoard(int x, int y, int width, int height, int curPosX ,int curPosY) {
	GotoXY(x, y); cout << 'X';
	for (int i = 1; i < width; i++)cout << 'X';
	cout << 'X';
	GotoXY(x, height + y); cout << 'X';
	for (int i = 1; i < width; i++)cout << 'X';
	cout << 'X';
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << 'X';
		GotoXY(x + width, i); cout << 'X';
	}
	GotoXY(curPosX, curPosY);
}
void Countdown()
{
	DrawSnake();// biet duoc vi tri cua ran khi cd
	CountDownSound();
	GotoXY(WIDTH_CONSOLE / 2-2, HEIGH_CONSOLE / 2);
	std::string data = "1 2 3";
	std::string data2 = "     ";
	for (char c : data) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	for (char c : data2) {
		std::cout << c << std::flush;
	}
	system("cls");
}
void DrawGate()
{
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y - 1);
	gate[0].x = food[FOOD_INDEX].x - 1; gate[0].y = food[FOOD_INDEX].y - 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y - 2);
	gate[1].x = food[FOOD_INDEX].x - 1; gate[1].y = food[FOOD_INDEX].y - 2;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x - 2, food[FOOD_INDEX].y - 1);
	gate[2].x = food[FOOD_INDEX].x - 2; gate[2].y = food[FOOD_INDEX].y - 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y - 1);
	gate[3].x = food[FOOD_INDEX].x + 1; gate[3].y = food[FOOD_INDEX].y - 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 2, food[FOOD_INDEX].y - 1);
	gate[4].x = food[FOOD_INDEX].x + 2; gate[4].y = food[FOOD_INDEX].y - 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y + 1);
	gate[5].x = food[FOOD_INDEX].x - 1; gate[5].y = food[FOOD_INDEX].y + 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x - 2, food[FOOD_INDEX].y + 1);
	gate[6].x = food[FOOD_INDEX].x - 2; gate[6].y = food[FOOD_INDEX].y + 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y + 2);
	gate[7].x = food[FOOD_INDEX].x - 1; gate[7].y = food[FOOD_INDEX].y + 2;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y + 1);
	gate[8].x = food[FOOD_INDEX].x + 1; gate[8].y = food[FOOD_INDEX].y + 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 2, food[FOOD_INDEX].y + 1);
	gate[9].x = food[FOOD_INDEX].x + 2; gate[9].y = food[FOOD_INDEX].y + 1;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y + 2);
	gate[10].x = food[FOOD_INDEX].x + 1; gate[10].y = food[FOOD_INDEX].y + 2;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y - 2);
	gate[11].x = food[FOOD_INDEX].x + 1; gate[11].y = food[FOOD_INDEX].y - 2;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x,food[FOOD_INDEX].y + 3);
	gate[12].x = food[FOOD_INDEX].x ; gate[12].y = food[FOOD_INDEX].y + 3;
	cout << "X";
	GotoXY(food[FOOD_INDEX].x,food[FOOD_INDEX].y - 3);
	gate[13].x = food[FOOD_INDEX].x; gate[13].y = food[FOOD_INDEX].y - 3;
	cout << "X";

}
void DeleteGate()
{
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y - 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y - 2);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x - 2, food[FOOD_INDEX].y - 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y - 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 2, food[FOOD_INDEX].y - 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y + 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x - 2, food[FOOD_INDEX].y + 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x - 1, food[FOOD_INDEX].y + 2);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y + 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 2, food[FOOD_INDEX].y + 1);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y + 2);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x + 1, food[FOOD_INDEX].y - 2);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y + 3);
	cout << " ";
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y - 3);
	cout << " ";
}
void DrawFood(const char* str) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static int counter = 0; // de thuc an nhap nhay
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	if (FOOD_INDEX < MAX_SIZE_FOOD-1)
	{
		if (counter % 2 == 0) {
			cout << str;
		}
		else {
			cout << " ";
		}
		counter++;
	}
	else// Tao gate la food cuoi cung
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
		if (counter % 2 == 0) {
			cout << str;
		}
		else {
			cout << " ";
		}
		counter++;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		DrawGate();
	}
}

void DrawSnake()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	char str[12] = { '2','2','1','2','7','1','8','9','7','2','6','2' };
	for (int i = 0; i < SIZE_SNAKE; i++) {
		GotoXY(snake[i].x, snake[i].y);
		cout << str[i%12]; // xu li do dai > 12
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void DrawScore()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	GotoXY(WIDTH_CONSOLE + 4, 0);
	cout << " .d8888b   .d8888b .d88b. 888d888 .d88b.  " << endl;
	GotoXY(WIDTH_CONSOLE + 4, 1);
	cout << " 88K      d88P'   d88''88 b888P'  d8P  Y8 " << endl;
	GotoXY(WIDTH_CONSOLE + 4, 2);
	cout << " Y8888b.  888     888  88 8888    88888888 " << endl;
	GotoXY(WIDTH_CONSOLE + 4, 3);
	cout << "    X88   Y88b.   Y88..88 P88     Y8b.     " << endl;
	GotoXY(WIDTH_CONSOLE + 4, 4);
	cout << " 88888P'  'Y8888P 'Y88P'  888     'Y8888  " << endl;
	GotoXY(WIDTH_CONSOLE + 25, 6);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << SCORE << endl;
	if (SCORE < HIGHSCORE)
	{
		GotoXY(WIDTH_CONSOLE + 4, 10);
		cout << "HIGHSCORE: ";
		cout << HIGHSCORE;
	}
	else
	{
		GotoXY(WIDTH_CONSOLE + 4, 12);
		cout << "YOU HIT NEW HIGHSCORE !!" << endl;
		GotoXY(WIDTH_CONSOLE + 4, 16);
		GotoXY(WIDTH_CONSOLE + 4, 10);
		cout << "HIGHSCORE: ";
		cout << SCORE;
		HIGHSCORE = SCORE;
	}
	SaveHighScore(HIGHSCORE);

}
void DrawLevel()
{
	GotoXY(WIDTH_CONSOLE + 4, 8);
	HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(tConsole, FOREGROUND_RED);
	cout << "LEVEL: "<< LEVEL;
	SetConsoleTextAttribute(tConsole, FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_BLUE);
}

void FlashSnake() {
	HANDLE tConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(tConsole, FOREGROUND_GREEN);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int count = 0;
	while (count < 3) {  // Số lần nhấp nháy
		// In ra con rắn
		char str[12] = { '2','2','1','2','7','1','8','9','7','2','6','2' };
		for (int i = 0; i < SIZE_SNAKE; i++) {
			GotoXY(snake[i].x, snake[i].y);
			cout << str[i%12]; // xu li neu do dai > 12
		}
		Sleep(500);
		for (int i = 0; i < SIZE_SNAKE; i++) {
			GotoXY(snake[i].x, snake[i].y);
			cout << " ";
		}
		Sleep(500);
		count++;
	}
	// Đặt màu sắc của con rắn thành màu mặc định
	SetConsoleTextAttribute(tConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void DrawLogo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << R"(               
                              
                                    _____             _           _____                      
                                   / ____|           | |         / ____|                     
                                  | (___  _ __   __ _| | _____  | |  __  __ _ _ __ ___   ___ 
                                   \___ \| '_ \ / _` | |/ / _ \ | | |_ |/ _` | '_ ` _ \ / _ \
                                   ____) | | | | (_| |   <  __/ | |__| | (_| | | | | | |  __/
                                  |_____/|_| |_|\__,_|_|\_\___|  \_____|\__,_|_| |_| |_|\___|
                                                            
                                                 ___________________________

                                                                        ____
                                              /\_______________________/ O  \___/
                                              \_____________________________/   \

)";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
void HowToPlay()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	GotoXY(15, 3);
	cout <<R"(                                    _________________________________________________
                                                 / \                                                \.
                                                |   |                                               |.
                                                 \_ |                                               |.
                                                    |			        	            |. 
                                                    |                                               |.
					            |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |   ____________________________________________|___
                                                    |  /                                               /.
                                                    \_/_______________________________________________/.)";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	GotoXY(66, 5);
	cout << "WELCOME TO SNAKE GAME";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	GotoXY(56, 8);
	cout << "Try to eat as many foods as you could.";
	GotoXY(56, 10);
	cout << "Try to avoid hitting wall.";
	GotoXY(56, 12);
	cout << "When you reach enough food, there will be a ";
	GotoXY(54, 13);
	cout <<"gate spawned to help you go to next stage.";
	GotoXY(56, 15);
	cout << "Use W A S D to move up left down and right.";
	GotoXY(56, 17);
	cout << "Press P to pause the game, then any keys to";
	GotoXY(54, 18);
	cout << "continue.";
	GotoXY(56, 19);
	cout << "Press Esc and Y to get back to Menu";
	GotoXY(57, 25);
	cout << "Have fun when playing this small game";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << " <3";
	GotoXY(8, 2);
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
	cout << R"(
    __   __  _______  _     _          
   |  | |  ||       || | _ | |         
   |  |_|  ||   _   || || || |         
   |       ||  | |  ||       |         
   |       ||  |_|  ||       |         
   |   _   ||       ||   _   |         
   |__| |__||_______||__| |__|         
    _______  _______                   
   |       ||       |                  
   |_     _||   _   |                  
     |   |  |  | |  |                  
     |   |  |  |_|  |                  
     |   |  |       |                  
     |___|  |_______|                  
    _______  ___      _______  __   __ 
   |       ||   |    |   _   ||  | |  |
   |    _  ||   |    |  |_|  ||  |_|  |
   |   |_| ||   |    |       ||       |
   |    ___||   |___ |       ||_     _|
   |   |    |       ||   _   |  |   |  
   |___|    |_______||__| |__|  |___|  
)";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	GotoXY(9, 28);
	system("pause");
	system("cls");
	Menu1();
}
void About()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << R"(
                                _____   ____________  ____  ____  __  ______________________  _   __
                               /  _/ | / /_  __/ __ \/ __ \/ __ \/ / / / ____/_  __/  _/ __ \/ | / /
                               / //  |/ / / / / /_/ / / / / / / / / / / /     / /  / // / / /  |/ / 
                             _/ // /|  / / / / _, _/ /_/ / /_/ / /_/ / /___  / / _/ // /_/ / /|  /  
                            /___/_/ |_/ /_/ /_/ |_|\____/_____/\____/\____/ /_/ /___/\____/_/ |_/   
                                                                        
)";
	GotoXY(40, 14);
	cout << R"(
                                                                                         /^\/^\
                                                                                       _|__|  O|
                                                                              \/     /~     \_/ \
                                                                               \____|__________/  \
                                                                                     \_______      \
                                                                                             `\     \                 \
                                                                                              |     |                  \
                                                                                             /      /                    \
                                                                                            /     /                       \\
                                                                                           /     /                         \ \
                                                                                          /     /                            \  \
                                                                                         /     /             _----_            \   \
                                                                                        /     /           _-~      ~-_         |   |
                                                                                      (      (        _-~    _--_    ~-_     _/   |
                                                                                       \      ~-____-~    _-~    ~-_    ~-_-~    /
                                                                                        ~-_           _-~          ~-_       _-~
                                                                                           ~--______-~                ~-___-~
)";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	GotoXY(29, 8);
	cout << "PROJECT GAME SNAKE - HCMUS - Programming Techniques - 22CLCA - GROUP 10";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
	GotoXY(19, 12);
	cout << "About us: ";
	GotoXY(23, 14);
	cout << "1. Do Luong Nhat Minh - 22127262";
	GotoXY(23, 16);
	cout << "2. Pham Binh Khanh - 22127189";
	GotoXY(19, 20);
	cout << "Special thanks to our Advisor: PhD. Truong Toan Thinh";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	GotoXY(9, 28);
	system("pause");
	system("cls");
	Menu1();
}
void DrawOption()
{
	system("cls");
	GotoXY(15, 3);
	cout << R"(                                    _________________________________________________
                                                 / \                                                \.
                                                 |  |                                               |.
                                                 \_ |                                               |.
                                                    |			        	            |. 
                                                    |                                               |.
					            |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |                                               |.
                                                    |   ____________________________________________|___
                                                    |  /                                               /.
                                                    \_/_______________________________________________/.)";
	GotoXY(2, 1);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << R"(
   ____  _____ _______ _____ ____  _   _  _____ 
  / __ \|  __ |__   __|_   _/ __ \| \ | |/ ____|
 | |  | | |__) | | |    | || |  | |  \| | (___  
 | |  | |  ___/  | |    | || |  | | . ` |\___ \ 
 | |__| | |      | |   _| || |__| | |\  |____) |
  \____/|_|      |_|  |_____\____/|_| \_|_____/ 
)";
	GotoXY(8, 8);
	cout << R"(
	           *@@@@@@+                
                  -@%....@@:               
         -%@@*- .-%@+    *@#=: -#@@%-      
       -%@#:-*@@@%*=     .=*%@@@*-:*@%-    
       @@+     :              :     =@@.   
       -@@+          ::::.         +@@:    
        :@@:     :*@@@%%@@@*-     :@@-     
      .:@@=    .#@#-      -#@%.    -@@-:.  
   =@@@%%*     @@=          =@@.    +#%@@@+
   @@-        =@#            *@+        :@@
   @@:        =@#            *@+        :@@
   *@@%#*+    .@@=          -@@.    =#%%@@+
    .:-@@=    .%@#-      -#@%:    -@@-:.  
        :@@:     -*@@%%%%@@*-     :@@-     
       .%@*         .:--:.         +@%:    
       @@*     .              .     =@@.   
       -%@*.:+%@@#+=      =+#@@@*:.*@%-    
         -%@@%=.:=%@*    +@%=: =#@@%=      
                  -@@....%@-               
                   +@@@@@@*                
              
)";
}
void DrawIngameIns()
{
	GotoXY(WIDTH_CONSOLE + 28, HEIGH_CONSOLE);
	cout << "T to save game" << endl;
	GotoXY(WIDTH_CONSOLE+28, HEIGH_CONSOLE+1);
	cout << "P to pause" << endl;
	GotoXY(WIDTH_CONSOLE + 28, HEIGH_CONSOLE + 2);
	cout << "anykeys to unpause" << endl;
	GotoXY(WIDTH_CONSOLE + 28, HEIGH_CONSOLE + 3);
	cout<< "Esc + Y to BacktoMenu"<<endl;
	GotoXY(WIDTH_CONSOLE + 28, HEIGH_CONSOLE + 4);
	cout<<"Esc + N to Return Game";
}
void LoadingBar()
{
	DrawLogo();
	LoadBarSound();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	int durationInSeconds = 2;
	int progressBarWidth = 50;
	for (int i = 0; i <= 5; i++)
	{
		cout << endl;
	}
	for (int i = 0; i <= progressBarWidth; i++)
	{
		std::cout << "                                     [";
		for (int j = 0; j < i; j++)
		{
			std::cout << "=";
		}
		for (int j = i; j < progressBarWidth; j++)
		{
			std::cout << " ";
		}
		std::cout << "] " << (i * 100) / progressBarWidth << "%";

		std::this_thread::sleep_for(std::chrono::milliseconds(durationInSeconds * 10));
		std::cout << "\r";
	}
	system("cls");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void DisplaySavedFile()
{
	string str, score, level;
	string Date;
	ifstream in("savedmaps.txt");
	bool check = true;
	int decor = 0;
	if (in.peek() == ifstream::traits_type::eof())
	{
		cout << "You have not saved any file, press any key to get back" << endl;
		char temp;
		while (check)
		{
			temp = _getch();
			check = false;
			break;
		}
		in.close();
		system("cls");
	}
	else {
		while (in >> str)
		{
			ifstream intemp(str);
			intemp >> Date;
			intemp >> score;
			intemp >> level;
			intemp.close();
			if (decor < 2)
			{
				/*out:cout <<"         "<< str << " " << Date << " score:" << score << " level:" << level << "           ";*/
			out: cout << left << setw(15) << str << setw(20) << Date << setw(6) << "Score:" << setw(2) << score << setw(7) << " level:" << setw(1) << level << "        ";
				decor++;
			}
			else
			{
				cout << endl;;
				decor = 0;
				goto out;
			}
		}
		in.close();
	back:cout << endl << endl << "						Enter your choice" << endl << endl;
		cout << "	  1.Play a saved file			 2.Delete a saved file			      3.Exit"<< endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cin.ignore();
			cout << endl << endl << endl << "Enter the file you want to play" << endl;
		}
		else if(choice==2)
		{
			string tmp;
			cout << "Enter the file you want to delete( no need .txt)" << endl;
			cin.ignore();
			getline(cin, tmp);
			savedFile(tmp + ".txt",2);
			cout << "Delete file successfully.Going back menu ..." << endl;
			Sleep(1000);
			check = false;
			system("cls");
		}
		else if(choice==3)
		{
			check = false;
			system("cls");
		}
		else
		{
			cout << "Invalid, please re-enter" << endl;
			goto back;
		}
	}
	if(check==true)LoadGame();
	else
	{
		Menu1();
	}
}
void DrawSavedLogo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	cout << R"(
			 _________                     _______    .____                     .___
			/   _____/____ ___  __ ____    \      \   |    |    _________     __| _/
			\_____  \\__  \\  \/ // __ \   /   |   \  |    |   /  _ \__  \   / __ | 
			/        \/ __ \\   /\  ___/  /    |    \ |    |__(  <_> ) __ \_/ /_/ | 
		       /_______  (____  /\_/  \___  > \____|__  / |_______ \____(____  /\____ | 
			       \/     \/          \/          \/          \/         \/      \/ 


)";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE);

}