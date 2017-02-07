#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	white,black,empty
}Team;
typedef enum
{
	false,true
}bool;
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
void getPosition(char *col, int *row);
Team FindTeam(char piece);
int isValidCell(char col, int row);
void initBoard(char *targetRow);
void printBoard(char *array);
int ConvertCol(char col);
int isPieceMovable();
void emptyBuffer();
char getPlayer(board, sc,sr);
void initBoard(char *ar)
{
	ar[0]='r';ar[1]='n';ar[2]='b';ar[3]='q';ar[4]='k';ar[5]='b';ar[6]='n';ar[7]='r';	
	ar[8]='p';ar[9]='p';ar[10]='p';ar[11]='p';ar[12]='p';ar[13]='p';ar[14]='p';ar[15]=' ';
	ar[16]=' ';ar[17]=' ';ar[18]='P';ar[19]=' ';ar[20]=' ';ar[21]=' ';ar[22]=' ';ar[23]=' ';
	ar[24]=' ';ar[25]=' ';ar[26]=' ';ar[27]=' ';ar[28]='p';ar[29]='R';ar[30]='r';ar[31]=' ';
	ar[32]=' ';ar[33]=' ';ar[34]='p';ar[35]='p';ar[36]=' ';ar[37]='R';ar[38]=' ';ar[39]=' ';
	ar[40]='r';ar[41]=' ';ar[42]=' ';ar[43]='p';ar[44]=' ';ar[45]=' ';ar[46]=' ';ar[47]=' ';
	ar[48]='P';ar[49]='P';ar[50]='P';ar[51]='P';ar[52]='P';ar[53]='P';ar[54]='P';ar[55]=' ';
	ar[56]='R';ar[57]='N';ar[58]='B';ar[59]='Q';ar[60]='K';ar[61]='B';ar[62]='N';ar[63]='R';
}

void main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
}


void printBoard(char *array)
{
	int i,j;
	for ( i = 0;i<8;i++)
	{
		if (i==0)
		{
			for (j = 0; j < 8; ++j)
			{
				char s='a'+j;
				if (j==0)
				{
					printf("  ");
				}
				/*this s print the col names*/
				printf("%c", s);
				if (j!=7)
				{
					printf(" ");
				}
			}
			printf("\n  - - - - - - - -\n");

		}
	
		/*this is print the row names */
		printf("%d|",8-i);
		
		for ( j = 0; j < 8; ++j)
		{
			printf("%c",array[i*8+j]);
			if (j!=7)
			{
				printf(" ");
			}
		}
		printf("|\n" );
	}
	printf("  - - - - - - - -\n");


}

int isPieceMovable(char *array)
{
	int sRow,tRow;
	int SColindex;
	int Process;
	int SourceControl,TargetControl;
	char buffer;
	char SElement;
	char sCol,tCol;
	/*take a source and target value*/
	getPosition(&sCol,&sRow);
	scanf("%c",&buffer);
	getPosition(&tCol,&tRow);
	/*Control them to valid or unvalid*/
	
	SColindex=ConvertCol(sCol);
	SElement=array[(8-sRow)*8+SColindex];
	SourceControl=isValidCell(sCol,8-sRow);
	TargetControl=isValidCell(tCol,8-tRow);
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*Declare to piece which name is and control to movable */
	switch(SElement)
	{	
		case 'R':
		case 'r':
			Process=isRookMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
		case 'N':
		case 'n':
			Process=isKnightMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
		case 'B':
		case 'b':
			Process=isBishopMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
		case 'Q':
		case 'q':
			Process=isQueenMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
		case 'K':
		case 'k':
			Process=isKingMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
		case 'P':
		case 'p':
			Process=isPawnMovable(array,sCol,8-sRow,tCol,8-tRow);
			break;
	}
	return Process;
}
/*This is helper function to declare the col value*/
int ConvertCol(char col){
	if (col>='a' && col<='h')
	{
		return col-'a';
	}
	return -1;
}
/*if the place obey tp rules return true else false*/
int isValidCell(char col, int row){
	printf("cccccc%d\n",row );
	if (ConvertCol(col)==-1 || row<0 || row>7)
	{
		return 0;
	}
	return 1;
}
/*Take the col and row number from user*/
void getPosition(char *col, int *row)
{
	scanf("%c%d",col,row);
}

void emptyBuffer()
{
	while ( getchar() != '\n' );
}

int isKingMovable(char *board, char sourceCol, int sourceRow,
							char targetCol, int targetRow)
{

	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sknight,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	int SourceControl,TargetControl;
	/* check the cell to valid or not*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	/* invalid states*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*Initialize*/
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	/*Declare the team target and source team */
	STeam=FindTeam(Sknight);
	TTeam=FindTeam(TElement);
	/*King move only one place to everwhere if target place avaible to that,
		check true*/
	if (abs(SColindex-TColindex)==1 )
	{
		if (abs(sourceRow-targetRow)<=1)
			Movable=true;
	}else if (abs(sourceRow-targetRow)==1)
	{
		if (abs(SColindex-TColindex)<=1 )
			Movable=true;
	}
	/*if Target piece not equal to space ,there will a another piece ,Control
		it then if the target and souce piece teams not equal ,it will movable
		else not*/
	if (TTeam!=empty)
	{
		
		if (Movable && (STeam!=TTeam))
			Movable=true;
		else
			Movable=false;
	}
	return Movable;


}
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	int SourceControl,TargetControl;
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*queen ability same as the rook and bishop so each one can move it,it will 
		 be True*/
	if (isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow) ||
		isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow) )
		return 1;
	else
		return 0;

}
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sbishop,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	int Counter;
	/*initialize*/
	int scount,tcount;
	int SourceControl,TargetControl;
	/* Check the cell to valid or not*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	/* Find the number of cell*/
	scount=sourceRow*8+SColindex;
	tcount=targetRow*8+TColindex;
	/*Find The element*/
	Sbishop=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	/*Declare the team target and source team */
	STeam=FindTeam(Sbishop);
	TTeam=FindTeam(TElement);
		/*Invalid states*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}

	/*if the move not valid to obey the rules return false */
	if (abs(sourceRow-targetRow)!=abs(SColindex-TColindex))
		{	
			return Movable;
		}
	

	
	/*Search the places to be null*/
	if (scount<tcount)
	{
	
		for (Counter=scount+7; Counter < tcount; Counter+=7)
		{
			
			if (board[Counter]!=' ')
			{
				return Movable;
			}
		}
		/*the places are null so it will move*/
		Movable=true;
	}
	else{
		
		for (Counter=tcount+9; Counter < scount; Counter+=9)
		{
		
			if (board[Counter]!=' ')
			{
				return Movable;
			}
		}
		/*the places are null so it will move*/
		Movable=true;
	}
	/*if target piece not equal to teams it will move or not*/
		if (STeam!=TTeam  && Movable)
			Movable=true;
		else
			Movable=false;

	return Movable;
}


