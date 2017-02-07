/*############################################################################*/
/*HW03_Mehmet_Onder_131044076_part1.c                                         */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on March 3, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* This program asks users for an integer and checks if the number is an odd, */
/*	a factorial or a narcissistic number, depending on the user choice.  	  */
/*	The program will keep running											  */
/* 	until the user wants to exit by entering y   			      			  */		
/*Inputs:                                                                     */
/*----------																  */
/*	The program take an integer to check them								  */
/*                            												  */
/*Outputs:  																  */
/*---------                                                                   */ 
/* -The result is if The number agreeable to selection return it is else not. */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*TheProgram turn into inside and take integer and selection value
	  until quit input is 'y' */
void TheProgram();
void welcome();

/* if the number is an odd number, print to console it is odd else not */
void isOdd(int number);

/* if the number is an factorial number, print to console it is else not */
void isFactory(int number);

/* This func. send the number to LengthCalculate , take the length*/
void isNarcis(int number);

/* This Function help to isNarcis func. to find the length of number*/
int LengthCalculate(int number);

int main()
{
	TheProgram();
	return 0;
}
/* TheProgram take the integer from the user to check this to odd,
	Narcissistic or Factorial number after if user want to quit ,enter the 'n'
	then quit the program else Continue */
void welcome()
{
	printf("*****************************************************\n");
	printf("*                    WELCOME!                       *\n");
	printf("*  This program checks whether the given number     *\n");
	printf("* is an odd, a Factorial or a Narcissistic number   *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	
}
void TheProgram()
{
	int Number,select;
	char Continue;
	Continue='y';
	welcome();	
	while(Continue=='y' || Continue=='Y')
	{
		printf("Please enter a positive integer: ");
		scanf("%d",&Number);
		if(Number>0)
		{
			printf("Which property would you like to check?\n");
			printf("1)Odd number\n");
			printf("2)Factorial number\n");
			printf("3)Narcissistic number\n");
			printf("Please enter(1/2/3):");
			scanf("%d",&select);
			switch(select){
				case 1: isOdd(Number);break;
				case 2: isFactory(Number);break;
				case 3: isNarcis(Number);break;
				default: printf("Please select only defined number!\n");
			}
		}	
		else{
			printf("The entered number is not positive\n");
		}		
		printf("Do you want to continue (y/n)?");
		scanf(" %c", &Continue);
	}
	printf("Good Bye");

	
}

/* LengthCalculat() calculate the total length to help to isNarcis function.
	if powers of 10 smaller then the number until to limit of power .
	the length is  power+1 */
int LengthCalculate(int number)
{ 
	int Length,BiggerPower;
	BiggerPower=0;
	Length=0;

	while(BiggerPower<=number)
	{
		Length+=1;
		BiggerPower=pow(10,Length);
	}
	return Length;
}

/* isNarcis firstly calculate the total length to use the function which 
	name is LengthCalculate after sum the power which return the counter1
	in loop for	the all digit then 
	control it to equal to the number after print the state.
*/
void isNarcis(int number)
{
	int Len,Counter,SumofPower,Digit;
	/*Power1,Power2 only help to calculute the digit and 
		Power3 is the power of the digit */ 
	int Power1,Power2,Power3;
	Len=LengthCalculate(number);	
	SumofPower=0;
	for(Counter=1;Counter<=Len;Counter++)
	{
		Power1=pow(10,Counter);
		Power2=pow(10,Counter-1);
		Digit=(number % Power1)/Power2;
		Power3=pow(Digit,Len);
		SumofPower +=Power3;
	}
	if(SumofPower==number)
	{
		printf("%d is an Narcissistic number\n",number);
	}
	else
	{
		printf("%d is not an Narcissistic number\n",number);
	}
}

/* This function control the number to if it is an odd or not , then
 print to concole the result */
void isOdd(int number)
{
	if(number%2!=0)
	{
		printf("%d is an odd number !\n",number);
	}
	else
	{
		printf("%d is not an odd number !\n",number);
	}
}

/* This function control the number to a Factorial number or not, the Multi 
	defination multiply the counter which return in in loop 
	if number % counter equal to 0 ,go on until not equal to 0 then 
    end the loop control the multi defination equal the number or not 
	and print the state  */ 
void isFactory(int number)
{
	int multi,counter;
	multi=1;
	counter=1;
	while((multi<number) && (number % counter ==0)){
		multi =multi*counter;
		counter +=1;
	}
	if(multi==number){
		printf("%d is a Factorial number !\n",number);
	}
	else
	{
		printf("%d is not a Factorial number !\n",number);
	}
}
