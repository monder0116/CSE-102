
/*Author: Mehmet Önder*/
#include <stdio.h>
typedef enum 
{
	false,true


}bool;
int readTime(char arrChr[],int *h,int *m);
int main()
{
		char array[]={' ',' ','3',' ','4',':','c','a','3','4','t'};
		int h,m;
		int s=readTime(array,&h,&m);
		printf("h=%d,m=%d,s=%d\n",h,m,s);
		return 0;
}

int readTime(char arrChr[],int *h,int *m)
{
	char tempc;
	int exit=0;
	int c1,c2;
	bool firsth,firstm,success;
	firsth=false;
	firstm=false;
	bool hourExit=false;
	c1=0;
	while(!firsth|| exit!=-1)
	{
		tempc=arrChr[c1];
		if(tempc=='t' || tempc=='-')
			{exit=-1;break;}
		if(tempc!=':')
		{
			if((tempc-'0'>=0) && (tempc-'0'<=9))
			{		
				if(firsth==false)
					{
						*h=(int)(tempc-'0');
						firsth=true;
					}
					else
					{
						int temph;
						temph=(int)(tempc-'0');
						if(temph+*h*10<=24)
						{
							*h *=10;
							*h +=temph;
						}else
						{
							*h *=10;
							*h +=temph;
							hourExit=true;
							exit=-1;
						}
					}
			}
			c1++;
		}
		else
		{
			hourExit=true;
			break;
		}			
	}
	bool minExit=false;
	c1++;
	while(!minExit && exit!=-1)
	{
		tempc=arrChr[c1];
		if(tempc=='t' || tempc=='-')
			{exit=-1;break;}
		if(tempc!=':')
		{
			if((tempc-'0'>=0) && (tempc-'0'<=9))
			{		
				if(firstm==false)
					{
						*m=(int)(tempc-'0');
						firstm=true;
	
					}
					else
					{
						int tempm;
						tempm=(int)(tempc-'0');
						if(tempm+*m*10<=24)
						{
							*m *=10;
							*m +=tempm;
						}else
						{
							*m *=10;
							*m +=tempm;
							minExit=true;
							exit=-1;
						}
					}
			}

		}
		else
		{
			minExit=true;
		}
		c1++;
	}
	if((*h<=24 && *h>=0 && *m<60 && *m>=0) && tempc!='-')
		{	
			success=0;}
	else
		{
			success=-1;
		}
	return success;

}
