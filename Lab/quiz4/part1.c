#include <stdio.h>

double avg(int x);

int main()
{
	printf("%f",avg(7));
	return 0;

	

}
double avg(int sentinel)
{
	double number,sum,counter,avg;
	sum=0;
	avg=0;
	counter=0;
	do
	{
		printf("Please Enter a number");
		scanf("%lf",&number);
		if(number!=sentinel)
		{	
			counter+=1;
			sum+=number;
		}
	}while(number!=sentinel);
	if(counter!=0){
			avg=sum/counter;
	}else
	{	
		counter=1;
		avg=sum/counter;
	}
	
	return avg;


}

