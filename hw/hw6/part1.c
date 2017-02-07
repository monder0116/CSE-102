/*############################################################################*/
/*HW06_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 4, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* calculate the character frequency of a given string. program will	      */
/*	handle only the ASCII letters and digits. Any other characters            */
/*	 such as punctuation marks and											  */
/* whitespaces will be handled as the same								      */
/*										 									  */
/* 				      														  */
/*Inputs:                                                                     */
/*----------																  */
/*	string  																  */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* Array to total number of characters									 	  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*		 					standart functions								  */
#include <stdio.h>


void freq(char *str, int *fr);
int main()
{
	int fr[37];
	int counter;
	int i;
	freq("abCd Ef ghIj kLM noprçç..231146265+--/*/-,0 0s<<tuv abAyzwxq 123 4 533 6 7 890 00 ?? |",fr);
	for (i = 0; i < 37; ++i)
	{
		printf("%d\n",fr[i] );
	}
	return 0;

}
void freq(char *str,int *fr)
{
	/*this is take a char from the string*/
	char Achar;
	/*this is counter for loops*/
	int counter;
	/*initialize the fr array to zero*/
	for ( counter = 0; counter < 37; ++counter)
	{
		fr[counter]=0;
	}
	counter=0;
	do{
		/*Get a char*/
		Achar=str[counter];
		if (Achar!='\0')
		{
			/* if char is Upper case and char is between with A and Z*/
			if (Achar>='A' && Achar<='Z')
			{
				fr[Achar-65]+=1;
			}
			/* if char is lower case and char is between with A and Z*/
			else if(Achar>='a' && Achar<='z')
			{
				fr[Achar-97]+=1;
			}
			/* if char is number and between with 1 and 9*/
			else if (Achar>=48 && Achar<=57)
			{
				fr[Achar-48+26]+=1;

			}
			/* if anathor char */
			else {
				fr[36]+=1;
			}
		}
		counter++;
	}while(Achar!='\0');

}