/*----------------------------------------------------------------------------*/
/*HW09_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 18, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* this program keeps information about world countries. 					  */
/*	There are at most 100 countries. Use Structures with the following 		  */
/*	data fields to represent countries.										  */
/*	  -Country name (at 25 characters),										  */
/*    -Country population,													  */
/*    -Country area in km squares,											  */
/*    -Number of soldiers in the army,										  */
/*    -Neighbor countries (at most 10 neighbors, 0 for island countries)	  */
/*	------------------------------------------------------------------------- */
/*    When program runs, it should offer the following options				  */
/*	(a) Add a country  (Type ‘-1’ to finish neighbor input )				  */
/*	(b) Print name of the most powerful country 							  */
/*	(among neighbors of neighbors of given country including itself )		  */
/*	(c) Print name of the largest Country  									  */
/*	(among neighbors of neighbors of given country including itself )		  */
/*	(d) Calculates and prints how many people at minimum should be seen 	  */
/*		if it need to go from a given country to another given country 		  */
/*		(Assume that if I visit a country, I would see all					  */
/*		people of that country).											  */
/*	(e) Exit the program													  */
/*																			  */
/*																			  */
/*Inputs:                                                                     */
/*----------																  */
/* -Country information 													  */
/* -source country for Largest Country								          */
/* -Source country for Powerful Country 									  */
/* -Source and target country to calculate minimum people					  */
/* Outputs:  																  */
/*---------                                                                   */
/* 	Largest Country 													      */
/*	Powerful Country 														  */
/*	minimum people number													  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
typedef struct 
{
	char CName[26];
	int Population;
	double AreaKm;
	int Soldiers;
	char Neighbors[10][26];/* Note : the name is 25 character but when the null 
								character will add , it will be 26 character*/
}CountryType;
typedef struct 
{
	int found;
	int Population;
}MinimumWayType;
/* this is create the new country then take values from user after assign them*/
CountryType AddCountry();
/* Find the powerful country compare with neightbor and neighbor of 
neighbors ,this function run with Recursive to find the neighbor of neighbors*/
CountryType PowerfulMilitary( CountryType *countries,char *sourceC,int Degree);
/* Find the country which has large country compare with neightbor and
 	neighbor of neighbors.
 	This function run with Recursive to find the neighbor of neighbors**/
CountryType LargestCountry(CountryType *countries,char *sourceC,int Degree);
/* if the source country is in country array ,return the country information*/
CountryType FindCountry(CountryType *countries,char *sourceC);
/* if the source country is in country array return 1, return 0 */
int FindCountry2(CountryType *countries,char *sourceC);
/* Find the minimum people number when it will gone from source country 
	to target country , the function run with recursive to find all 
	of neighbor of neighbor queue*/
