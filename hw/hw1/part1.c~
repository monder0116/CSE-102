/*############################################################################*/
/*HW01_Mehmet_Onder_131044076_part1.c                                         */
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


int main()
{
	/* All defines to get the values from user and assign to them*/ 
	float Mid1Weight,Mid2Weight,Mid3Weight;
	float Hw1Weight,Hw2Weight;
	float FinalWeight;
	float Mid1Grade,Mid2Grade,Mid3Grade;
	float Hw1Grade,Hw2Grade;
	float FinalGrade;
	/*This defines to calculate the all notes */
	float Calculate;	
	/* Ask to user and take the values to assign them to variables */
	printf("Please enter the 1. midterm weight:");
	scanf("%f",&Mid1Weight);
	printf("Please enter the 2. midterm weight:");
	scanf("%f",&Mid2Weight);
	printf("Please enter the 3. midterm weight:");
	scanf("%f",&Mid3Weight);
	printf("Please enter the 1. homework weight:");
	scanf("%f",&Hw1Weight);
	printf("Please enter the 2. homework weight:");
	scanf("%f",&Hw2Weight);
	printf("Please enter the final exam weight:");
	scanf("%f",&FinalWeight);
	printf("Please enter the 1. midterm grade:");
	scanf("%f",&Mid1Grade);
	printf("Please enter the 2. midterm grade:");
	scanf("%f",&Mid2Grade);
	printf("Please enter the 3. midterm grade:");
	scanf("%f",&Mid3Grade);
	printf("Please enter the 1. homework grade:");
	scanf("%f",&Hw1Grade);
	printf("Please enter the 2. homework grade:");
	scanf("%f",&Hw2Grade);
	printf("Please enter the final exam grade:");
	scanf("%f",&FinalGrade);

	
	/*Assign to values which calulate with weight and grade*/
	Calculate = (Mid1Grade*Mid1Weight/100) + 
		(Mid2Grade*Mid2Weight/100) + 
		(Mid3Grade*Mid3Weight/100) + 
		(Hw1Grade*Hw1Weight/100) + 
		(Hw2Grade*Hw2Weight/100) + 
		(FinalGrade*FinalWeight/100);
	/*it will show the result only 4 digit */
	printf("Your final grade is: %f ",Calculate);

	return 0;	
}
