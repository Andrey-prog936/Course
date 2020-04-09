#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "functions.h"
int main() {
	{
	char symvol;
	const int x1 = 10, y1 = 21; char level1[x1][y1];
	const int x2 = 17, y2 = 43; char level2[x2][y2];
	const int x3 = 22, y3 = 49; char level3[x3][y3];
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
//######################################################
	}


	int selected = 0;
	selectLevel(selected);




	/*
	for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2; j++)
		{
			cout << level2[i][j];
		}
	}
	cout << endl;
	*/
	
	
	
	system("pause");
	return 0;
}