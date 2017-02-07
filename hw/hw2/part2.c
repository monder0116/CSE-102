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
#include <stdio.h>
/* This defination is for the pi number take it only 3,14 */
#define PI 3,14


/* This is header functions to calculute area and perimeter for -
	Rectangle,Circle and Square 											  */
int areaOfRectangle(int x,int y);
int perimeterOfRectangle(int x,int y);

double areaOfCircle(int radius);
double perimeterOfCircle(int radius);

int areaOfSquare(int x);
int perimeterOfSquare(int x);


int main()  
{
	/* Define the variables to take the values which is width,height or 
		radius from the user 												 */
	/* R means rectangle*/
	int ValueofRWidth,ValueofRHeight,ValueofRArea,ValueofRPerimeter;
	int ValueofSWidth,ValueofSArea,ValueofSPerimeter; /* S means Square */
	int ValueofCRadius,ValueofCArea,ValueofCPerimeter; /*C means circle */

	/* Take the values and assign them from the user */
	printf("Please enter the width of rectangle:");
	scanf("%d",&ValueofRWidth);
	printf("Please enter the height of rectangle:");
	scanf("%d",&ValueofRHeight);
	/* Calculute the area and perimeter of Rectangle then assign to variable */
	ValueofRArea = areaofRectangle ( ValueofRWidth , ValueofRHeight );
	ValueofRPerimeter = perimeterOfRectangle( ValueofRWidth , ValueofRHeight );
	printf("The area of the rectangle is: %d \n", ValueofRArea );
	printf("The perimeter of the rectangle is: %d \n", ValueofRPerimeter );
	

	printf("Please enter the width of the square:");
	scanf("%d",&ValueofSWidth);
	ValueofSArea = areaofSquare(ValueofSWidth);
	ValueofSPerimeter = perimeterOfSquare(ValueofSWidth);
	printf("The area of the Square is: %d \n",ValueofSArea);
	printf("The perimeter of the Square is: %d \n",ValueofSPerimeter);

	printf("Please enter the radius of the Circle:");
	scanf("%d",&ValueofCRadius);
	ValueofCArea = areaofCircle(ValueofCRadius);
	ValueofCPerimeter = perimeterOfCircle(ValueofCRadius);
	printf("The area of the circle is: %d \n",ValueofCArea);
	printf("The perimeter of the Circle is: %d \n",ValueofCPerimeter);


	return 0;

}
/* calculte area and perimeter function to Square  */
int areaOfSquare(int x){
	return (x*x);	
}
int perimeterOfSquare(int x)
{

	return (4*x);
}
/* calculte area and perimeter function to Circle  */
double areaOfCircle(int radius)
{
	return (PI*radius*radius);
}
double perimeterOfCircle(int radius)
{
	return (2*PI*radius);
}
/* calculte area and perimeter function to Rectangle  */
int areaOfRectangle(int x,int y){
	return x*y;
}
int perimeterOfRectangle(int x,int y)
{
	return (2*x+2*y);
}
