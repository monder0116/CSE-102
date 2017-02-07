#include <stdio.h>


int main()
{
	int number,first,second,third,total;
	printf("Please enter a 3-digit number: ");
	scanf("%d",&number);
	first=number/100;
	second=((number/10)%10)*10;
	third=((number%100)%10)*100;
	total=first+second+third;
	printf("Reverse of the number: %d \n",total);
	return 0;
}

