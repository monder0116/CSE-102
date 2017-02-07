#include <stdio.h>

/*############################################################################*/
/*HW04_part2_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on March 20, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* Get a positive integer from the user and print out a simple ASCII art.,    */
/*	The program will not print out any message and wait input 				  */
/*	from the user. Beside the number to be printed, the user will			  */
/*	enter the width of the border and the character to be used while printing.*/
/*										 									  */
/* 				      														  */		
/*Inputs:                                                                     */
/*----------																  */
/*	User should enter at most 5-digit integer, your program should			  */
/*	print nothing if integer is higher than 99999. The program will wait 	  */
/*	for the input from the user until he enters a negative number.			  */
/*                            												  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* print the number as simple ASCII art., 									  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*		 					standart functions								  */

/*this is control the number if is true ,print the digits					  */
int printNumber(int num,int borderWidth,char borderChar);
/* this is take number and borderwidth,borderchar until enter negative number*/
void getInputs(int *num,int *borderWidth,char *borderchar);


/*							The Helper functions Prototype					*/

/*this is calculate the length of number*/
int len(int number);
/*this is calculate the power of number to count*/
double Power(double number,double count);
/*this is art to border which is left,right and bottom*/
void BorderLeftRight(int width,char borderChar);
void BorderTopBottom(int width,char borderChar,int Length);
/*print the number of char style*/
void printone(int step,char borderchar);/*the step means the x position*/
void printtwo(int step,char borderchar);
void printthree(int step,char borderchar);
void printfour(int step,char borderchar);
void printfive(int step,char borderchar);
void printsix(int step,char borderchar);
void printseven(int step,char borderchar);
void printeight(int step,char borderchar);
void printnine(int step,char borderchar);
void printzero(int step,char borderchar);
int main()
{
	int num,borderw;
	char border;
	while(1)
	{
		getInputs(&num,&borderw,&border);

		

	}

}
/*this is calculate the length of number*/
int len(int number)
{ 
	int Length,BiggerPower;
	BiggerPower=0;
	Length=0;
	while(BiggerPower<=number)
	{
		Length+=1;
		BiggerPower=Power(10,Length);
	}
	return Length;
}
/*this is calculate the power of number to count*/
double Power(double number,double count)
{
	int c1; /*This is for counter		*/
	double Result;
	Result=1;
	for(c1=1;c1<=count;c1++)
	{
		Result *=number;
	}
	return Result;
	
}
void getInputs(int *num,int *borderWidth,char *borderchar)
{
		scanf("%d %d %c",num,borderWidth,borderchar);		
}
int printNumber(int num,int borderWidth,char borderChar)
{
	int Length;
	int digit,h1,h2;/* h1,h2 means helper declaration to calculate the digit*/
	int c1,c2;/*this is for loops,c1 loop for with,c2 loop for find digits*/
	c1=0;
	Length=len(num);
	if(num<0 || num>99999)
		return 0;
	BorderTopBottom(borderWidth,borderChar,Length);
	while(c1<7) /*this is position of x state ,turn it until to 7 */
	{
		for(c2=Length;1<=c2;c2--)/*turn to find the digit then control it after	
																	print	*/
		{
			if(c2==Length)
			{
				/*/print the left border in first digit*/
				BorderLeftRight(borderWidth,borderChar);
			}
			h1=Power(10,c2);
			h2=Power(10,c2-1);
			digit=(num % h1)/h2;		
				if(digit==0)
				{
					/*print the zero of char style which x position c1 */
					printzero(c1,borderChar);
				}
				else if(digit==1)
				{	
					/*print the one of char style which x position c1 */
					printone(c1,borderChar);
				}
				else if(digit==2)
				{
					/*print the two of char style which x position c1 */
					printtwo(c1,borderChar);
				}
				else if(digit==3)
				{
					/*print the three of char style which x position c1*/
					printthree(c1,borderChar);
				}
				else if(digit==4)
				{
					/*print the four of char style which x position c1*/
					printfour(c1,borderChar);
				}
				else if(digit==5)
				{
					/*print the five of char style which x position c1*/
					printfive(c1,borderChar);
				}
				else if(digit==6)
				{
					/*print the six of char style which x position c1*/
					printsix(c1,borderChar);
				}
				else if(digit==7)
				{
					/*print the seven of char style which x position c1*/
					printseven(c1,borderChar);
				}
				else if(digit==8)
				{
					/*print the eight of char style which x position c1*/
					printeight(c1,borderChar);
				}
				else if(digit==9)
				{
					/*print the nine of char style which x position c1*/
					printnine(c1,borderChar);
				}
			if(c2==1) 
			{
				/*print the right border in end digit*/
				BorderLeftRight(borderWidth,borderChar);
			}
		}
		printf("\n");
		c1++;
	}
	BorderTopBottom(borderWidth,borderChar,Length);
	return 1;
}

/*There are ten function in bellow, That are the style of the number 
  which is arted by the char according to x position */

void printone(int step,char borderchar)
{
	
	switch(step){
	case 0:	
			printf("       ");
			break;
	case 1:
			printf("   %c   ",borderchar);
			break;
	case 2:
			printf("  %c%c   ",borderchar,borderchar);
			break;
	case 3:
			printf("   %c   ",borderchar);
			break;
	case 4:
			printf("   %c   ",borderchar);
			break;
	case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
	case 6:
			printf("       ");
			break;
	}
}
void printtwo(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("    %c  ",borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("  %c    ",borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printthree(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("    %c  ",borderchar);
			break;
		case 3:
			printf("   %c%c  ",borderchar,borderchar);
			break;
		case 4:	
			printf("    %c  ",borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printfour(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 2:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("    %c  ",borderchar);
			break;
		case 5:
			printf("    %c  ",borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printfive(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("  %c    ",borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("    %c  ",borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printsix(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("  %c    ",borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}

void printseven(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("    %c  ",borderchar);
			break;
		case 3:
			printf("    %c  ",borderchar);
			break;
		case 4:	
			printf("    %c  ",borderchar);
			break;
		case 5:
			printf("    %c  ",borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printeight(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printnine(int step,char borderchar)
{	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 3:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 4:	
			printf("    %c  ",borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
void printzero(int step,char borderchar)
{	
	
	switch(step)
	{
		case   0:
			printf("       ");
			break;
		case 1:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 2:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 3:
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 4:	
			printf("  %c %c  ",borderchar,borderchar);
			break;
		case 5:
			printf("  %c%c%c  ",borderchar,borderchar,borderchar);
			break;
		case 6:
			printf("       ");
			break;
	}
}
/* This is for counter to art the border of left and right*/
void BorderLeftRight(int width,char borderChar)
{
	int c1;
	for(c1=1;c1<=width;c1++)
	{
		printf("%c",borderChar);
	}
}
/* This is for counter to art the border of top and bottom*/
void BorderTopBottom(int width,char borderChar,int Length)
{
	int c1,c2;
	for(c1=1;c1<=width;c1++)
	{
		for(c2=1;c2<=width*2+7*Length;c2++)
		{
			printf("%c",borderChar);

		}
		printf("\n");
	}
}
