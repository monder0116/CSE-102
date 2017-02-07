#include <stdio.h>

int max(int num1,int num2,int num3,int num4);

int main()
{

	printf("%d",max(5,5,5,20));
	
	return 0;

}

int max(int num1,int num2,int num3,int num4)
{
	int section1,section2,max;
	
	if(num1>num2)
	{
		section1=num1;	

	}
	else
	{
		section1=num2;
	}
	if(num3>num4)
	{
		section2=num3;	

	}
	else
	{
		section2=num4;

	}
	if(section1>section2)
	{
	
		max=section1;
	}
	else
	{
		max=section2;
	}

	return max;
}

