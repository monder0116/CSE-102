#include <stdio.h>

void triangle(int width);
void pine(int,int);
void rect(int width,int height,int spacing_left);

int main()
{
	
	pine(2,0);
	return 0;

}
void pine(int width,int triangle_n)
{
	if(width>=3 && (width%2==1) && triangle_n>0){
		int i;
		for(i=1;i<=triangle_n;i++){
			triangle(width);
		}
		rect(width/2,width/2,(width/4+1));
	}
}
void rect(int width,int height,int spacing_left)
{
	if(width>0 && height>0)
	{
		int a,b,c,d;

		for(a=1;a<=height;a++)
		{
			for(b=1;b<=spacing_left;b++)
			{

				printf(" ");
	
			}
			if(a==1 || a==height)
			{
				for(c=1;c<=width;c++)
				{
					printf("*");

	
				}
				printf("\n");
			}else
			{
				printf("*");
				for(d=1;d<=width-2;d++)
				{
					printf(" ");
				}
				printf("*");			
				printf("\n");
			}
	
		}
	}
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
			printf("\n");
	}
	else
	{
	printf("try again");
	}

}
