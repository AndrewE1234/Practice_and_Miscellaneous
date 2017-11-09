/*
Created by Andrew Eljumaily
Based on "led.c" by sunfounder.com

Code for a simple LED binary counter
using a RaspberryPI.

For anyone unsure or stuck on how to compile
this code  via the terminal, try:

c99 -lwiringPi -o PinaryCounter PinaryCounter.c
*/

#include <wiringPi.h>
#include <stdio.h>
#include <stdbool.h>

//Defined via wiringPi standards.
#define LedPin1    0
#define LedPin2    2
#define LedPin3	   3
#define LedPin4    21 

void displayLeds(bool onOrOff[]);

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	printf("Using GPIO pins %d, %d, %d, and %d (wiringPi)\n",LedPin1, LedPin2, LedPin3, LedPin4); 
	printf("OK! Start:\n");
	
	pinMode(LedPin1, OUTPUT);
	pinMode(LedPin2, OUTPUT);
	pinMode(LedPin3, OUTPUT);
	pinMode(LedPin4, OUTPUT);
	
	digitalWrite(LedPin1, LOW);
	digitalWrite(LedPin2, LOW);
	digitalWrite(LedPin3, LOW);
	digitalWrite(LedPin4, LOW);

	int numbersToCompair[] = { 8,4,2,1 };
	int currentNumber = 0;	
	bool onOrOff[4];

	for(int i = 0; i < 16; i++)
	{
		currentNumber = i;
		printf("%i \n", i);
		for(int j = 0; j < 4; j++)
		{
			if(currentNumber >= numbersToCompair[j])
			{
				onOrOff[j] = true;
				currentNumber -= numbersToCompair[j];
			}
			else
			{
				onOrOff[j] = false;
			}
		}
		displayLeds(onOrOff);
		delay(500);
	}
		
	digitalWrite(LedPin1, LOW);
	digitalWrite(LedPin2, LOW);
	digitalWrite(LedPin3, LOW);
	digitalWrite(LedPin4, LOW);

	printf("Done!\n");

	return 0;
}


void displayLeds(bool onOrOff[])
{
	if(onOrOff[0] == true)
	{
		digitalWrite(LedPin1, HIGH);
	}
	else
	{
		digitalWrite(LedPin1, LOW);
	}

	if(onOrOff[1] == true)
	{
		digitalWrite(LedPin2, HIGH);
	}
	else
	{
		digitalWrite(LedPin2, LOW);
	}

	if(onOrOff[2] == true)
	{
		digitalWrite(LedPin3, HIGH);
	}
	else
	{
		digitalWrite(LedPin3, LOW);
	}

	if(onOrOff[3] == true)
	{
		digitalWrite(LedPin4, HIGH);
	}
	else
	{
		digitalWrite(LedPin4, LOW);
	}
}



