
/*----------------------------------------------------------------------------*/
/*HW07_part2_Mehmet_Onder_131044076_part2.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 10, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* This program simulates hitting an air hockey disc and checks whether		  */
/* the disc will be in the goal or not . But if angle bigger 175 ,taken at    */
/* 175 degree,or angle smaller 5,taken	5 degree. And when the ball come to   */
/* wall ,the reflection is not perfect reflection,There is a random diversion */
/* between -5 degrees and +5 degrees. Then if the wallheight small than 	  */
/* height	of ball way , it will calculate according to wall, if ball come	  */
/* from right wall the slope is negatife so it need calculate subtraction 	  */
/* the total x coordination or come from left only calculate the x coordinate */
/*										 									  */
/* 	-Goal is at the horizontal center of the top side with a length of gw	  */
/*Inputs:                                                                     */
/*----------																  */
/*Function parameters are table width (w), table height (h),				  */
/*	disc center distance from left side of the table (dc),					  */
/*	disc radius (r), 														  */
/*	and goal width (gw),												      */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */
/* Program will check whether the ball is in the goal or no				 	  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
/* this is take the contact angle then give a outgoing angle which is 
	a random diversion between -5 degrees and +5 degrees */
int reflection(int angle);

/* the ball return in inside while the ball reflect from the wall
 until the ball height bigger then wall height  */
int kickDisc(double wallWidth, double wallHeight, 
	double ballCenterX, double kickAngle, double ballRadius, double goalWidth);

/* this functions calculate the hit point according to right wall if
	top of ball hit the goal return 1 else 0 */
double HitToLeft(double wallWidth,double wallHeight,
	double ballCenterX,double kickAngle,double ballRadius,double goalWidth);

/* this functions calculate the hit point according to left wall if
	top of ball hit the goal return 1 else 0 */
double HitToRight(double wallWidth,double wallHeight,
	double ballCenterX,double kickAngle,double ballRadius,double goalWidth);
/* This is create random number which is depend on angle*/
int randNumber(int angle);
int main()
{
	int a=kickDisc(10, 26, 2, 70, 1, 2);	
	printf("%d \n",a );
	return 0;
}

/* this function calculate the hitting point according to right wall
	but there is slope is negatif if top of ball hit the goal return 1 else 0 */
