#include <stdio.h>
int extremum(double a,double b, double c,double search_starting_point,
				double step_size,double *m_x,double *m_y);
int fx(int a,int b,int c,int x);
int main()
{
	double a,b;
   int res = extremum (-2, 5, 5, -3, 3, &a, &b);
	printf("mx%f,my%f,n%d",a,b,res);
	return 0;
}
int extremum(double a,double b, double c,double search_starting_point,
            double step_size,double *m_x,double *m_y)
{
    int c1;
	int count=0;
   if(a>0){
				int y0;
				int y1;
				y0=fx(a,b,c,search_starting_point);
				y1=fx(a,b,c,search_starting_point);
				int x;
				x=search_starting_point;
				int n=0;
			  	while(y0<=y1)
			  	{
			  		*m_x=x;
			  		y1=fx(a,b,c,*m_x);
			  		*m_y=y1;
			  		x=x+step_size;
			  		y0=fx(a,b,c,x);
			  		++n;

			  	}
			  	return n;

  }else	
  {
		  		int y0;
			int y1;
			y0=fx(a,b,c,search_starting_point);
			y1=fx(a,b,c,search_starting_point);
			int x;
			x=search_starting_point;
			int n=0;
		  	while(y0>=y1)
		  	{
		  		*m_x=x;
		  		y1=fx(a,b,c,*m_x);
		  		*m_y=y1;
		  		x=x+step_size;
		  		y0=fx(a,b,c,x);
		  		++n;

		  	}
		  	return n;
  }
            
            
}
            
int fx(int a,int b,int c,int x)
{
	return a*x*x+b*x+c;
}

