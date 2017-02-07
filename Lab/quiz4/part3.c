#include <stdio.h>
void rect(int width,int height,int spacing_left);

int main()
{
	rect(50,50,0);
	return 0;
}
void rect(int width,int height,int spacing_left)
{
	if(width>0 && height>0 && spacing_left >=0)
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
