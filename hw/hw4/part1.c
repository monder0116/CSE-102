#include <stdio.h>
#define PI 3.14
/*############################################################################*/
/*HW04_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on March 20, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* Taylor series to calculate sine and cosine with own functions			  */
/*  The user will enter an integer as degree and another integer that         */
/*	defines the first n elements of the series/								  */
/*										 									  */
/* 				      														  */		
/*Inputs:                                                                     */
/*----------																  */
/*	The function named getInputs will wait for user to enter 				  */
/*	the degree and n value. If ‘E’ is entered instead, 						  */
/*	the exit variable will be 1, otherwise 0.								  */
/*                            												  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* print sin and cos value, 									 			  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*		 					standart functions								  */


/*This is calculate to power number  of n base */ 
double Power(double number,double count);  						
/* This is calculate to Factory of the number*/
double Factory(double number); 
/* this is calculate to cos value of number*/
double cosine(int,int);
/* this is calculate to sin value of number*/
double sine(int degree,int n);
/* this is take input from user if input 'e' ,exit*/
void getInputs(int *degree,int *n,int *exit);
int main()
{
	int exit=0;
	int b,a;
	while(exit!=1)	
	{
		getInputs(&a,&b,&exit);
	}
	return 0;
}
/* this is take input from user if input 'e' or 'E',exit*/
void getInputs(int *degree,int *n,int *exit)
{
	char buffer;/*if input is not integer ,Take this char */
	int TakeNumber;/*the scanf function's state values*/
	TakeNumber=scanf("%d %d",degree,n);
		if(TakeNumber!=2)/*if inputs are not integer */
		{		
			scanf("%c",&buffer);/*take the char from the buffer*/
		}		
		if(buffer=='e' || buffer=='E') /*if input is e , */
		{
			*exit=1;
		}else{
		
			*exit=0;
		}
		if(TakeNumber==2){/*the condition mean the inputs are two integer
			 this are translation on trigonometry*/
				printf("sin(%d) %.4f\n",*degree,sine(*degree,*n));
				printf("cos(%d) %.4f\n",*degree,cosine(*degree,*n));
				*exit=0;
		}
}
/* this is calculate to cos value of number*/
double cosine(int degree,int n)
{

	int Sign;
	double XPower,RDegree,Divisor,Result,Sum; /* RDegree mean RadiansDegree*/
	int c1; /*This is for counter*/
	
	/*This is translation on trigonometry*/	
	degree=degree%360;
	 if ((degree>=90 && degree <=180))
		{
			return -sine((degree -90),n);
		}
		else if((degree>=180 && degree <=270))
		{
			return -cosine(degree-180,n);
		}
		else if((degree>=270 && degree <=360))
		{	
			return sine(degree-270,n);
		}
	Sum=0;
	for(c1=0;c1<n;c1++)
	{
		Sign=Power(-1,c1);
		RDegree=(PI*degree)/180;
		XPower=Power(RDegree,2*c1);
		Divisor=Factory(2*c1);
		Result=Sign*XPower/Divisor;
		Sum=Sum+Result;
	}
	return Sum;
}
/* this is calculate to sin value of number*/
double sine(int degree,int n)
{
	int Sign;
	double XPower,RDegree,Divisor,Result,Sum; /* RDegree mean RadiansDegree*/
	int c1; /*This is for counter*/
	

	/*This is translation on trigonometry*/	
	degree=degree%360;
	 if ((degree>=90 && degree <=180))
		{
			return cosine((degree -90),n);
		}
		else if((degree>=180 && degree <=270))
		{
			return -sine((degree -180) ,n);
		}
		else if((degree>=270 && degree <=360))
		{	
			return -cosine((degree-270),n);
		}	


	Sum=0;
	for(c1=0;c1<n;c1++)
	{
		Sign=Power(-1,c1);
		RDegree=(PI*degree)/180;
		XPower=Power(RDegree,2*c1+1);
		Divisor=Factory(2*c1+1);
		Result=Sign*XPower/Divisor;
		Sum=Sum+Result;
	}
	return Sum;
}
 /*This is calculate to power number  of n base */  
double Power(double number,double count)
{
	int c1; /*This is for counter*/
	double Result=1;
	for(c1=1;c1<=count;c1++)
	{
		Result *=number;
	}
	return Result;
	
}
/* This is calculate to Factory of the number*/
double Factory(double number)
{
	int c1;
	double Result=1;
	for(c1=1;c1<=number;c1++)
	{
		Result*=c1;
	}
	return Result;
}
