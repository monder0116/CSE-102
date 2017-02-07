#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int a,b,c;
	double x1,x2;

	printf("a        : ");
	scanf("%d",&a);
	printf("b        : ");
	scanf("%d",&b);
	printf("c        : ");
	scanf("%d",&c);
	x1=(sqrt(pow(b,2)-4*a*c)-b)/(2*a);
	x2=(-sqrt(pow(b,2)-4*a*c)-b)/(2*a);	
	printf("Roots are: %.2f %.2f \n",x1,x2);
	return 0;

}


