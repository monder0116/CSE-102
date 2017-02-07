#include <stdio.h>
int compare(char *str1,char *str2);
int absld(int number);

int main()
{
	char *s1="araba";
	char *s2="arada";
	printf("%d\n",compare(s1,s2));
	return 0;

}
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
					result=-1;
					quit=1;

				}
				else if(charst1-charst2>0)
				{
					result=1;
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