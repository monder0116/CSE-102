#include <stdio.h>

void triangle(int width);
int main()
{
	triangle(2);
	return 0;
}
void triangle(int width)
{
	int i,j,k,m;
	if( (width % 2 ==1) && (width>2)){
		for(i=1;i<(width/2)+1;i++)
		{
				for(j=i;j<=(width/2);j++)
				{
					printf(" ");
				}
				if(i==1)
				{	
					printf("*");
				}else
				{
					printf("*");
					for(k=1;k<(2*(i-1));k++)
					{
						printf(" ");

					}
					printf("*");
				}
				printf("\n");
		}
			for(m=1;m<=width;m++)
			{
				printf("*");
		
			}
	}
	
}
