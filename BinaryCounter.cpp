/*
Created by Andrew Eljumaily

A simple "one and done" c++ binary counter
from 0 to 15.
*/

#include <iostream>

int main()
{
	int listOfNumbers[4] = { 8, 4, 2, 1 };
	int currentNumber = 0;
	
	for (int i = 0; i < 16; i++)
	{
		currentNumber = i;

		//Formating crap
		if (i < 10)
		{
			std::cout << " ";
		}
		std::cout << i << " : ";

		for (int j = 0; j < 4; j++)
		{
			if (currentNumber >= listOfNumbers[j])
			{
				currentNumber -= listOfNumbers[j];
				std::cout << 1;
			}
			else
			{
				std::cout << 0;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}