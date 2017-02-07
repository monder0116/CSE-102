#include <stdio.h>

int main()
{
	float a,b,c,x,px;
	printf("a   : ");
	scanf("%f",&a);
	printf("b   : ");
	scanf("%f",&b);
	printf("c   : ");
	scanf("%f",&c);
	printf("x   : ");
	scanf("%f",&x);
	px=(a*x*x)+(b*x)+c;
	printf("P(x): %.2f",px);
	return 0;
	

}

