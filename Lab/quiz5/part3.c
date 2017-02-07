#include <stdio.h>
int extremum(double a,double b, double c,double search_starting_point,
				double step_size,double *m_x,double *m_y);
int fx(int a,int b,int c,int x);
int main()
{
	double a,b;
   int res = extremum (2, 5, 5, -3, 3, &a, &b);
	printf("mx%f,my%f,n%d",a,b,res);
	return 0;
}
int extremum(double a,double b, double c,double search_starting_point,
            double step_size,double *m_x,double *m_y)
{
    int c1;
	int count=0;
   if(a>0){
	
   	for(c1=search_starting_point;;c1+=step_size)
	{	
		count++;
		if(fx(a,b,c,c1)<fx(a,b,c,c1+step_size))	
			{return count-1;}
		*m_x=c1+step_size;
		*m_y=fx(a,b,c,c1+step_size);
		c1++;
		
	}
  }else	
  {
  		for(c1=search_starting_point;;c1+=step_size)
		{	
			count++;
			if(fx(a,b,c,c1)>fx(a,b,c,c1+step_size))	
			{return count-1;}
			*m_x=c1;
		*m_y=fx(a,b,c,c1);
		c1++;
		
		}
  }
            
            
}
            
int fx(int a,int b,int c,int x)
{
	return a*x*x+b*x+c;
}

