#include <stdio.h>
int sum(int num1,int num2,int num3,int num4);

int main()
{

	printf("%d",sum(0,0,5,5));
	
	return 0;

}

int sum(int num1,int num2,int num3,int num4)
{
	int s1,s2,s3,s4,sum,temp;
	if(num1>num2)
	{
		s1=num1;
		s2=num2;
	}
	else
	{
		s1=num2;
		s2=num1;
	}
	if(num3>num4)
	{
		s3=num3;	
		s4=num4;
	}
	else
	{
		s3=num4;
		s4=num3;

	}
	if(s3>s1)
	{
		temp=s1;
		s1=s3;
		s3=temp;
	
	}
	if(s4>s2)
	{
		temp=s2;
		s2=s4;
		s4=temp;
	
	}
	
	sum=s2+s3;
	
	return sum;
}
