#include <stdio.h>

int extremum(double a,double b, double c,double search_starting_point,
            double step_size,double *m_x,double *m_y);

int main()
{
   	double x,y;
	int s;
	s=extremum(1,1,1,-3,1,&x,&y);
	printf("x:%f,y:%f,step:%d",x,y,s);
	return 0;

}

int extremum(double a,double b, double c,double search_starting_point,
            double step_size,double *m_x,double *m_y)
{
    int c1;
    double temp,pre;
	if(a==0 || step_size<=0)
		return -1;
	temp=a*(search_starting_point*search_starting_point)+b*search_starting_point+
		c;
	pre=a*(search_starting_point*search_starting_point)+b*search_starting_point+
		c;
	int x;
	x=search_starting_point;
  	while(temp<=pre)
	{
		x+=step_size;
		y2=a*(x)*(x)+b*(x)+c;
		
		printf("%d %f\n",x,y2);
	}
    return c1;
            
            
}
            
            
