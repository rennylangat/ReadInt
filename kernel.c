/* ACADEMIC INTEGRITY PLEDGE                                              */
/*                                                                        */
/* - I have not used source code obtained from another student nor        */
/*   any other unauthorized source, either modified or unmodified.        */
/*                                                                        */
/* - All source code and documentation used in my program is either       */
/*   my original work or was derived by me from the source code           */
/*   published in the textbook for this course or presented in            */
/*   class.                                                               */
/*                                                                        */
/* - I have not discussed coding details about this project with          */
/*   anyone other than my instructor. I understand that I may discuss     */
/*   the concepts of this program with other students and that another    */
/*   student may help me debug my program so long as neither of us        */
/*   writes anything during the discussion or modifies any computer       */
/*   file during the discussion.                                          */
/*                                                                        */
/* - I have violated neither the spirit nor letter of these restrictions. */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/* Signed: Naomi Burhoe, Temilolu Fayomi, Rawan Tohari__ Date:__9/24/2019_*/
/*                                                                        */
/*                                                                        */
/* 3460:4/526 BlackDOS2020 kernel, Version 1.03, Fall 2019.               */
#include<stdio.h>

void handleInterrupt21(int, int, int, int);
void printString(char*, int);
void readString(char*);
void readInt(int*);
void writeInt(int, int);
void printLogo();

void main()
{
	char food[25], adjective[25], color[25], animal[25];
	int temp;
	makeInterrupt21();
	printLogo();
	temp = 10;

	interrupt(33, 0, "Enter a number: \0", 0, 0);
	readInt(10);
	//writeInt(temp, 0);

	/*interrupt(33,0,"\r\nWelcome to the Mad Libs kernel.\r\n\0",0,0);
	interrupt(33,0,"Enter a food: \0",0,0);
	interrupt(33,1,food,0,0);
	temp = 0;

	while ((temp < 100) || (temp > 120)) {
	   interrupt(33,0,"Enter a number between 100 and 120: \0",0,0);
	   interrupt(33,14,&temp,0,0);


	}

	interrupt(33,0,"Enter an adjective: \0",0,0);
	interrupt(33,1,adjective,0,0);
	interrupt(33,0,"Enter a color: \0",0,0);
	interrupt(33,1,color,0,0);
	interrupt(33,0,"Enter an animal: \0",0,0);
	interrupt(33,1,animal,0,0);
	interrupt(33,0,"Your note is on the printer, go get it.\r\n\0",0,0);
	interrupt(33,0,"Dear Professor O\'Neil,\r\n\0",1,0);
	interrupt(33,0,"\r\nI am so sorry that I am unable to turn in my program at this time.\r\n\0",1,0);
	interrupt(33,0,"First, I ate a rotten \0",1,0);
	interrupt(33,0,food,1,0);
	interrupt(33,0,", which made me turn \0",1,0);
	interrupt(33,0,color,1,0);
	interrupt(33,0," and extremely ill.\r\n\0",1,0);
	interrupt(33,0,"I came down with a fever of \0",1,0);
	interrupt(33,13,temp,1,0);
	interrupt(33,0,". Next my \0",1,0);
	interrupt(33,0,adjective,1,0);
	interrupt(33,0," pet \0",1,0);
	interrupt(33,0,animal,1,0);
	interrupt(33,0," must have\r\nsmelled the remains of the \0",1,0);
	interrupt(33,0,food,1,0);
	interrupt(33,0," on my computer, because he ate it. I am\r\n\0",1,0);
	interrupt(33,0,"currently rewriting the program and hope you will accept it late.\r\n\0",1,0);
	interrupt(33,0,"\r\nSincerely,\r\n\0",1,0);
	interrupt(33,0,"(your name here)\r\n\0",1,0);*/
	while (1);
	while (1);
}

void printString(char* c, int d)
{
	if (d == 1)
	{
		while (*c != '\0') {

			char p = *c;

			interrupt(23, p, 0, 0, 0);
			++c;
		}
	}
	else
	{
		while (*c != '\0') {
			char p = *c;
			interrupt(16, 14 * 256 + p, 0, 0, 0);
			++c;
		}
	}
}



void readString(char* c)
{
	int i = 0;
	char* p;
	*p = interrupt(22, 0, 0, 0, 0);
	while (*p != 0xD) {
		interrupt(16, 14 * 256 + *p, 0, 0, 0);
		if (*p == 0x8 && i > 0)
		{
			i = i - 1;
		}
		else
		{
			c[i] = *p;
			++i;
		}
		*p = interrupt(22, 0, 0, 0, 0);
	}
	c[i] = 0xD;
	++i;
	c[i] = 0x0;
	//printString(c, 0);
	return c;

}

int mod(int a, int b)
{
	int x = a;
	while (x >= b) x = x - b;
	return x;
}

int div(int a, int b)
{
	int q = 0;
	while (q * b <= a) q++;
	return (q - 1);
}

void readInt(int* n)
{
	char line[10];
	int n;
	char* result;

	result = [readString(line)];
	scanf(result, "%d", &n)
		/**
		  while(line[i] != '\0')
		  {
			   result = (result * 10) + (line[i++] - '0');
			}


			*n = result;
			*/

		return n;
	printf(n);

}


void writeInt(int x, int d)
{
	//convert integer x to a character array
	//int i = 0;
	int y = x;
	/**char num[10];
	char z[10];
	int j = 0;*/
	char z[10];

	/**
	while(y != 0)
	{
	   num[i++] = (char) (mod(y, 10) + '0');
	   y = div(y, 10);
	}

	for(j = 0; j < i; j++){
		z[j] = num[(i - 1) - j];
	}

	z[j] = '\0';
	*/
	itoa(y, z, d);


	printString(z, d);


}


void printLogo()
{
	printString("       ___   `._   ____  _            _    _____   ____   _____ \r\n\0", 0);
	printString("      /   \\__/__> |  _ \\| |          | |  |  __ \\ / __ \\ / ____|\r\n\0", 0);
	printString("     /_  \\  _/    | |_) | | __ _  ___| | _| |  | | |  | | (___ \r\n\0", 0);
	printString("    // \\ /./      |  _ <| |/ _` |/ __| |/ / |  | | |  | |\\___ \\ \r\n\0", 0);
	printString("   //   \\\\        | |_) | | (_| | (__|   <| |__| | |__| |____) |\r\n\0", 0);
	printString("._/'     `\\.      |____/|_|\\__,_|\\___|_|\\_\\_____/ \\____/|_____/\r\n\0", 0);
	printString(" BlackDOS2020 v. 1.03, c. 2019. Based on a project by M. Black. \r\n\0", 0);
	printString(" Author  Naomi, Temilolu, Rawan .\r\n\r\n\0", 0);
}

/* MAKE FUTURE UPDATES HERE */
/* VVVVVVVVVVVVVVVVVVVVVVVV */



/* ^^^^^^^^^^^^^^^^^^^^^^^^ */
/* MAKE FUTURE UPDATES HERE */

void handleInterrupt21(int ax, int bx, int cx, int dx)
{
	switch (ax) {
	case 0: printString(bx, cx); break;
	case 1:  readString(bx); break;
		/*	case 2: case 3: case 4: case 5: */
		/*      case 6: case 7: case 8: case 9: case 10: */
		/*      case 11: case 12: */
	case 13: writeInt(bx, cx);
	case 14: readInt(bx); break;
		/*case 15: */
	default: printf("General BlackDOS error.\r\n\0");
	}
}
