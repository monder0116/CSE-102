/*############################################################################*/
/*HW06_part2_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 4, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* program for finding substring(s) in a given string. Instead of matching	  */
/*	the exact substring, you are asked to match only odd indexed characters	  */
/*										 									  */
/* 				      														  */
/*Inputs:                                                                     */
/*----------																  */
/*	string  																  */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* string pointer to first found index										  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*		 					standart functions								  */
#include <stdio.h>
char *matcher(char *haystack, char *needle);
int len(char *string);
int main()
{
	char *a;
	int i;
	a=matcher("ab", "ab");
	if (a!=NULL)
	{
			printf("%s\n",a );
	}
	else
		printf("null\n");

	return 0;


}
/*calculate the string length*/
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
char *matcher(char *haystack, char *needle){
	/*This is counters*/
	int c1=0,c2=0; 
	/*This help to while condition to exit and take the state which
		 chars equal or not*/
	int state1=0,quit=0; 
	/*This is pointer to index of first equal */
	int point=0;
	/* haychar show the counter's index and firstneed show the [0] index*/
	char haychar,FirstNeed;
	/*when haychar equal to firstneed then look the nextchar to equal or not*/
	char Nextneed;
	if (len(haystack)<len(needle))
	{
		return NULL;
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
						point=c1;
					}else
					{
						state1=0;
						quit=1;
					}

				}
				c2++;
			}while(Nextneed!='\0' && !quit);

		}
		c1++;
	}while(haychar!='\0' && state1==0);
	if (state1==1)
	{
		return &haystack[point];
	}
	else
	{
		return NULL;

	}
}