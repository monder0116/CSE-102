/*----------------------------------------------------------------------------*/
/*HW10_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on May 2, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* This program get the information to same struck type array 				  */
/*	 which are students,lectures,professors,Lescture schedules 				  */
/*	 and Lesson Register of student from the input.data					      */
/*	 Then write the summary information to outpu.txt.						  */
/*																			  */
/*	The input.dat file format;												  */
/*																			  */
/*	-There are 5 different data types in the file. 							  */
/*	-At the beginning of each entry type is a number which indicates 		  */
/*	  how many entries will be listed.										  */
/*	-Students (with id,name and surname),									  */
/*	-Lecturers (with degree, id,name and surname),							  */
/*	-Lectures(with code, name and the id of the lecturer),					  */
/*	-Schedule (with classroom name, day, start time of the lecture,			  */
/*	duration of the lecture and the code of the lecture) and 				  */
/*	-courses taken by the students (with	student id and lecture code). 	  */
/*																			  */
/*	The output.txt file format;												  */
/*																			  */
/*	 -The first summary is lecture, lecturer and student relation. 			  */
/*	Namely, for each lecture its name,the name and surname of the lecturer 	  */
/*	 and the number of students that takes the lecture will be 				  */
/*	listed.																	  */
/*	- Secondly summary is the student-lecture relation, 					  */
/*	for each student, his student id,name, surname and 						  */
/*	how many lectures he takes. 											  */
/*	- The last summary is about student schedules, 							  */
/*	his student id, name, surname, and the days on which he has class.		  */
/*																			  */
/*																			  */
/*Inputs:                                                                     */
/*----------																  */
/* the input.dat file									    				  */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */
/* the output.txt file														  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define EndOfArrays 20
#define StringLen 30

/* Structer types */
typedef struct 
{
	int S_id;
	char S_name[StringLen];
	char S_surname[StringLen];
}StudentType;
typedef struct 
{
	char degree[StringLen];
	int T_id;
	char T_name[StringLen];
	char T_surname[StringLen];
}TeacherType;
typedef struct 
{
	int L_code;
	char L_name[StringLen];
	int T_id;
}LessonType;
typedef struct 
{
	char Room_name[StringLen];
	char Day[StringLen];
	int Start_day;
	int Duration_lesson;
	int L_code;
}ScheduleType;
typedef struct 
{
	int S_id;
	int L_code;

}RegisterLessonType;
/* This function will calculate the total count which lesson is taken
	by the student*/
int LessonCount(RegisterLessonType *array,int Lessoncode,int rcount);
/* This function will calculate the total count which student take lessons */
int TotalLessonCount(RegisterLessonType *array,int Lessoncode,int rcount);
/* This function return the pointer of Lesson time information which lesson 
	code is Lcode in Schedules array. Pointer for less using the memory*/
ScheduleType *LessonTime(ScheduleType *array,int Lcode,int SCHcount);
/* This function return the pointer of Teacher Information which
	Teacher id is t_id in Teachers array. Pointer for less using the memory*/
