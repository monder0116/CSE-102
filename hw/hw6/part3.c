/*############################################################################*/
/*HW06_part3_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 4, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* program for finding substring(s) number in a given string. Instead of	  */
/*	 matching	  															  */
/*	the exact substring, you are asked to match only odd indexed characters	  */
/*										 									  */
/* 				      														  */
/*Inputs:                                                                     */
/*----------																  */
/*	string  																  */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* substring count to found in string										  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*		 					standart functions								  */
#include <stdio.h>
int len(char *string);
int count(char *haystack, char *needle);
int main()
{

	int a=count("ececece  ece","ece");
	printf("%d\n",a );
	return 0;
}
int len(char *string)
{
	int counter=0;
	char chr;
	do
	{
		chr=string[counter];
		counter++;
	}while(chr!='\0');

	return counter;
}
int count(char *haystack, char *needle){
	/*This is counters for loops*/
	int c1=0,c2=0; 
	/*this is total substring piece in string*/
	int Count=0;
	/*This help to while condition to exit and take the state which
		 chars equal or not*/
	int state1=0,quit=0; 
	/* haychar show the counter's index and firstneed show the [0] index*/
	char haychar,FirstNeed;
	/*when haychar equal to firstneed then look the nextchar to equal or not*/
	char Nextneed;
	if (len(haystack)<len(needle))
	{
		return 0;
	}
	do{
		haychar=haystack[c1];
		/*the new char must equal to needle of first index so equal 
			to counter2 to zero*/
		c2=0;
		FirstNeed=needle[c2];
		/*if the first chars are equal to each other check the 
			other chars*/ 
		if (haychar==FirstNeed )
		{
			/*initialize again the counters*/
			quit=0;
			state1=0;

			do
			{
				/*scan the needle of chars to equal to string chars*/
				Nextneed=needle[c2];
				if (Nextneed!='\0' && c2%2==0 )
				{

					haychar=haystack[c2+c1];
					/*if each of one needle char not equal to string exit from 
						the loop else save the pointer then control to the next*/
					if (haychar==Nextneed )
					{
						state1=1;
					}else
					{
						state1=0;
						quit=1;
					}

				}
				/* if substring equal to string increase the count*/
				if (Nextneed=='\0')
				{
					if (state1)
					{
						Count++;
					}
					
				}
				c2++;
			}while(Nextneed!='\0' && !quit);

		}
		c1++;
	}while(haychar!='\0');
	return Count;
}