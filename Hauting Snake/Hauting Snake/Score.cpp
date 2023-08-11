#include"header.h"
void GetHighScore(int& n)
{
	ifstream in;
	in.open("highscore.txt");
	in >> n;
	in.close();
}
void SaveHighScore(int n)
{
	ofstream out;
	out.open("highscore.txt");
	out << n;
	out.close();
}