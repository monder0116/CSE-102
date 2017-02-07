#include <stdio.h>

int main()
{
	double radius,area,perimeter;
	double pi;
	pi=3.14;
	printf("Circle radius: ");
	scanf("%lf",&radius);
	area=pi*(radius*radius);
	perimeter=2*pi*radius;
	printf("Circle perimeter: %.2f\n",perimeter);
	printf("Circle area: %.2f\n",area);
	return 0;
}

