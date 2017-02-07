#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int x1,y1,x2,y2,Avgspeed;
	double ArriveHour,LenAB;
	double hx,hy;
	printf("Coordinates of the A: ");
	scanf("%d %d",&x1,&y1);
	printf("Coordinates of the B: ");
	scanf("%d %d",&x2,&y2);	
	printf("Average velocity of the vehicle: ");
	scanf("%d",&Avgspeed);
	LenAB=sqrt(pow(abs(y2-y1),2) + pow(abs(x2-x1),2));
	ArriveHour=LenAB/Avgspeed;
	printf("Arrival time: %.2f hour(s) \n",ArriveHour);
	hx=(abs(x2-x1)/ArriveHour)+x1;
	hy=(abs(y2-y1)/ArriveHour)+y1;
	printf("Coordinates of the vehicle after 1 hour: %.2f %.2f \n",hx,hy);
	
	return 0;
}
