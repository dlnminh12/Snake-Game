#include"header.h"
#include"audio.h"
void Option()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DrawOption();
    int Optionchoice = 1;
    char input = 1;
    do
    {
        if (Optionchoice == 1&&MUSIC_OPS==1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            GotoXY(66, 9);
            cout << "MUSIC:      <   ON   >";
        }
        else if (Optionchoice == 1 && MUSIC_OPS == 0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            GotoXY(66, 9);
            cout << "MUSIC:      <   OFF  >";
        }
        else if (Optionchoice == 2 && MUSIC_OPS == 0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            GotoXY(66, 9);
            cout << "MUSIC:      <   OFF  >";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
            GotoXY(66, 9);
            cout << "MUSIC:      <   ON   >";
        }
        if (Optionchoice == 2&&SFX_OPS==1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            GotoXY(66, 15);
            cout << "SFX:        <   ON   >";
        }
        else if (Optionchoice == 2 && SFX_OPS == 0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            GotoXY(66, 15);
            cout << "SFX:        <   OFF  >";
        }
        else if (Optionchoice == 1 && SFX_OPS == 0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
            GotoXY(66, 15);
            cout << "SFX:        <   OFF  >";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   
            GotoXY(66, 15);
            cout << "SFX:        <   ON   >";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        GotoXY(58, 22);
        cout << "Use A and D to switch between On and Off";
        GotoXY(64, 24);
        cout << "Press B to get back to Menu";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        input = _getch();
        switch (input)
        {
        case 'w':
            if (Optionchoice > 1)
                Optionchoice--;
            else if (Optionchoice <= 1)
                Optionchoice = 2;
            break;
        case 's':
            if (Optionchoice < 2)
                Optionchoice++;
            else  if (Optionchoice >= 2)
                Optionchoice = 1;
            break;
        case 'a':
            if (Optionchoice == 1)
            {
                if (MUSIC_OPS == 1)
                    MUSIC_OPS = 0;
                else if (MUSIC_OPS == 0)
                    MUSIC_OPS = 1;
            }
            else if (Optionchoice == 2)
            {
                if (SFX_OPS == 1)
                    SFX_OPS = 0;
                else if (SFX_OPS == 0)
                    SFX_OPS = 1;
            }
            break;
        case 'd':
            if (Optionchoice == 1)
            {
                if (MUSIC_OPS == 0)
                    MUSIC_OPS=1;
                else if (MUSIC_OPS == 1)
                    MUSIC_OPS = 0;
            }
            else if (Optionchoice == 2)
            {
                if (SFX_OPS == 0)
                    SFX_OPS = 1;
                else if(SFX_OPS==1)
                    SFX_OPS = 0;
            }
            break;
        }
    } while (input != 98 && input != 66);//dung khi nhan B
    system("cls");
    Menu1();
}
void Menu1()
{
    char keyinput;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    MenuSound();
    int tempchoice;
    do {
        DrawLogo();
        if (MENUCHOICE == 1)
        {
            GotoXY(51, 16);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   PLay Game   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else
        {
            GotoXY(55, 16);
            cout << "PLay Game";
        }
        if (MENUCHOICE == 2)
        {
            GotoXY(51, 18);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   Play saved game   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else
        {
            GotoXY(55, 18);
            cout << "Play saved game";
        }
        if (MENUCHOICE == 3)
        {
            GotoXY(51, 20);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   Options   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            GotoXY(55, 20);
            cout << "Options";
        }
        if (MENUCHOICE == 4)
        {
            GotoXY(51, 22);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   How To Play   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else
        {
            GotoXY(55, 22);
            cout << "How To Play";
        }
        if (MENUCHOICE == 5)
        {
            GotoXY(51, 24);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   About Us   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            GotoXY(55, 24);
            cout << "About Us";
        }
        if (MENUCHOICE == 6)
        {
            GotoXY(51, 26);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << ">   Exit   <";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else
        {
            GotoXY(55, 26);
            cout << "Exit";
        }
        keyinput = _getch();
        switch (keyinput)
        {
        case'w':
            if (MENUCHOICE > 1)
                MENUCHOICE--;
            else if (MENUCHOICE <= 1)
                MENUCHOICE = 6;
            break;
        case's':
            if (MENUCHOICE < 6)
                MENUCHOICE++;
            else if (MENUCHOICE >= 6)
                MENUCHOICE = 1;
            break;
        }
        system("cls");
    } while (keyinput != 13);//dung khi nhap enter
    switch (MENUCHOICE)
    {
    case 1:
        StopSound();
        StartGame();
        break;
    case 2:
        DrawSavedLogo();
        DisplaySavedFile();
        break;
    case 3:
        Option();
        break;
    case 4:
        HowToPlay();
        break;
    case 5:
        About();
        break;
    case 6 :
        exit(0);
        return;   
    }
}

