#include <stdio.h>
char *reverser(char *str);
char *concat(char *destination,char *source);
int len(char *string);
int main()
{

	char str[80]="lorem ipsum dolor sit amet";
	printf("%s\n",reverser(str) );
	return 0;
}
int len(char *string)
{
	char charstr;
	int counter=0;
	do
	{
		charstr=string[counter];
		counter++;
	} while (charstr!='\0');
	return counter;
}
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
char *reverser(char *str)
{
	char charstr;
	char *world;
	char x[300];
	world=x;
	int counter=0;
	int c1=0,a=0;
	world[0]='\0';
	int i;
	for (c1 = len(str)-1;c1>=0; c1--)
	{
		charstr=str[c1];
		if (charstr==' ')
		{
			for (i = counter,a=c1+1; i<=len(str), a<=len(str); ++i,++a)
			{
				world[counter]=str[a];
			}
		}
		str[c1]='\0';
	}
	world[len(str)+1]='\0';
	return world;

}