int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sknight,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	int SourceControl,TargetControl;
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);

	/*initialize*/
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	/*Declare the team target and source team */
	STeam=FindTeam(Sknight);
	TTeam=FindTeam(TElement);
	/*Invalid states*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}


	/*The state of piece to move to target place*/
	if (abs(SColindex-TColindex)==2 )
	{
		if (abs(sourceRow-targetRow)==1)
		{
			Movable=true;
		}
	}else if (abs(sourceRow-targetRow)==2)
	{
		if (abs(SColindex-TColindex)==1 )
		{
			Movable=true;
		}
	}
	
	if (TTeam!=empty)
	{
		/* if the target place have a piece , if the team of the target piece 
			is a opposing the team , it will move else not*/
		if (Movable && (STeam!=TTeam))
			Movable=true;
		else
			Movable=false;
	}
	return Movable;
}
Team FindTeam(char piece)
{
	if (piece>='a' && piece<='z')
	{
		return black;
	}
	else if (piece>='A' && piece<='Z')
	{
		return white;
	}
		return empty;

}
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	int sindex,tindex;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	char TElement=board[targetRow*8+TColindex];
	char SElement=board[sourceRow*8+SColindex];
	int SourceControl,TargetControl;
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	/*Find the cell numbers*/
	sindex=sourceRow*8+SColindex;
	tindex=targetRow*8+TColindex;
    /*Declare the teams*/
	STeam=FindTeam(SElement);
	TTeam=FindTeam(TElement);
	/* Invalid States*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}

	if (STeam==white)
	{
		if (TTeam==empty)
		{
			if (sindex-tindex==8)
			{
				Movable=true;
			}
			else
			{
				Movable=false;
			}
		}
		else if (TTeam==black)
		{
		
				if ((sindex-tindex)==7 ||(sindex-tindex) ==9 )
				{
					Movable=true;
				}
				else
				{
					Movable=false;

				}
		}else
			Movable=false;

	}else if(STeam==black)
	{
		if (TTeam==empty)
		{
			if (sindex-tindex==-8)
			{
				Movable=true;
			}
			else
			{
				Movable=false;
			}
		}
		else if(TTeam==white)
		{
			if ((sindex-tindex)==-7 ||(sindex-tindex) ==-9 )
			{
				Movable=true;
			}
			else
			{
				Movable=false;

			}
		}
		else
			Movable=false;
	}
	return Movable;
}
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	/*Declares*/
	Team STeam,TTeam;
	bool Isempty=false;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	int Counter;
	int Lower,Higher;
	char Srook=board[sourceRow*8+SColindex];
	char TElement=board[targetRow*8+TColindex];
	int SourceControl,TargetControl;
	/* Control the cell*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	 /*Declare the teams*/
	STeam=FindTeam(Srook);
	TTeam=FindTeam(TElement);
	/* if the rook want move to piece which is not valid to general rules,
		return false*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}

	/*if rook move on rows or cols*/

	if (abs(TColindex-SColindex)==0 )
	{

		/*if rook want to move to reverse ,change the rows ,else the values
			as same*/
		if (sourceRow>targetRow)
		{
			Lower=targetRow;
			Higher=sourceRow;
		}
		else{
			Lower=sourceRow;
			Higher=targetRow;
		}
		/*search the pieces to have any element from the lower row 
			to higher row,return false*/
		for (Counter= Lower+1; Counter < Higher; ++Counter)
		{
			if (board[Counter*8+SColindex]!=' ')
			{
				Isempty=false;
				return Isempty;
			}
		}
		/*this mean there is no piece in rows*/
		Isempty=true;
	}
	else if(abs(targetRow- sourceRow)==0 )
	{
		/*if rook want to move to reverse ,change the cols, else the values
			as same*/
		if (SColindex>TColindex)
		{	
			Lower=TColindex;
			Higher=SColindex;
		}
		else{
			Lower=SColindex;
			Higher=TColindex;
		}
			/*search the pieces to have any element from the lower col 
			to higher cols,return false*/
			for (Counter= Lower+1; Counter < Higher; ++Counter)
			{
				if (board[sourceRow*8+Counter]!=' ')
				{
						Isempty=false;
						return Isempty;
				}
			}
			/*this mean there is no piece in cols*/
		Isempty=true;
	}else
	{
		Isempty=false;
	}
	
	if (TTeam==STeam)
	{
		return false;

	}
	/* return the result */
	return Isempty;
}