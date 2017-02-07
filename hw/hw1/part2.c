/*############################################################################*/
/*HW01_Mehmet_Onder_131044076_part1.c                                         */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on February 20, 2016                                */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*This program calculate how many days the user has lived on planet   		  */
/*Inputs:                                                                     */
/* This program take the current year,month and day and then his birthdate-	  */
/* from the user                                   							  */
/*Outputs:                                                                    */ 
/* the result program will show that the total days which user has lived and  */
/* the day,year and month if you were lived in another planet                 */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
/*This defination to unspace at the RAM */
#define WorldYear 365
#define WorldMonth 30
#define WorldHour 24


int main()
{
	/* This descibes for take values from user to Current dates*/
	int CurrentYear,CurrentMonth,CurrentDay; 
	/* This descibes for take values and assign from user to Birth dates*/
	int BirthYear,BirthMonth,BirthDay;
	/* it will calculate the day from zero to dates then subtract them*/
	int TotalDay;
	/* This Describes to take the information from the user to value of 
		another planet date  */
	int AboutHours,AboutDays,AboutMonths;
	/* This Describe for calculate the new values to another planet */
	/* The "AP" means Another Planet */
	int APDay,APMonth,APYear; 
	int NewTotalDay;
	/* it will convert the world days to hours to declare the new dates values*/
	int TotalHours; 

	/* Fİrstly it will calculate for the world to how many lived */		
	/*Taken the current dates from the user */
	printf("Please enter the current date.\n");
	printf("Year:");
	scanf("%d",&CurrentYear);
	printf("Month:");
	scanf("%d",&CurrentMonth);
	printf("Day:");
	scanf("%d",&CurrentDay);	
	/*Taken the birth dates from the user */
	printf("Please enter your birthday.\n");
	printf("Year:");
	scanf("%d",&BirthYear);
	printf("Month:");
	scanf("%d",&BirthMonth);
	printf("Day:");
	scanf("%d",&BirthDay);
	/* Calculate the total day to how many live in days*/
	TotalDay=(CurrentYear * WorldYear + CurrentMonth * WorldMonth + CurrentDay)- 
		(BirthYear * WorldYear + BirthMonth * WorldMonth + BirthDay);
	printf("You have lived %d days.\n",TotalDay);

	/* Secondly it will calculate for the another planet to how many lived */	
	printf("Please enter about the time of another planet\n");
	printf("How many hours is a day?");
	scanf("%d",&AboutHours);
	printf("How many days is a month?");
	scanf("%d",&AboutDays);
	printf("How many months is a year?");
	scanf("%d",&AboutMonths);
	/*Calculate the new values to another planet */
	TotalHours=TotalDay*WorldHour;
	NewTotalDay=(TotalHours/AboutHours);
	APDay=NewTotalDay%AboutDays;
	APMonth=(NewTotalDay/AboutDays)%AboutMonths;
	APYear=(NewTotalDay/AboutDays/AboutMonths);
	printf("If you lived in a planet where a day is %d hours, "
	"a month is %d days and a year is %d months: you were %d years, "
	"%d months and %d days old\n",AboutHours,AboutDays,AboutMonths,
				APYear,APMonth,APDay);
	return 0;	
}
