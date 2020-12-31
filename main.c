#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "customMath.h"
#include <windows.h>
#include <conio.h>

#define XRES 1200
#define YRES 350

#define EMPTY ' '
#define FULL '#'

char density[7] = " .:+*#@";

#define MAX_ITERATIONS 75

// Z_0 = 0			
// Z_n+1 = Z_n^2 + C

/*
	___		  ___  2			
	  /    --  /        __:__   /‾‾
     /     -- /		      :     \__
	‾‾‾ n+1	  ‾‾‾n

*/

float MARG = 10;

char buffer[XRES*YRES+YRES];

float xOff = 0, yOff = 0;
float zoom = 1.0f;
float MOVE = 5.0f;

void SetPosition(int X, int Y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position={X, Y};

	SetConsoleCursorPosition(Screen, Position);
}


int main() {

	system("echo off");
	system("cls");

	while(true) { 
		SetPosition(0,0);

	int i = 0;
		for (int y = MARG/2; y < YRES+MARG/2; y++) {
	for (int x = MARG/2; x < XRES+MARG/2; x++) {
			char pixel = EMPTY;

			float _x = (-(2.0f) + ((float)(x+xOff) / (float)(XRES*zoom)) * 4) ;
			float _y = (-(1.6f) + ((float)(y+yOff) / (float)(YRES*zoom)) * 3.2f) 	;

			complexNumber C = createComplex(_x, _y);
			complexNumber Z = createComplex(0, 0);

			int n = 0;
			bool inside = true;
			for (; n < MAX_ITERATIONS; n++) {	

				if (SquareModule(Z) >= 4) {
					inside = false;
					pixel = FULL;
					break;
				}
				Z = Square(Sum(Z, C));
			}
			if (n <= MAX_ITERATIONS - 20 && !inside) {
				int v = (int)((float)(n / (float)(MAX_ITERATIONS - 21))*6);
				pixel = density[6 - v];
			}
			buffer[i++] = pixel;

		}
		buffer[i++] = '\n';
	}

	printf("%s", buffer);
	
		char ch = _getch();
		if (ch == 'w')
			yOff-=MOVE;
		else if (ch == 's')
			yOff +=MOVE;
		else if (ch == 'a')
			xOff-=MOVE;
		else if (ch == 'd')
			xOff+=MOVE;
		else if (ch == 'z')
			zoom *= 1.2f;
		else if (ch == 'x')
			zoom *= 0.8f;

		else if (ch == '1')
			MOVE = 5.0f;
		else if (ch == '2')
			MOVE = 10.0f;
		else if (ch == '3')
			MOVE = 15.0f;
		else if (ch == '4')
			MOVE = 20.0f;
		else if (ch == '5')
			MOVE = 40.0f;

		else if (ch == 'j')
			zoom *= 2.0f;
		else if (ch == 'k')
			zoom *= 0.5f;

	}

    return 0;
}