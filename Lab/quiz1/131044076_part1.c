#include <stdio.h>

int main()
{
	int number;
	printf("Please enter a 3-digit number: ");
	scanf("%d",&number);
	printf("%d\n",number/100);
	printf("%d\n",(number/10)%10);
	printf("%d\n",(number%100)%10);
	return 0;

}