MinimumWayType MinimumWay(CountryType *countries,char *source,char *targetC);
/* When the input is invalid ,this function clear the buffer*/
void emptyBuffer();
int main()
{
	int Last=0,quit=0;
	CountryType countries[100];
	MinimumWayType MinWay; 
	char Command,Countryinput[26],Countryinput2[26];
	while(quit!=1)
	{
		/* Take a command*/
		printf("Make your choice:\n");
		scanf(" %c",&Command);
		if (Command=='a')
		{
			countries[Last]=AddCountry();
			++Last;
		}
		else if (Command=='b')
		{
			scanf("%s",Countryinput);
			/* if the source country is in array go on*/
			if (FindCountry2(countries,Countryinput))
			{
				CountryType Powerful=PowerfulMilitary(countries,Countryinput,0);
				printf("<output>%s\n",Powerful.CName);
			}else
			{
				printf("<output>INACCESSIBLE\n" );
			}
			
		}
		else if (Command=='c')
		{
			scanf("%s",Countryinput);
			/* if the source country is in array go on*/
			if (FindCountry2(countries,Countryinput))
			{
				CountryType Largest=LargestCountry(countries,Countryinput,0);
				printf("<output>%s\n",Largest.CName);
			}
			else
			{
				printf("<output>INACCESSIBLE\n" );
			}
			
		}
		else if (Command=='d')
		{
			scanf("%s %s",Countryinput,Countryinput2);
			MinWay=MinimumWay(countries,Countryinput,Countryinput2);
			if (MinWay.found)
			{
				printf("<output>%d\n",MinWay.Population );
			}
			else
			{
				printf("<output>INACCESSIBLE\n" );
			}
		}
		else if (Command=='e')
		{
			printf("<output>Good Bye\n");
			quit=1;
		}
		else
		{
			/*if the input is not valid ,the buffer will be cleared*/
			emptyBuffer();
		}
	}
	return 0;
}
/*this funcion clear the buffer */
void emptyBuffer()
{
	while ( getchar() != '\n' );
}
/*This is return 1 or 0 ,if the country is in array 1,else 0*/
int FindCountry2(CountryType *countries,char *sourceC)
{
	int i;
	int found=0;
	for ( i = 0; i < 100; ++i)
	{
		if (strcmp(countries[i].CName,sourceC)==0)
		{
			found=1;
		}
	}
	return found;
}
/* this is return a country type which given a name of country*/
CountryType FindCountry(CountryType *countries,char *sourceC)
{
	int i;
	CountryType empty;
	empty.Soldiers=-1;
	for ( i = 0; i < 100; ++i)
	{
		if (strcmp(countries[i].CName,sourceC)==0)
		{
			return countries[i];
		}
	}
	return empty;
}
/* This Function run with recursive to find the minimum way to 
	go from source country to target country, the function search the
	neigtbor as souceCountry to arrive target country*/
MinimumWayType MinimumWay(CountryType *countries,char *source,char *targetC)
{
	/*Take the Source Country Values*/
	CountryType sourceC=FindCountry(countries,source);
	/*These are keep the value of Minimum Way*/
	MinimumWayType NewWay;
	MinimumWayType SubWay;/* Another way*/
	CountryType Neighbor;/* Keep the neighbor information*/
	int i,j;
	/* Initialize */
	
	/* At first The Found zero*/
	NewWay.found=0;
	/*Add the source country Population in minimum way*/
	NewWay.Population=sourceC.Population;
	SubWay.Population=sourceC.Population;
	

	/*Search in Neightbors of Source Country*/
	for (i = 0; i < 10; ++i)
	{
		/*if the neighbor is equal to target country  */
		if (strcmp(sourceC.Neighbors[i],targetC)==0)
		{

			NewWay.found=1;
			/*Take The Values of Target country information*/
			Neighbor=FindCountry(countries,sourceC.Neighbors[i]);
			/*Add the target Country Population in Minimum way */
			NewWay.Population+=Neighbor.Population;
			
		}
	}
	/*it could be, the neigthbor not equal to target country but the neighbor of	
			neighor can be the target country  */
	for (j = 0; j < 10; ++j)
	{
		/*search in neightbors of the main country*/
		if (strcmp(sourceC.Neighbors[j],"")!=0)
			{
				/* if the neigthbor is in Country array go on*/
				if (FindCountry2(countries,sourceC.Neighbors[j]))
				{
					/* This is the recursive to find the another way to 
						the minimum way,the neighbor will be source country*/
					SubWay=MinimumWay(countries,sourceC.Neighbors[j],targetC);
					/* add the Main Country poulation */
					SubWay.Population+=sourceC.Population;
					/* if subway is found go on*/
					if (SubWay.found==1)
					{
						/* if the sub way is smaller minimum then the new way 
							the minimum way is sub way*/
						if (SubWay.Population<NewWay.Population && NewWay.found==1)
						{
							NewWay=SubWay;
						}
					/* if the new way is not be , the sub way is minimum way*/
						if(NewWay.found==0)
						{
							
							NewWay=SubWay;
						}
					}

				}		
			}
	}
	return NewWay;
}

