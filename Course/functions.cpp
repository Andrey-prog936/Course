#include "functions.h"
#include<iostream>
#include<string>
#include <conio.h>
using namespace std;

void selectLevel(int selected)
{
	int oi = 0;
	cout << "Hello, select level please (1 - 4)" << endl;
	cout << "Your choice: ";
	cin >> selected;
	while (selected > 4 || selected < 1)
	{
		if (selected > 4 || selected < 1)
		{
			oi++;
			cout << "Please enter number (1 - 4): ";
			cin >> selected;
			if (oi>4)
			{
				system("cls");
				selectLevel(selected);
			}
		}
		else
		{
			break;
		}
	}
	
}



/*
int right() //100 вправо
{
	char S = '$';
	system("cls");
	if (map[x][y + 1] == '*')
	{

	}
	else if (map[x][y + 1] == '#')
	{
		cout << "GAME OVER" << endl;
		return 0;
	}
	else if (map[x][y + 1] == 'F')
	{
		system("cls");
		cout << "\nYou WIN" << endl;
		return 0;
	}
	else {
		map[x][y] = ' ';
		map[x][++y] = S;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}

}

int left() //97 влево
{
	char S = '$';
	system("cls");
	if (map[x][y - 1] == '*')
	{

	}
	else if (map[x][y - 1] == '#')
	{
		cout << "GAME OVER" << endl;
		return 0;

	}
	else if (map[x][y - 1] == 'F')
	{
		system("cls");
		cout << "\nYou WIN" << endl;
		return 0;
	}
	else
	{
		map[x][y] = ' ';
		map[x][--y] = S;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}
}

int up() //119 вверх
{
	char S = '$';
	system("cls");
	if (map[x - 1][y] == '*')
	{

	}
	else if (map[x - 1][y] == '#')
	{
		cout << "GAME OVER" << endl;
		return 0;
	}
	else if (map[x - 1][y] == 'F')
	{
		system("cls");

		cout << "\nYou WIN" << endl;
		return 0;
	}
	else {
		map[x][y] = ' ';
		map[--x][y] = S;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}


}

int down() //115 вниз
{
	char S = '$';
	system("cls");
	if (map[x + 1][y] == '*')
	{

	}
	else if (map[x + 1][y] == '#')
	{
		cout << "GAME OVER" << endl;
		return 0;

	}

	else if (map[x + 1][y] == 'F')
	{
		system("cls");
		cout << "\nYou WIN" << endl;
		return 0;
	}
	else {
		map[x][y] = ' ';
		map[++x][y] = S;
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}

}
*/

int controls()
{
	for (;;)
	{
		int d = _getch();

		switch (d)
		{
		case 100: //вправо D
		{
			system("cls");
			right();
		}break;
		case 97: //влево A
		{
			system("cls");
			left(); 
		}break;
		case 119: //вверх W
		{
			system("cls");
			up();
		}break;
		case 115: //вниз S
		{
			system("cls");
			down(); 
		}break;
			
			

		default:
			cout << "\nError404\n" << endl;
			return 0;
			break;
		}
	}
}
