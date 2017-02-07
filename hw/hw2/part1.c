/*############################################################################*/
/*HW02_Mehmet_Onder_131044076_part1.c                                         */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on February 20, 2016                                */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*The Program calculate the overall grade of the students      			      */
/*Inputs:                                                                     */
/*The program take valeus of grades and weight which is	-					  */
/* 3 midterms, 2 homeworks and 1 final exam                                   */
/*Outputs:                                                                    */ 
/* -The result is the final grade which is calculated                         */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include "stdio.h"
void calculateLastGrade();
int main()
{
	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();

	return 0;
}
void calculateLastGrade()
{
	/* I define this variables for take the values which are weights or grades*/
 	/*  then assign to them 												  */
	int Mid1Weight,Mid1Grade;
	int HW1Weight,HW1Grade;
	int FinalWeight,FinalGrade;
	
	/* This is for calculate the final grade calculate with weight and grade  */
	/* values 																  */ 	
	float TotalCalculate;
	/*Take the values which are weight and grades and assign them to variables*/
	printf("Please enter the 1. midterm weight:");
	scanf("%d",&Mid1Weight);
	printf("Please enter the 1. homework weight:");
	scanf("%d",&HW1Weight);
	printf("Please enter the final exam weight:");
	scanf("%d",&FinalWeight);
	printf("Please enter the 1. midterm grade:");
	scanf("%d",&Mid1Grade);
	printf("Please enter the 1. homework grade:");
	scanf("%d",&HW1Grade);
	printf("Please enter the final exam grade:");
	scanf("%d",&FinalGrade);
	/* Calculate the final grade and assign to TotalCalculate */	
	TotalCalculate= ( Mid1Weight * Mid1Grade /100) +
				(HW1Weight * HW1Grade/100) +
				( FinalWeight * FinalGrade /100);
	/* Show the result */
	printf("Your final grade is: %f \n",TotalCalculate);
	
}

