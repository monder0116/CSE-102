#include <stdio.h>
#include <string.h>
char *reverser(char *str);
char *rpos(char *str,char ch);
char *concat(char *destination,char *source);
int rposint(char *str,char ch);
int main()
{
	char str[256]="mehmet deneme önder 2 c";
	printf("%s\n",reverser(str));
	
	return 0;
}
char *reverser(char *str)
{

	char new[256];

	int firstlen=strlen(str);
	int sonbosluk;
	int enson;
	while(rpos(str,' ')!=NULL){	
		strcat (new,rpos(str,' '));
		enson=rposint(str,' ');
		printf("%d\n",enson );
		str[enson]='\0';
	}
	strcpy(str,new);
	str[firstlen+1]='\0';
	return str+1;
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
int rposint(char *str,char ch){

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
			return counter;
		}

	}
	return -1;
}