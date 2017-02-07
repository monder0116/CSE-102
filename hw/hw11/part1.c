/*----------------------------------------------------------------------------*/
/*HW11_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on May 9, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* it is a binary file consisting of exactly 1000 records					  */
/*	of unknown C structure. Also, primitive data types used in structure can  */
/*	only be char (1 Byte), int(4 Bytes), long long int (8 Byte), 			  */
/*	float(4 Bytes), double (8 Bytes) and at	the end of the each record 		  */
/*	there is a double variable which keeps average of all other data fields   */
/*	in that record. The maximum data fields in the structure can be 11    	  */
/*	(including average field). Your duty is to decode 						  */
/*	the entire data written in the file. 									  */
/*																			  */
/*																			  */
/*	-hwDecode func. take file name and array to will find the struct type.    */
/*	the function calculate the all of Probability types and try it on file    */ 
/*	structer if the averages equal to each other the real types would be found*/
/*	then write them to array with represented integers which is;			  */
/*		char --> 1															  */
/*		int--> 2															  */
/*		long long int--> 3													  */
/*		float-->4															  */
/*		double-->5															  */
/*																			  */
/*	-findSameOrder func. will searh in array ,if the given list is in list 	  */
/*	return 1 else return 0													  */
/*																			  */
/*																			  */
/*																			  */
/*Inputs:                                                                     */
/*----------																  */
/* a binary  file									    				 	  */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */
/* Represented integer array												  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*the total structer count*/
#define READCOUNT 1000
/*Probability sturcters use 5^10 memory but it is huge and useless
	 this is control it*/
