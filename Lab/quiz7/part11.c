#include <stdio.h>
char *concat(char *destination,char *source);
int main()
{
	char dee[20];
	dee[0]='a';
	dee[1]='b';
	dee[2]='\0';
	char *source="onder";
	printf("%s\n",concat(dee,source) );
	printf("oldu\n");

	return 0;
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