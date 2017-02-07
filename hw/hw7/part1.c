
/*----------------------------------------------------------------------------*/
/*HW06_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 9, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*  All functions run with recursive to palindrome finder .					  */
/*	A palindrome is a sequence of characters								  */
/*	which reads the same backward or forward. Program						  */
/*	match only letters. The ignore function ignore the punctuations, 		  */
/*	spaces,etc. And len function calculate the length of string to find last  */
/*	character.Then the HelperRecurvie function check the all char 			  */
/*	if all chars are equal to each other return 1 ,else	return 0     		  */
/*Inputs:                                                                     */
/*----------																  */
/* Function take a String												      */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */
/* if the given string is a palindrome , Return 1 else return 0 		 	  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
int isPalindrome(char *str);
int len(char *string);
int Ignore(char str);
int main()
{
	char *str="Ab,. ,cdD!ed~cb%a";
	printf("%d\n",len(str) );
	int a=isPalindrome(str);
	printf("%d\n", a);
	return 0;

}
/* Calculate the string length with recursive */
int len(char *string)
{
	if (string[0]=='\0')
	{
		return 0;
	}
	else
	{
		return 1+len(string+1);
	}
}

/* This Function help to HelperRecursive to the char is valid or invalid */
int Ignore(char str)
{
	if ((str>='a' && str<='z') || (str>='A' && str<='Z') )
	{
		return 0;
	}
	return 1;
}
/* This function run with recursive, it is check the char to Palindrome 
	or not if char is palindrome, skip to next, else return 0, */
int HelperRecursive(char *str,int first,int last)
{
	char FirstChar,LastChar;
	
	FirstChar=str[first];
	LastChar=str[last];
	if(FirstChar=='\0'){
		return 1;
	}

	
	/* if first of char is punctuations , it will be stepped to next char*/
	if (Ignore(FirstChar)){
		return HelperRecursive(str,++first,last);
	}
	/* if last of char is punctuations , it will be stepped to next char*/
	else if (Ignore(LastChar))
	{
	 	return	HelperRecursive(str,first,last-1);
	}
	/* Convert the first char to upper case for case insensitive */
	 if(FirstChar>='a' && FirstChar<='z')
	{
		FirstChar=FirstChar-32;

	}
	/* Convert the last char to upper case for case insensitive */
	 if(LastChar>='a' && LastChar<='z')
	{	
		LastChar=LastChar-32;
	}
	/* if the chars is equal to each other, both of them will be stepped 
		to next char*/
	if (FirstChar==LastChar)
	{
		return HelperRecursive(str,++first,last-1);
	}
	/*if the chars is not equal , return 0 */
	else
	{
		return 0;
	}


}
/* This Function send to helper function to is this string Palidrome or not*/
int isPalindrome(char *str)
{
	int length=len(str)-1;
	return HelperRecursive(str,0,length);
}