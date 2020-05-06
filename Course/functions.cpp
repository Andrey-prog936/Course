#include "functions.h"
#include<iostream>
#include <fstream>
#include<string>
#include <conio.h>
#include <stdio.h>
#include "coloring.h"
using namespace std;
char S = '$';
int selected = 0;
void gameover()
{
	cout << R"( ______      ___       ___  ___   ____      _____   _     _   ____   ____
/  ___/     /   |     /   |/   | |  __|    /  _  \ | |   / / | ___| |  _ \
| |        / /| |    / /|   /| | | |___    | | | | | |  / /  | |__  | |_| |
| |  _    / __  |   / / |__/ | | |  ___|   | | | | | | / /   | __|  |  _ /
| |_| |  / /  | |  / /       | | | |____   | |_| | | |/ /    | |___ | | \ \
\_____/ /_/   |_| /_/        |_| |______|  \_____/ |___/     |_____||_|  \_\ 

)";
}
//###########################################################################################
void youwin()
{
	cout << R"(  _     _   _____   _   _    _         _   _   _ __     _
 \ \   / / /  _  \ | | | |  | |   _   | | | | | |\ \   | |
  \ \_/ /  | | | | | | | |  | |  / \  | | | | | | \ \  | |
   \   /   | | | | | | | |  | | / _ \ | | | | | |  \ \ | |
    | |    | |_| | | |_| |  | |/ / \ \| | | | | |   \ \| |
    |_|    \_____/ \_____/  \___/   \___/ |_| |_|    \_|_|

)";
}
//###########################################################################################
void guid()
{
	green
		cout << R"(|=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|                           |
|        /-----\	    |
|        |_W___|	    |
|        |_____|	    |
|        \-----/	    |
|   /-----\/-----\/-----\   |
|   |_A___||_S___||_D___|   |
|   |_____||_____||_____|   |
|   \-----/\-----/\-----/   |
|                           |
|-=-=-=-=-=Control=-=-=-=-=-|
)";
	red    cout << "|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n|";
	orange cout << "Please select an English keyboard layout "; red cout << "|" << endl;
	red    cout << "|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|" << endl;
	def

}
//###########################################################################################
int selectLevel()
{
	char symvol;
	int point = 0;
	const int x1 = 10, y1 = 21; char level1[x1][y1];
	const int x2 = 17, y2 = 43; char level2[x2][y2];
	const int x3 = 18, y3 = 49; char level3[x3][y3];
	const int x4 = 23, y4 = 59; char level4[x4][y4];
	ifstream in1("level1.txt"); // open file_1
	for (int i = 0; i < x1; i++)
	{
		for (int j = 0; j < y1; j++)
		{
			in1.get(symvol);
			level1[i][j] = symvol;
		}
	}	in1.close();
	//######################################################
	ifstream in2("level2.txt"); // open file_2
	for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
		{
			in2.get(symvol);
			level2[i][j] = symvol;
		}
	}in2.close();
	//######################################################
	ifstream in3("level3.txt"); // open file_3
	for (int i = 0; i < x3; i++)
	{
		for (int j = 0; j < y3; j++)
		{
			in3.get(symvol);
			level3[i][j] = symvol;
		}
	}in3.close();
	//######################################################
	ifstream in4("level4.txt"); // open file_4
	for (int i = 0; i < x4; i++)
	{
		for (int j = 0; j < y4; j++)
		{
			in4.get(symvol);
			level4[i][j] = symvol;
		}
	}in4.close();
	//#################################################
	int oi = 1;
	cout << "\tMAZE\nHello, select level please (1 - 4)\nYour choice: ";
	cin >> selected;
	while (selected < 1 || selected > 4)
	{
		if (selected < 1 || selected > 4)
		{
			oi++;
			cout << "Please enter number (1 - 4): ";
			cin >> selected;
			if (oi > 3)
			{
				system("cls");
				selectLevel(); // recursion 
			}
		}
		else
		{
			break;
		}
	}

	//##############################################################################################################################

	system("cls");
	switch (selected)
	{
	case 1:
	{

		int x = 1, y = 1;
		level1[x][y] = S;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cout << level1[i][j];
			}
			cout << endl;
		}
		cout << "Point: " << point <<"/10"<< endl;
		for (;;)
		{
			int d = _getch();
			switch (d)
			{
			case 100: //âïðàâî D
			{
				system("cls");
				if (level1[x][y + 1] == '*' || level1[x][y + 1] == '|')
				{

				}
				else if (level1[x][y + 1] == '#')
				{
					gameover();
					return 0;
				}
				else if (level1[x][y + 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level1[x][y + 1] == '@')
				{
					level1[x][y] = ' ';
					level1[x][++y] = S;
					point++;
				}
				else {
					level1[x][y] = ' ';
					level1[x][++y] = S;
				}
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						cout << level1[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/10"<< endl;

			}break;
			case 97: //âëåâî A
			{
				system("cls");
				if (level1[x][y - 1] == '*')
				{

				}
				else if (level1[x][y - 1] == '#')
				{
					gameover();
					return 0;

				}
				else if (level1[x][y - 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level1[x][y - 1] == '@')
				{
					level1[x][y] = ' ';
					level1[x][--y] = S;
					point++;
				}
				else
				{
					level1[x][y] = ' ';
					level1[x][--y] = S;
				}

				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						cout << level1[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/10"<< endl;

			}break;
			case 119: //ââåðõ W
			{

				system("cls");
				if (level1[x - 1][y] == '*')
				{

				}
				else if (level1[x - 1][y] == '#')
				{
					gameover();
					return 0;
				}
				else if (level1[x - 1][y] == 'F')
				{
					system("cls");

					youwin();
					return 0;
				}
				else if (level1[x-1][y] == '@')
				{
					level1[x][y] = ' ';
					level1[--x][y] = S;
					point++;
				}
				else {
					level1[x][y] = ' ';
					level1[--x][y] = S;
				}

				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						cout << level1[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/10"<< endl;
			}break;
			case 115: //âíèç S
			{
				system("cls");
				if (level1[x + 1][y] == '*')
				{

				}
				else if (level1[x + 1][y] == '#')
				{
					gameover();
					return 0;

				}

				else if (level1[x + 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level1[x + 1][y] == '@')
				{
					level1[x][y] = ' ';
					level1[++x][y] = S;
					point++;
					
				}
				else {
					level1[x][y] = ' ';
					level1[++x][y] = S;
				}
				if (point == 10) { level1[8][17] = ' '; }
				
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						cout << level1[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/10"<< endl;
			}break;

			default:
				cout << "\nError404\n" << endl;
				return 0;
				break;
			}
		}

	}break;

	case 2:
	{
		int x = 1, y = 1;
		level2[x][y] = S;
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 42; j++)
			{
				cout << level2[i][j];
			}
			cout << endl;
		}
		cout << "Point: " << point <<"/19"<< endl;

		for (;;)
		{
			int d = _getch();
			switch (d)
			{
			case 100: //âïðàâî D
			{

				system("cls");
				if (level2[x][y + 1] == '*')
				{

				}
				else if (level2[x][y + 1] == '#')
				{
					gameover();
					return 0;
				}
				else if (level2[x][y + 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level2[x][y + 1] == '@')
				{
					level2[x][y] = ' ';
					level2[x][++y] = S;
					point++;
				}
				else {
					level2[x][y] = ' ';
					level2[x][++y] = S;
				}
				for (int i = 0; i < 17; i++)
				{
					for (int j = 0; j < 42; j++)
					{
						cout << level2[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/19"<< endl;

			}break;
			case 97: //âëåâî A
			{
				system("cls");
				if (level2[x][y - 1] == '*'|| level2[x][y - 1] == '|')
				{

				}
				else if (level2[x][y - 1] == '#')
				{
					gameover();
					return 0;

				}
				else if (level2[x][y - 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level2[x][y - 1] == '@')
				{
					level2[x][y] = ' ';
					level2[x][--y] = S;
					point++;
				}
				else
				{
					level2[x][y] = ' ';
					level2[x][--y] = S;
				}

				for (int i = 0; i < 17; i++)
				{
					for (int j = 0; j < 42; j++)
					{
						cout << level2[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/19"<< endl;

			}break;
			case 119: //ââåðõ W
			{

				system("cls");
				if (level2[x - 1][y] == '*')
				{

				}
				else if (level2[x - 1][y] == '#')
				{
					gameover();
					return 0;
				}
				else if (level2[x - 1][y] == 'F')
				{
					system("cls");

					youwin();
					return 0;
				}
				else if (level2[x-1][y] == '@')
				{
					level2[x][y] = ' ';
					level2[--x][y] = S;
					point++;
				}
				else {
					level2[x][y] = ' ';
					level2[--x][y] = S;
				}

				for (int i = 0; i < 17; i++)
				{
					for (int j = 0; j < 42; j++)
					{
						cout << level2[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/19"<< endl;
			}break;
			case 115: //âíèç S
			{
				system("cls");
				if (level2[x + 1][y] == '*')
				{

				}
				else if (level2[x + 1][y] == '#')
				{
					gameover();
					return 0;

				}

				else if (level2[x + 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level2[x+1][y] == '@')
				{
					level2[x][y] = ' ';
					level2[++x][y] = S;
					point++;
				}
				else {
					level2[x][y] = ' ';
					level2[++x][y] = S;
				}

				if (point == 19) { level2[15][34] = ' '; }
				for (int i = 0; i < 17; i++)
				{
					for (int j = 0; j < 42; j++)
					{
						cout << level2[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point <<"/19"<< endl;
			}break;

			default:
				cout << "\nError404\n" << endl;
				return 0;
				break;
			}
		}
	}break;

	case 3:
	{
		int x = 1, y = 1;
		level3[x][y] = S;
		for (int i = 0; i < 18; i++)
		{
			for (int j = 0; j < 48; j++)
			{
				cout << level3[i][j];

			}
			cout << endl;
		}
		cout << "Point: " << point << "/23" << endl;

		for (;;)
		{
			int d = _getch();
			switch (d)
			{
			case 100: //âïðàâî D
			{

				system("cls");
				if (level3[x][y + 1] == '*'|| level3[x][y + 1] == '|')
				{

				}
				else if (level3[x][y + 1] == '#')
				{
					gameover();
					return 0;
				}
				else if (level3[x][y + 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level3[x][y+1] == '@')
				{
					level3[x][y] = ' ';
					level3[x][++y] = S;
					point++;
				}
				else {
					level3[x][y] = ' ';
					level3[x][++y] = S;
				}
				for (int i = 0; i < 18; i++)
				{
					for (int j = 0; j < 48; j++)
					{
						cout << level3[i][j];

					}
					cout << endl;
				}
				cout << "Point: " << point << "/23" << endl;

			}break;
			case 112:
			{
				point = 9;
			if (point == 9)
			{
				system("cls");
				for (int i = 0; i < 18; i++)
				{
					for (int j = 0; j < 48; j++)
					{
						cout << level3[i][j];
					}
					cout << endl;
				}

				cout << "Point: " << point << "/23" << endl;
				cout << point << " - this is the favorite number of the author of the this game =)" << endl;
				//This secret is only at the third level, because the favorite three-digit number 939 =)
				Sleep(1000);
			}
			}
			case 97: //âëåâî A
			{
				system("cls");
				if (level3[x][y - 1] == '*'|| level3[x][y - 1] == '|')
				{

				}
				else if (level3[x][y - 1] == '#')
				{
					gameover();
					return 0;

				}
				else if (level3[x][y - 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level3[x][y-1] == '@')
				{
					level3[x][y] = ' ';
					level3[x][--y] = S;
					point++;
				}
				else
				{
					level3[x][y] = ' ';
					level3[x][--y] = S;
				}
				for (int i = 0; i < 18; i++)
				{
					for (int j = 0; j < 48; j++)
					{
						cout << level3[i][j];

					}
					cout << endl;
				}
				cout << "Point: " << point << "/23"<< endl;

			}break;
			case 119: //ââåðõ W
			{

				system("cls");
				if (level3[x - 1][y] == '*')
				{

				}
				else if (level3[x - 1][y] == '#')
				{
					gameover();
					return 0;
				}
				else if (level3[x - 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level3[x-1][y] == '@')
				{
					level3[x][y] = ' ';
					level3[--x][y] = S;
					point++;
				}
				else {
					level3[x][y] = ' ';
					level3[--x][y] = S;
				}
				if (point == 23) { level3[1][43] = ' '; level3[1][45] = ' '; }
				for (int i = 0; i < 18; i++)
				{
					for (int j = 0; j < 48; j++)
					{
						cout << level3[i][j];

					}
					cout << endl;
				}
				cout << "Point: " << point<<"/23" << endl;
			}break;
			case 115: //âíèç S
			{
				system("cls");
				if (level3[x + 1][y] == '*')
				{

				}
				else if (level3[x + 1][y] == '#')
				{
					gameover();
					return 0;

				}

				else if (level3[x + 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level3[x + 1][y] == '@')
				{
					level3[x][y] = ' ';
					level3[++x][y] = S;
					point++;
				}
				else {
					level3[x][y] = ' ';
					level3[++x][y] = S;
				}

				for (int i = 0; i < 18; i++)
				{
					for (int j = 0; j < 48; j++)
					{
						cout << level3[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point << "/23" << endl;
			}break;

			default:
				cout << "\nError404\n" << endl;
				return 0;
				break;
			}
		}
	}break;
	case 4:
	{
		int x = 1, y = 1;
		level4[x][y] = S;
		for (int i = 0; i < 23; i++)
		{
			for (int j = 0; j < 58; j++)
			{
				cout << level4[i][j];
			}
			cout << endl;
		}
		cout << "Point: " << point << "/34" << endl;
		for (;;)
		{
			int d = _getch();
			switch (d)
			{
			case 100: //âïðàâî D
			{
				system("cls");
				if (level4[x][y + 1] == '*'|| level4[x][y + 1] == '|')
				{

				}
				else if (level4[x][y + 1] == '#')
				{
					gameover();
					return 0;
				}
				else if (level4[x][y + 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level4[x][y+1] == '@')
				{
					level4[x][y] = ' ';
					level4[x][++y] = S;
					point++;
				}
				else {
					level4[x][y] = ' ';
					level4[x][++y] = S;
				}
				for (int i = 0; i < 23; i++)
				{
					for (int j = 0; j < 58; j++)
					{
						cout << level4[i][j];

					}
					cout << endl;
				}
				cout << "Point: " << point << "/34" << endl;
			}break;
			case 97: //âëåâî A
			{
				system("cls");
				if (level4[x][y - 1] == '*'|| level4[x][y - 1] == '|')
				{

				}
				else if (level4[x][y - 1] == '#')
				{
					gameover();
					return 0;

				}
				else if (level4[x][y - 1] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level4[x][y - 1] == '@')
				{
					level4[x][y] = ' ';
					level4[x][--y] = S;
					point++;
				}
				else
				{
					level4[x][y] = ' ';
					level4[x][--y] = S;
				}
				for (int i = 0; i < 23; i++)
				{
					for (int j = 0; j < 58; j++)
					{
						cout << level4[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point << "/34" << endl;
			}break;
			case 119: //ââåðõ W
			{

				system("cls");
				if (level4[x - 1][y] == '*')
				{

				}
				else if (level4[x - 1][y] == '#')
				{
					gameover();
					return 0;
				}
				else if (level4[x - 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level4[x-1][y] == '@')
				{
					level4[x][y] = ' ';
					level4[--x][y] = S;
					point++;
				}
				else {
					level4[x][y] = ' ';
					level4[--x][y] = S;
				}
				for (int i = 0; i < 23; i++)
				{
					for (int j = 0; j < 58; j++)
					{
						cout << level4[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point << "/34" << endl;
			}break;
			case 115: //âíèç S
			{
				system("cls");
				if (level4[x + 1][y] == '*')
				{

				}
				else if (level4[x + 1][y] == '#')
				{
					gameover();
					return 0;

				}
				else if (level4[x + 1][y] == 'F')
				{
					system("cls");
					youwin();
					return 0;
				}
				else if (level4[x+1][y] == '@')
				{
					level4[x][y] = ' ';
					level4[++x][y] = S;
					point++;
				}
				else {
					level4[x][y] = ' ';
					level4[++x][y] = S;
				}
				if (point == 34) { level4[21][27] = ' ';level4[21][29] = ' ';}
				for (int i = 0; i < 23; i++)
				{
					for (int j = 0; j < 58; j++)
					{
						cout << level4[i][j];
					}
					cout << endl;
				}
				cout << "Point: " << point << "/34" << endl;
			}break;

			default:
				cout << "\nError404\n" << endl;
				return 0;
				break;
			}
		}
	}break;
	default:
	{
		cout << "Error404" << endl;
	}break;
	}
}