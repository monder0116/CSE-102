#include <stdio.h>
int read_time(int *h ,int *m);
typedef enum
{
	false,true
}bool;
int main()
{
	int h,m;
	if (read_time(&h,&m)==0)
	{
		printf("%d:%d",h,m);
	}
	else
	{
		printf("yanlış");
	}
}
int read_time(int *h ,int *m)
{
		bool exit=false;
		bool first=false;
	while(1)
	{
		int read,hour;
		char buffer;
		
	
		read=scanf("%d",&hour);

		if(read!=1)
		{

			scanf("%c",&buffer);

			
			if (buffer =='.' || (int)buffer == 10)
			{
				exit=true;
				break;
			}
			if (buffer==':')
			{
				break;
			}
		}
		else{
			if (first==false)
			{
				*h=hour;
				first=true;	
			}else
			{
				if (*h*10+hour<=24)
				{		
					*h=*h*10+hour;
				}
				else
				{	
					exit=true;
					break;
				}
			}

		}
	}
	first=false;
	while(!exit)
	{	
		int read,min;
		char buffer;
		
	
		read=scanf("%d",&min);

		if(read!=1)
		{

			scanf("%c",&buffer);

			
			if (buffer =='.' || (int)buffer == 10)
			{
				exit=true;
				break;
			}
			if (buffer==':')
			{
				break;
			}
		}
		else{
			if (first==false)
			{
				*m=min;
				first=true;
				
			}else
			{

			
				if (*m*10+min<=59)
				{		
					*m=*m*10+min;
					break;
				}
				else
				{	
					exit=true;
					break;
				}
			}

		}


	}
	if (exit)
	{
		/* code */
		return -1;
	}
	else
	{
		return 0;
	}
}

