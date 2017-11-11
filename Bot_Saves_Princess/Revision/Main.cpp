/*
Created by Andrew Eljumaily

Based on original c++ solution to 
"Bot Saves Princess" challange
from hackerrank.com.

https://www.hackerrank.com/challenges/saveprincess/problem

A revision of my original solution to the Bot Save
Princess problem that can determine a move set
no matter where Mario or the Princess are on the
grid.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid) 
{
	int mX = 0;
	int mY = 0;
	int pX = 0;
	int pY = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 'm')
			{
				mX = j;
				mY = i;
			}
			else if (grid[i][j] == 'p')
			{
				pX = j;
				pY = i;
			}
		}
	}

	int xDifference = mX - pX;
	int yDifference = mY - pY;
	string moveX = "";
	string moveY = "";

	if (xDifference > 0)
	{
		moveX = "LEFT\n";
	}
	else if (xDifference < 0)
	{
		moveX = "RIGHT\n";
	}

	if (yDifference > 0)
	{
		moveY = "UP\n";
	}
	else if (yDifference < 0)
	{
		moveY = "DOWN\n";
	}

	
	for (int i = 0; i < abs(xDifference); i++)
	{
		cout << moveX;
	}

	for (int i = 0; i < abs(yDifference); i++)
	{
		cout << moveY;
	}
}

int main(void) 
{

	int m;
	vector <string> grid;

	cout << "Enter in size of grid (odd #'s only): ";
	cin >> m;

	cout << "Please create grid: " << endl;
	for (int i = 0; i<m; i++) 
	{
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);
	return 0;
}
