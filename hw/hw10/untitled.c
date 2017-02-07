void printRegister(RegisterLessonType reg);
void printSchedule(ScheduleType sche);
void printTeacher(TeacherType teac);
void printStudent(StudentType stu);
void printLecture(LessonType lesson);
for ( i = 0; i < 5; ++i)
		{
			if (i==0)
			{
				printf("------------Students\n");
				for ( j = 0; j < count[i]; ++j)
				{
					printf("%d)",j );
					printStudent(Students[j]);
				}
			}
			else if (i==1)
			{
				printf("-----------teachers\n");
				for ( j = 0; j <  count[i]; ++j)
				{
						printf("%d)",j );
					printTeacher(Teachers[j]);
				}
			}
			else if (i==2)
			{
				printf("-----------lessons\n");
				for ( j = 0; j <  count[i]; ++j)
				{
						printf("%d)",j );
					printLecture(Lessons[j]);
				}
			}
			else if (i==3)
			{
				printf("-----------Schedules\n");
				for ( j = 0; j <  count[i]; ++j)
				{
						printf("%d)",j );
					printSchedule(Schedules[j]);
				}
			}
			else if(i==4){
				printf("----------Registers\n");
				printf("len%d\n", count[i]);
				for ( j = 0; j <  count[i]; ++j)
				{
						printf("%d)",j );
					printRegister(Registers[j]);
				}
			}

	}
	void printTeacher(TeacherType teac)
{
	printf("Degree=%s\n",teac.degree );
	printf("id=%d\n",teac.T_id );
	printf("Name=%s\n",teac.T_name );
	printf("surname=%s\n",teac.T_surname);
}
void printStudent(StudentType stu)
{
	printf("id=%d\n",stu.S_id );
	printf("name=%s\n",stu.S_name);
	printf("surname=%s\n",stu.S_surname );
}
void printLecture(LessonType lesson)
{
	printf("code %d\n",lesson.L_code );
	printf("name=%s\n",lesson.L_name );
	printf("Teacher=%d\n",lesson.T_id );

}
void printSchedule(ScheduleType sche)
{
	printf("class=%s\n",sche.Room_name );
	printf("day=%s\n",sche.Day );
	printf("start=%d\n",sche.Start_day );
	printf("time=%d\n", sche.Duration_lesson);
	printf("lesson code=%d\n",sche.L_code );

}
void printRegister(RegisterLessonType reg)
{
	printf("sid=%d\n", reg.S_id);
	printf("lid=%d\n", reg.L_code);
}