CountryType LargestCountry(CountryType *countries,char *sourceC,int Degree)
{
	int i,j;
	/*Take the values of source Country informations*/
	CountryType GivenCountry=FindCountry(countries,sourceC);
	/*This is found the largest Country*/
	CountryType Largest,SubCountry;
	/*firstly the largest is source country*/
	Largest=GivenCountry;
	
	/* firstly assign with the neithbor countries*/
	for (i = 0; i < 10; ++i)
	{
				if (strcmp(GivenCountry.Neighbors[i],"")!=0)
				{
					/* Take the values of the neighbors to assign with 
						the larger country*/
					SubCountry=FindCountry(countries,GivenCountry.Neighbors[i]);
						if (strcmp(GivenCountry.Neighbors[i],SubCountry.CName)==0)
						{
							/*if the neightbor country larger then 
								source country*/
							if (SubCountry.AreaKm>Largest.AreaKm)
							{
								Largest=SubCountry;
							}
						}
				}		
	}
	/* Search the neightbor of neigtbor countries with recursive
		so degree will be under the one  */
	if (Degree<1)
	{
		for (j = 0; j < 10; ++j)
		{
				if (strcmp(GivenCountry.Neighbors[j],"")!=0)
				{
					if (FindCountry2(countries,GivenCountry.Neighbors[j]))
						{
							/* The neightnor country will be source country 
								with recursive*/
							SubCountry=LargestCountry(countries,
									GivenCountry.Neighbors[j],Degree+1);
							if (SubCountry.AreaKm>Largest.AreaKm)
							{
								Largest=SubCountry;
							}
						}
				}
		}
	}
	return Largest;
}
/* This function run with Recursive, the function will search the neighbor
	then keep the Powerful country information , after return that*/
CountryType PowerfulMilitary(CountryType *countries,char *sourceC,int Degree)
{
	/*These are for loops*/
	int i,j;
	/* Take the source Country values */
	CountryType GivenCountry=FindCountry(countries,sourceC);
	/* these are keep the the Powerful coutry informations*/
	CountryType MaxMilitary,SubMilitary;
	/* Firstly the Powerful is source country*/
	MaxMilitary=GivenCountry;

	/* Search in Neighbors*/
	for (i = 0; i < 10; ++i)
	{
				if (strcmp(GivenCountry.Neighbors[i],"")!=0)
				{
						/* if The neighbors is in array */
						if (FindCountry2(countries,GivenCountry.Neighbors[i]))
						{
							/*Take the neighbors information*/
							SubMilitary=FindCountry(countries,
										GivenCountry.Neighbors[i]);
							if (SubMilitary.Soldiers>MaxMilitary.Soldiers)
							{
								MaxMilitary=SubMilitary;
							}
						}
				}		
	}
	/* The Powerful country will be neighbors of neighbor so there is a
		recursive to find the neighbors of neighbor country */
	if (Degree<1)
	{
		/*Firstly search in neighbors*/
		for (j = 0; j < 10; ++j)
		{
				if (strcmp(GivenCountry.Neighbors[j],"")!=0)
				{
						/* if the neighbor is in array, the neighbors of
							neighbor would be */
						if (FindCountry2(countries,GivenCountry.Neighbors[j]))
						{
							/* the neighbor will the source country
							then it will search in own neighbor*/
							SubMilitary=PowerfulMilitary(countries,
									GivenCountry.Neighbors[j],Degree+1);
							/* the sub country is powerful then source 
								country , it will swap*/
							if (SubMilitary.Soldiers>MaxMilitary.Soldiers)
							{
								MaxMilitary=SubMilitary;
							}
						}
					
				}
		}
	}
	/* Return the powerful counrty*/
	return MaxMilitary;
}
/* This function create the new country then take the information from user 
	assign them . But when the neighbors values are taken, the function 
	will contiune until user input -1 */
CountryType AddCountry()
{	
	CountryType newCountry;
	int count=0,input=0,i;
	char temp[26];
	/* Take informations*/
	scanf("%s",newCountry.CName);
	scanf("%d",&(newCountry.Population));
	scanf("%lf",&(newCountry.AreaKm));
	scanf("%d",&(newCountry.Soldiers));
	/* Initialize the neighbors memory*/
	for (i = 0; i < 10; ++i)
	{
		strcpy(newCountry.Neighbors[i],"");
	}
	/* if input is -1 , the loop not return else contiune the take value*/
	while(scanf("%d",&input)!=1 && input!=-1)
	{
		scanf("%s",temp);
		strcpy(newCountry.Neighbors[count],temp);
		count++;
	}
	/*Return the new Country*/
	return newCountry;
}