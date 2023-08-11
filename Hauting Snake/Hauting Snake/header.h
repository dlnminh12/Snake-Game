#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<chrono>
#include<fstream>
#include <cstdlib>
#include<string>;
#include<time.h>;
#include<iomanip>;
using namespace std;
//Constants
#define MAX_SIZE_FOOD 7
#define MAX_SPEED 50
//Global variables
extern POINT snake[50]; //snake
extern POINT food[7]; // food
extern POINT gate[14];
extern POINT WALL2[38];
extern POINT WALL3[26];
extern POINT WALL4[169];
extern int CHAR_LOCK;//used to determine the direction my snake cannot move (At a moment, there is one direction my snake cannot move to)
extern int MOVING;//used to determine the direction my snake moves (At a moment, there are three directions my snake can move)
extern int SPEED;// Standing for level, the higher the level, the quicker the speed
extern int HEIGH_CONSOLE, WIDTH_CONSOLE;// Width and height of console-screen
extern int FOOD_INDEX; // current food-index
extern int SIZE_SNAKE; // size of snake, initially maybe 6 units and maximum size maybe
extern int STATE; // State of snake: dead or alive
extern int SCORE;
extern int HIGHSCORE;
extern int LEVEL;
extern int MUSIC_OPS; // nhac = 1 bat , nguoc lai
extern int SFX_OPS; // sfx nhu tren
extern int MENUCHOICE; //menu (luu toan cuc de khi thoat ra 1 option ko bi reset ve dong dau)
extern int CountDownR5; // dem nguoc round 5 1 lan vi round 5 la vo han
void FixConsoleWindow();//fixconsole
void GotoXY(int x, int y);//function
bool IsValid(int x, int y);//function
void GenerateFood(int foodIndex);// food
void GetHighScore(int& n);// score
void SaveHighScore(int n);// score
void ResetData();//function
void DrawBoard(int x, int y, int width, int height, int curPosX = 0,int curPosY = 0);//draw
void Countdown();//draw
void StartGame();//function
void ExitGame(HANDLE t);//function
void PauseGame(HANDLE t);//function
void Eat();// snake
void DrawBack(const char* str);// draw
void GameOverScreen();// draw
void ProcessDead();//snake
void DrawFood(const char* str);//draw
void DrawSnake();//draw
void DrawScore();//draw
void FlashSnake();//draw
void MoveRight();// move
void MoveLeft();// move
void MoveDown();//move
void MoveUp();//move
void ThreadFunc();//function
void DeleteGate();//snake
void DrawLevel();//draw
void Wall2();//wall
void ReDrawWall2();//wall
void Wall3();//wall
void ReDrawWall3();//wall
void Wall4();//wall
void ReDrawWall4();//wall
void Menu1();//menu
void DrawLogo();//draw
void HowToPlay();//draw
void About();//draw
void Option();//menu
void DrawOption();//option
void Wall5();//wall
void DrawIngameIns();//draw
void SavenLoad(int SCORE,int LEVEL,int SIZE_SNAKE,int FOOD_INDEX,int SPEED,POINT food,POINT snake[], HANDLE t);//function
void LoadingBar();//draw
void ToggleSound();//audio
void LoadGame();//function
string timeTH(); //function (lay thoi gian thuc)
void savedFile(string in,int choice); //function
void DisplaySavedFile();//draw
void DrawSavedLogo();//draw