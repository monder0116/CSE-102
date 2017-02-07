#include <stdio.h>
#include <math.h>
int lwRevInt(int input);
int main()
{
	printf("%d\n",lwRevInt(1234) );
	return 0;


}
int lwRevInt(int input)
{
	
	int len=floor(log10(input))+1;
	int anumber=(input %10);
	if (input<=0)
	{
		return -1;
	}
	if (len>1)
	{
		return (anumber*pow(10,len-1)+lwRevInt(input/10));
	}
	else
	{
		return anumber;
	}

}