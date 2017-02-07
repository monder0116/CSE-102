#include <stdio.h>
#include <string.h>
#define MAX_NAME 25
#define MAX_NEIGHBOR 10
typedef struct 
{
	char name[25];
	int population;
	char neighbors[10][26];
	int flag;
}Country;
int lwFind(Country arr[],int size,char *query);
int lwSort(Country arr[],int size,char choice);
int lwIsAcc(Country arr[],int size,char *source,char *target);
int main()
{
	
	Country array[20];
	
	array[0].population=8;
	strcpy(array[0].name,"tr");
	strcpy(array[0].neighbors[0],"uk");
	array[1].population=4;
	strcpy(array[1].name,"uk");
	array[1].population=3;
	printf("%d\n",lwIsAcc(array,2,"tr","uk") );
	return 0;
}	

int lwSort(Country arr[],int size,char choice)
{
	int i,j;
	if (size<=0)
	{
		return -1;
	}
	if (choice !='n' && choice !='p')
	{
		return -1;
	}
	
	if (choice=='p')
	{

		for (i = 0; i < size; ++i)
		{
			for (j = i; j<size; ++j)	
			{
				if (arr[i].population>arr[j].population)
				{
					Country temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < size; ++i)
		{
			for (j = i; j<size; ++j)	
			{
				if (strcmp(arr[i].name,arr[j].name)>0)
				{
					Country temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
			}
		}
	}
	return 0;

}
int FindCountry2(Country *countries,int size,char *sourceC)
{
	int i;
	int found=0;
	for ( i = 0; i < size; ++i)
	{
		if (strcmp(countries[i].name,sourceC)==0)
		{
			found=1;
		}
	}
	return found;
}
Country FindCountry(Country *countries,int size,char *sourceC)
{
	int i;
	Country empty;
	empty.flag=0;
	for ( i = 0; i < size; ++i)
	{
		if (strcmp(countries[i].name,sourceC)==0)
		{
			return countries[i];
		}
	}
	return empty;
}
int lwIsAcc(Country arr[],int size,char *source,char *target)
{
	/*Take the Source Country Values*/

	Country sourceC;
	int NewWay;
	int SubWay;/* Another way*/
	int i,j;
	if (FindCountry2(arr,size,source)==0 || strcmp(source,target)==0)
	{
		return -1;
	}
	sourceC=FindCountry(arr,size,source);
	
	/* Initialize */
	
	/* At first The Found zero*/
	NewWay=-1;
	SubWay=-1;
	/*Search in Neightbors of Source Country*/
	for (i = 0; i < MAX_NEIGHBOR; ++i)
	{
		/*if the neighbor is equal to target country  */
		if (strcmp(sourceC.neighbors[i],target)==0)
		{
			return NewWay=0;
		}
	}
	/*it could be, the neigthbor not equal to target country but the neighbor of	
			neighor can be the target country  */
	if (NewWay==-1)
	{
		for (j = 0; j < MAX_NEIGHBOR; ++j)
		{
		/*search in neightbors of the main country*/
			if (sourceC.neighbors[i]==NULL && strcmp(source,sourceC.neighbors[j])!=0 )
			{
					/* if the neigthbor is in Country array go on*/
					if (FindCountry2(arr,size,sourceC.neighbors[j]) )
					{
						/* This is the recursive to find the another way to 
							the minimum way,the neighbor will be source country*/
						SubWay=lwIsAcc(arr,size,sourceC.neighbors[j],target);
						
						if (SubWay==0 && NewWay==-1)
						{
							NewWay=SubWay;
						}

					}		
			}
			
		}
	}
	
	return NewWay;
}


int lwFind(Country arr[],int size,char *query)
{
	int i;
	if (size<=0 || query==NULL)
	{
		return -1;
	}
	for ( i = 0; i < size; ++i)
	{
		if (strcmp(arr[i].name,query)==0)
		{
			return i;
		}
	}
	return -1;
}
