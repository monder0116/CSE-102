#include <stdio.h>

char *rpos(char *str,char ch);


int main()
{

	char str[20]="hello world";
	char *a=rpos(str,'d');
	if (a!=NULL)
	{
			printf("%s\n",a);
	}
	else{
		printf("null\n");
	}

	return 0;
}
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