TeacherType *FindTeacher(TeacherType *array,int t_id,int tcount);
int main()
{
	/* These are the array of structures*/
	StudentType Students[EndOfArrays];
	TeacherType Teachers[EndOfArrays];
	LessonType Lessons[EndOfArrays];
	ScheduleType Schedules[EndOfArrays];
	RegisterLessonType Registers[EndOfArrays];
	/* These are count of information in file*/
	int scount,tcount,lcount,SCHcount,rcount;
	/* this is keep the summary day */
	char DayOfLessons[7][StringLen];
	/* EndofDay is summary day length */
	int flag=0,EndOfDay=0;
	/* Keep total count which is taken by student*/
	int TakenLessonCount;
	/*this is pointer of teachertype */
	TeacherType *Teacher;
	/* These are for Loops*/
	int i,j,k;
	/* The input and output file*/
	FILE *inputFile;
	FILE *outputfile;


								/* Read the binary file*/
	inputFile=fopen("input.dat","rb");

	if (inputFile==NULL)
	{
		printf("There is no input.dat\n");
		return 0;
	}
								
	/* Read the count of student from file*/
		fread(&scount,sizeof(int),1,inputFile);
	/* Get n student information from file to Students array which n is scount*/
	fread(Students,sizeof(StudentType),scount,inputFile);
	/* Read the count of Teacher from file*/
	fread(&tcount,sizeof(int),1,inputFile);
	/* Get n Teacher information from file to Teachers Array which n is tcount*/
	fread(Teachers,sizeof(TeacherType),tcount,inputFile);
	/* Read the count of Lesson from file*/
	fread(&lcount,sizeof(int),1,inputFile);
	/* Get n Lesson information from file to Lessons Array which n is tcount*/
	fread(Lessons,sizeof(LessonType),lcount,inputFile);
	/* Read the count of Schedule from file*/
	fread(&SCHcount,sizeof(int),1,inputFile);
	/* Get n Schedule information from file to Schedules Array which n is tcount*/
	fread(Schedules,sizeof(ScheduleType),SCHcount,inputFile);
	/* Read the count of lesson Register from file*/
	fread(&rcount,sizeof(int),1,inputFile);
	/* Get n Register information from file to Registers Array which n is tcount*/
	fread(Registers,sizeof(RegisterLessonType),rcount,inputFile);
	/* The reading is ok*/
	fclose(inputFile);


						
							/*Write to output.txt*/
	
	outputfile=fopen("output.txt","w");

	/* Print to file to The Summary of lecture and lecturer */
	
	fprintf(outputfile, "Lecture-Lecturern\n");
	/* Search in Lectures */
	for (i = 0; i < lcount; ++i)
	{
		/*The pointer for using less memory 
			this is pointer of teachertype which teacher id is equal T_id*/
		Teacher=FindTeacher(Teachers,Lessons[i].T_id,tcount);
		/* Take total count which is taken by student*/
		TakenLessonCount=LessonCount(Registers,Lessons[i].L_code,rcount);
		/* Print the information to file*/
		fprintf(outputfile, "%s %s %s %d\n",Lessons[i].L_name 
			,Teacher->T_name
			,Teacher->T_surname
			,TakenLessonCount);
	}
	


	/* Print to file to The Summary of student-lecture relation*/
	fprintf(outputfile, "\nStudent-Lecture\n");
	/*Search in student Array */
	for (i = 0; i < scount; ++i)
	{
		/* Take the total count which student take lesson*/
		int TotalLesson=TotalLessonCount(Registers,Students[i].S_id,rcount);
		/* Print the student information to file*/
		fprintf(outputfile, "%d %s %s %d\n",Students[i].S_id 
			,Students[i].S_name
			,Students[i].S_surname
			,TotalLesson);
	}


	/* Print to file to the summary is about student schedules */
	fprintf(outputfile, "\nStudent-Day\n" );
	/* Firstly search the each student to find which lesson taken by student*/
	for (i = 0; i < scount; ++i)
	{
		/* Initialize the day arrays */
		for ( k = 0; k < 7; ++k)
		{
			strcpy(DayOfLessons[k],"");
		}
		/*Initialize the declares*/
		flag=0;
		EndOfDay=0;
		/* Firstly print the information of the student */
		fprintf(outputfile, "%d %s %s ",Students[i].S_id
			,Students[i].S_name
			,Students[i].S_surname );
		/* search the Register array to find which lesson is taken by student*/
		for (j = 0; j < rcount; ++j)
		{
			/* select the cols*/
			if (Students[i].S_id==Registers[j].S_id)
			{
				/* This is pointer to Lesson time in Schedules Array*/
				ScheduleType *LessonInformation;
				/* Take the information of Student lesson time*/
				LessonInformation=LessonTime(Schedules,Registers[j].L_code,SCHcount);
				flag=0;
				/* Search the Day array to equal the same day*/
				for (k = 0; k < EndOfDay; ++k)
				{
					if (strcmp(DayOfLessons[k],LessonInformation->Day)==0)
					{
						/* there is a same day so it is not nessesary to 
							write same day to file*/
						flag=1;
					}
				}
				/* if the flag zero, there is same day , it will be first
					add the array*/
				if (flag==0)
				{
					strcpy(DayOfLessons[EndOfDay],LessonInformation->Day);
					EndOfDay++;
				}
			}
		}
		/* there are the day array which student have a lesson in day
			then write the days to file */
		for (k = 0; k < EndOfDay; ++k)
		{
			if (k==0)
			{
				fprintf(outputfile,"%s", DayOfLessons[k]);
			}
			else
			{
				fprintf(outputfile,",%s", DayOfLessons[k]);
			}
		}
		fprintf(outputfile,"\n");
	}
	fclose(outputfile);
	return 0;
}
/* This is pointer of Lesson time information , the pointer for using less 
	memory*/
ScheduleType *LessonTime(ScheduleType *array,int Lcode,int SCHcount)
{
	int i;
	for (i = 0; i < SCHcount; ++i)
	{
		if (Lcode==array[i].L_code)
		{
			return &array[i];
		}
	}
	return NULL;
}
/* This function return count which the student take lesson */
int TotalLessonCount(RegisterLessonType *array,int sid,int rcount)
{
	int count=0,i;
	for ( i = 0; i < rcount; ++i)
	{
		if (sid==array[i].S_id)
		{
			count++;
		}
	}
	return count;
}
/* This function return count which the lesson is taken by student*/
int LessonCount(RegisterLessonType *array,int Lessoncode,int rcount)
{
	int count=0,i;
	for ( i = 0; i < rcount; ++i)
	{
		if (Lessoncode==array[i].L_code)
		{
			count++;	
		}
	}
	return count;
}
/* This function return a pointer which teacher id is select in Teacher array*/
TeacherType *FindTeacher(TeacherType *array,int t_id,int tcount)
{
	int i;

	for ( i = 0; i < tcount; ++i)
	{
		if (array[i].T_id==t_id)
		{
			return &array[i];
		}
	}
	printf("Wrong Teacher\n");
	return NULL;
}