double HitToLeft(double wallWidth,double wallHeight,double ballCenterX,
		double kickAngle,double ballRadius,double goalWidth)
{
		/* when ball come to wallheight ,Xlength is the length of x 
			and HitToPoint is x coordinate number*/
		double HitToPoint,XLength; 
		/* when ball is come to goal , the top hitting firstly, so it need
	  calculte according to top of ball therefore it must decrease the height*/ 
		if (wallHeight>ballRadius)
		{
				/* the height is smaller then ballradius it will be negative ,
			this condition protect it */
			wallHeight-=ballRadius;
		}
		XLength=wallHeight/tan(PI*kickAngle/180);
		/*ball come from right wall, The slope is negatif therefore 
			it need calculate subtraction the total x coordination */
		HitToPoint=wallWidth-((ballCenterX)+XLength);

		/* the x coordination is bigger then goal left corner and smaller goal
			right corner ,return 1 else 0*/
		if (HitToPoint>=wallWidth/2 - goalWidth/2 &&
					 HitToPoint<=wallWidth/2+goalWidth/2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
/* this function calculate the hit point according to left wall if
	top of ball hit the goal return 1 else 0 */
double HitToRight(double wallWidth,double wallHeight,double ballCenterX,
			double kickAngle,double ballRadius,double goalWidth)
{
		/* when ball come to wallheight ,Xlength is the length of x 
			and HitToPoint is x coordinate number*/
		double HitToPoint,XLength; 
		/* when ball is come to goal , the top hitting firstly, so it need
	  calculte according to top of ball therefore it must decrease the height*/ 
		if (wallHeight>ballRadius)
		{
				/* the height is smaller then ballradius it will be negative ,
			this condition protect it */
			wallHeight-=ballRadius;
		}
		
		/* this calculate the x length depent on wallheight*/
		XLength=wallHeight/tan(PI*kickAngle/180);
		/* This is coordinate of x */
		HitToPoint=(ballCenterX)+XLength;
			printf("------------------right------------------------------\n");
		printf("wallHeight=%f\n",wallHeight );
		printf("a=%f\n",kickAngle );
		printf("x1=%f\n",XLength );
		printf("x2=%f \n", HitToPoint);
		/* the top of x coordination is bigger then goal left corner and 
		smaller goal right corner ,return 1 else 0*/
		if (HitToPoint>=wallWidth/2 - goalWidth/2 &&
				 HitToPoint<=wallWidth/2+goalWidth/2)
			return 1;
		else
			return 0;
}
/* the ball return in inside while the ball reflect from the wall
 until the ball height bigger then wall height  */
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth)
{

	double XLength=0,YLength=0;/* This is length to taken ball way x and y
		on reflection time*/

	double TempAngle=0; /* This is help to calculate tan value if 
	kickdegree bigger then 90 it must be calculate the supplementary degree */
	double ReflectAngle=0;/* This is the reclect angle when ball come to wall*/

	double GoalLeft,GoalRight;/* These are used when kick angle 90 degress*/

	/* 	Invalid states	*/
	if (goalWidth>wallWidth || ballRadius>wallWidth/2 || goalWidth<=0 ||
			ballRadius<=0 || wallHeight<0 || ballCenterX<ballRadius)
	{
		return 0;
	}
	/* if the angle under the 5 degrees ,it will take it on 5 degree*/
	if (kickAngle<0)
	{
		kickAngle=5;

	/*  if the angle over the 175 degrees, it will take it on 175 degree*/
	}else if(kickAngle>175)
	{
		kickAngle=175;
	}

	if (kickAngle>90)
	{
		/* Take the supplementary degree to calculate tan values
		 	if bigger then 90 degree*/
		TempAngle=180 - kickAngle;
	}
	/* if the angle equal to 90 degree the ball will go with vertical angle  */
	else if(kickAngle==90)
	{
		GoalLeft=wallWidth/2- goalWidth/2;/*the left of goal coordinate*/
		GoalRight=wallWidth/2+ goalWidth/2;/*the right of goal coordinate*/
		if ((ballCenterX>=GoalLeft && ballCenterX<=GoalRight))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		TempAngle=kickAngle;
	}
	/*  This is calculate the length of x and y way*/
	XLength=wallWidth-(ballCenterX+ballRadius);
	YLength=XLength*tan(PI*TempAngle/180);
	printf("%f ile geldi\n", kickAngle);
	printf("h=%f\n",YLength );
	printf("wallHeight%f\n",wallHeight );
	printf("****x=%f\n",XLength );
	/* The Y length smaller then Wallheight send to again with new rejlect 
		degree to this function which wallHeight decrease to the taken way */
	if (YLength<wallHeight) 
	{
		
		ballCenterX=ballRadius;
		ReflectAngle= kickAngle; //reflection(kickAngle);
		return kickDisc(wallWidth,wallHeight-YLength,ballCenterX,
				ReflectAngle,ballRadius,goalWidth);
	}
	/* if y lenght bigger then wallheight , send to hit functions 
			 to it is goal or not*/
	else 
	{
		/* when the ball is goal which come from left wall or right wall, 
		each hit must be goal or not */

		if (HitToRight(wallWidth,wallHeight,ballCenterX,
										TempAngle,ballRadius,goalWidth) 
			|| HitToLeft(wallWidth,wallHeight,ballCenterX,
										TempAngle,ballRadius,goalWidth))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}
/* This give a angle which diversion between -5 degrees and +5 degrees.*/
int reflection(int angle)
{
	int NewRandom=randNumber(angle) % (11);
	angle-=5;
	/*if angle bigger then  175 return 175,else smaller then 5 return 5*/
	if (NewRandom+angle>=5 && NewRandom+angle<=175)
	{
		return NewRandom+angle;
	}
	if (NewRandom+angle<5)
	{
		return 5;
	}
	else if (NewRandom+angle>175)
	{
		return 175;
	}
	else
	{
		return reflection(angle);
	}
} 
int randNumber(int angle){
	srand(angle);
	return rand();
}
