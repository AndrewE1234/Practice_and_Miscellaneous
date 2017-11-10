/*
Created by Andrew Eljumaily

Solution in c++ to 
"Bot Saves Princess" challange
from hackerrank.com.

https://www.hackerrank.com/challenges/saveprincess/problem

TODO: It's feels a bit "hard coded" at the moment, would be
nice to have some more "advanced" logic.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid) 
{
	int mLocation = (n / 2);

	if (grid[0][0] == 'p')
	{
		for (int i = mLocation; i != 0; i--)
		{
			cout << "LEFT\n";
			cout << "UP\n";
		}
	}
	else if (grid[0][n-1] == 'p')
	{
		for (int i = mLocation; i != 0; i--)
		{
			cout << "RIGHT\n";
			cout << "UP\n";
		}
	}
	else if (grid[n-1][0] == 'p')
	{
		for (int i = mLocation; i != 0; i--)
		{
			cout << "LEFT\n";
			cout << "DOWN\n";
		}
	}
	else if (grid[n - 1][n - 1] == 'p')
	{
		for (int i = mLocation; i != 0; i--)
		{
			cout << "RIGHT\n";
			cout << "DOWN\n";
		}
	}
}

int main(void) 
{

	int m;
	vector <string> grid;

	cout << "Enter in size of grid (odd #'s only): ";
	cin >> m;

	cout << "Please created grid: " << endl;
	for (int i = 0; i<m; i++) 
	{
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);
	system("Pause");
	return 0;
}
