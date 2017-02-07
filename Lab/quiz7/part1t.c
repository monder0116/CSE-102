#include <stdio.h>
char *concat(char *destination,char *source);
int compare(char *str1,char *str2);
int absld(int number);
char *copystr(char *destination, char *source);
char *rpos(char *str,char ch);
/*part1*/
char *concat(char *destination,char *source)
{
	int exit=0;
	int counter=0,counter2=0;
	char destchar,sourchar;
	do
	{
		destchar=destination[counter];
		if (destchar=='\0')
		{	
			printf("%c\n",destchar );
			sourchar=source[counter2];
			while(sourchar!='\0')
			{
				sourchar=source[counter2];
				destination[counter]=sourchar;
				counter++;
				counter2++;

			}
			destination[counter]='\0';
			exit=1;
		}
		else
		{
			counter++;
		}
	}while(exit!=1);
	return destination;

}

/*part2*/
int compare(char *str1,char *str2)
{
	int c1,c2;
	char charst1,charst2;
	c1=0;
	c2=0;
	int quit=0;
	int result=0;
	do
	{
		charst1=str1[c1];
		charst2=str2[c2];
		if (charst1!='\0' && charst2!='\0')
		{
				charst2=str2[c2];
				charst1=str1[c1];

				if (absld(charst1-charst2)==32 || charst1-charst2==0)
				{
					result=0;
				}
				else if (charst1-charst2<0)
				{
					result=1;
					quit=1;

				}
				else if(charst1-charst2>0)
				{
					result=-1;
					quit=1;
				}
				c2++;
				c1++;
			}
	}while(quit!=1 && charst1!='\0' && charst2!='\0');

	return result;
}
int absld(int number)
{

	if (number<0)
	{
		return -number;
	}
	else
	{
		return number;
	}
}
/*part3*/
char *copystr(char *destination, char *source)
{
	int counter=0;
	int quit=0;
	do
	{

		if (source[counter]!='\0')
		{
			destination[counter]=source[counter];
		}else
		{
			destination[counter]='\0';
			quit=1;

		}
		counter++;
	}while(quit!=1);
	return destination;

}
/*4*/
char *rpos(char *str,char ch){

	char charstr;
	int counter=0;
	int len=0;

	do
	{
		charstr=str[counter];
		if (charstr!='\0')
		{
			len++;
		}
		counter++;
	} while (charstr!='\0');

	for (counter = len; counter>=0; counter--)
	{
		if (str[counter]==ch)
		{
			return str+counter;
		}

	}
	return NULL;
}