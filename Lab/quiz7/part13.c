#include <stdio.h>
char *copystr(char *destination, char *source);
int main()
{

	char str[20];
	char *source="mehmet";
	printf("%s\n",copystr(str,source) );
	return 0;
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