#define USEDMEMORY 10
/*this struct for store the number of type in Probability*/
typedef struct 
{
	 int i; /*int count*/
 	 int d; /*double count*/
	 int f; /*float count*/
	 int l; /*long count*/
	 int c; /*char count*/
}TypeCountType;
typedef struct 
{
	/* The Probability types are represented with char to use easyly
	which i is int,
	d is double,
	f is float,
	l is long long int,
	c is char*/
	char TypeList[12];
}ProbabilityType;
int findSameOrder(ProbabilityType *liste,int len,char *string);
int hwDecode(const char filename[], int arr_out[] );
int main()
{
	int arr[10];
	int i;
	hwDecode("data.bin",arr);
	for (i = 0; i < 11; ++i)
	{
		printf("%d\n",arr[i] );
	}
	/* add the new list*/
	return 0;
}
int hwDecode(const char filename[], int arr_out[] )
{
	/*These are for loops*/
	int i,l,c,f,d,k,j,t; 
	/*These declares are for read the bin file*/
	FILE *data;
	int TotalByte=0;
	int StruckByte;
	char getByte;
	/*this is store The number of Probability types  */
	TypeCountType *TypeCountList;
	int LenghtCList=0;
	/*this list to find all of Probability types*/
	ProbabilityType *AllProbList=
		(ProbabilityType *)calloc(pow(5,USEDMEMORY),sizeof(ProbabilityType));
	int PLength=0;
	int TypeLen,TypeCount=0;
	/* This is used when create the new Probability Type*/
	char tempList[12];
	/* this flag for finding Probability,if all of type add,the flag will be 0*/
	int flag;
	/*This is for trying the type to appropriate the file structer*/
	long long int tempLong=0;
	double tempDouble=0;
	int tempint=0;
	unsigned char tempChar=0;
	float tempFloat=0;
	double avg;
	double Total=0;
	int Ascichar;
	/*This is for finding the real type list, if the selected type equal to 
		file structer type ,flag will be 1,and copy the types to reallist */
	int flag2;
	char RealList[114];	
	data=fopen(filename,"rb");
	if (data==NULL)
	{
		return -1;
	}
	/*initialize the given array*/
	for ( i = 0; i < 11; ++i)
	{
		arr_out[i]=-1;
	}
	/*This is count the the total byte of file*/
	while(fread(&getByte,sizeof( char),1,data))
	{
		TotalByte++;
	}
	fclose(data);
	StruckByte=TotalByte/READCOUNT -8;
	/* Borrow the space from heap to store the number of types*/
	TypeCountList=(TypeCountType *)calloc(pow(5,USEDMEMORY),sizeof(TypeCountType));
	/* initialize the memory which is borrowed*/
	for ( i = 0; i<pow(5,USEDMEMORY); ++i)
	{
		TypeCountList[i].i=0;
		TypeCountList[i].d=0;
		TypeCountList[i].l=0;
		TypeCountList[i].c=0;
		TypeCountList[i].f=0;
	}
	/*when the find the number of Probability type ,it is used the equation
	 	which is 4*int + 8*double + 4*float + c + 8*longint = StruckByte and
	 	i+d+f+c+l <=10 */
	for ( i = 0; i <= 10; ++i)/*int*/
	{
		for (d= 0; d <=10; ++d)/*double*/
		{
			for (f = 0; f <= 10; ++f)/*float*/
			{
				for ( c = 0; c <= 10; ++c)/*char*/
				{
					for ( l = 0; l <= 10; ++l)/* long*/
					{
						if ((i*4+ d*8 + f*4 + c + l*8 )==StruckByte && i+d+f+c+l<=10)
						{
							/* if the numbers are appropriate to sturct 
								add the list*/

							TypeCountList[LenghtCList].i=i;
							TypeCountList[LenghtCList].d=d;
							TypeCountList[LenghtCList].f=f;
							TypeCountList[LenghtCList].c=c;
							TypeCountList[LenghtCList].l=l;
							LenghtCList++;
						}
					}
				}
				
			}
		}
	}
	/* When all number of Probability type is found ,first of all adding the
		type to AllProbList which type include several times */
	for ( i = 0; i < LenghtCList; ++i)
	{
		TypeCount=0;
		for ( d = 0; d < TypeCountList[i].d; ++d)
		{
			AllProbList[PLength].TypeList[TypeCount]='d';
			TypeCount++;
		}
		for ( f = 0; f < TypeCountList[i].f; ++f)
		{
			AllProbList[PLength].TypeList[TypeCount]='f';
			TypeCount++;
		}
		for ( t = 0; t < TypeCountList[i].i; ++t)
		{
			AllProbList[PLength].TypeList[TypeCount]='i';
			TypeCount++;
		}
		for ( c = 0; c < TypeCountList[i].c; ++c)
		{
			AllProbList[PLength].TypeList[TypeCount]='c';
			TypeCount++;
		}
		for ( l = 0; l < TypeCountList[i].l; ++l)
		{
			AllProbList[PLength].TypeList[TypeCount]='l';
			TypeCount++;
		}
		AllProbList[PLength].TypeList[TypeCount]='\0';
		PLength++;	
	}
	free(TypeCountList);
	/* There are finding all of Probability types with swap the chars , 
	if all the type is not be in list ,it will added. if all of Probability
	are found ,the flag will be 0 and exit the loop*/
	do{
		flag=0;
		for ( i = 0; i <PLength ; ++i)
		{
			for ( j = 0; j < strlen(AllProbList[i].TypeList)	; ++j)
			{
				for ( k = 0; k < strlen(AllProbList[i].TypeList); ++k)
				{
					strcpy(tempList,AllProbList[i].TypeList);
					/*swaping the chars to creat new Probability*/
					tempChar=tempList[j];
					tempList[j]=tempList[k];
					tempList[k]=tempChar;
					/* if search the types in list*/
					if (findSameOrder(AllProbList,PLength,tempList)==0)
					{
						flag=1;
						strcpy(AllProbList[PLength].TypeList,tempList);
						PLength++;
					}
				}
			}
		}
	}while(flag!=0);

	/*There are trying all of Probability types to file structer, 
	if the file structer average equal to Probability type average , 
	the flag2 will be 1 and the real type would be found */
	data=fopen("data.bin","rb");
	flag2=0;
	RealList[0]='\0';
	/*Searching the Probability list*/
	for (i = 0; i < PLength; ++i)
	{

		rewind(data);
		flag2=0;
		/*Takeing the structer from the file*/
		for ( k = 0; k < READCOUNT; ++k)
		{
			Total=0;
			/* Searching the select types element*/
			for (j = 0; j < strlen(AllProbList[i].TypeList); ++j)
			{
				tempLong=0;
				tempDouble=0;
				tempint=0;
				tempChar=0;
				tempFloat=0;
				Ascichar=0;
				/* if Probability type is integer, read int in file */
				if (AllProbList[i].TypeList[j]=='i')
				{
					
					fread(&tempint,sizeof(int),1,data);
					
				}
				/* if Probability type is double, read double in file */
				else if (AllProbList[i].TypeList[j]=='d')
				{
				
					fread(&tempDouble,sizeof(double),1,data);
					
				}
				/* if Probability type is long long int, read 
					long long int in file */
				else if (AllProbList[i].TypeList[j]=='l')
				{
					fread(&tempLong,sizeof(long long int),1,data);
					
				}
				/* if Probability type is char, read char in file */
				else if (AllProbList[i].TypeList[j]=='c')
				{
				
					fread(&tempChar,sizeof(unsigned char),1,data);
					
				}
				/* if Probability type is float, read float in file */
				else if (AllProbList[i].TypeList[j]=='f')
				{
					fread(&tempFloat,sizeof(float),1,data);
					
				}
				/* Case the char to integer*/
				Ascichar=tempChar;
				/* Add the type to Total*/
				Total+=(tempint+tempLong+tempDouble+tempFloat+Ascichar);

			}
			/* the end of struct,read the double to average*/
			fread(&avg,sizeof(double),1,data);
			/* Calculate the Probability types lenght*/
			TypeLen=strlen(AllProbList[i].TypeList);
			/* Calculate the Probability types average*/
			Total=(double)(Total/TypeLen);
			if (avg==Total)
			{
				flag2=1;
			}
			else
			{
				flag2=0;
			}
		}
		if (flag2==1)
		{
			/* copy the real types*/
			strcpy(RealList,AllProbList[i].TypeList);
			break;
		}

	}
	fclose(data);
	/* Adding the real types with which is represented to given array*/
	for ( k = 0; k < strlen(RealList); ++k)
	{
		if (RealList[k]=='c')
		{
			arr_out[k]=1;
		}
		else if (RealList[k]=='i')
		{
			arr_out[k]=2;
		}
		else if (RealList[k]=='l')
		{
			arr_out[k]=3;
		}
		else if (RealList[k]=='f')
		{
			arr_out[k]=4;
		}
		else if (RealList[k]=='d')
		{
			arr_out[k]=5;
		}
		else
		{
			arr_out[k]=-1;
		}
	}
	for ( j = strlen(RealList); j < 11; ++j)
	{
		arr_out[j]=-1;
	}
	free(AllProbList);

	return 0;
}
/*This function search in list ,if the string is be,return 1 else return 0*/
int findSameOrder(ProbabilityType *liste,int len,char *string)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		if (strcmp(liste[i].TypeList,string)==0)
		{
			return 1;
		}
	}
	return 0;
}