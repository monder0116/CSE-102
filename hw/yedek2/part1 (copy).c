#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	white,black
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
int isValidCell(char col, int row);
void initBoard(char *targetRow);
void printBoard(char *array);
int ConvertCol(char col);
int isPieceMovable();
void emptyBuffer();
void initBoard(char *ar)
{
	ar[0]='r';ar[1]='n';ar[2]='b';ar[3]='q';ar[4]='k';ar[5]='b';ar[6]='n';ar[7]='r';	
	ar[8]='p';ar[9]='p';ar[10]='p';ar[11]='p';ar[12]='p';ar[13]='p';ar[14]='p';ar[15]='p';
	ar[16]='c';ar[17]=' ';ar[18]=' ';ar[19]=' ';ar[20]=' ';ar[21]=' ';ar[22]=' ';ar[23]=' ';
	ar[24]=' ';ar[25]=' ';ar[26]=' ';ar[27]=' ';ar[28]=' ';ar[29]=' ';ar[30]=' ';ar[31]=' ';
	ar[32]=' ';ar[33]=' ';ar[34]=' ';ar[35]=' ';ar[36]=' ';ar[37]=' ';ar[38]=' ';ar[39]=' ';
	ar[40]='R';ar[41]=' ';ar[42]='R';ar[43]=' ';ar[44]=' ';ar[45]=' ';ar[46]=' ';ar[47]=' ';
	ar[48]='R';ar[49]='P';ar[50]='P';ar[51]='P';ar[52]='P';ar[53]='P';ar[54]='P';ar[55]='P';
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
	SourceControl=isValidCell(sCol,sRow);
	TargetControl=isValidCell(tCol,tRow);
	SColindex=ConvertCol(sCol);
	SElement=array[(8-sRow)*8+SColindex];

	if (!TargetControl && !SourceControl)
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
	if (col>=97 && col<=104)
	{
		return col-97;
	}
	return -1;
}
/*if the place obey tp rules return true else false*/
int isValidCell(char col, int row){
	
	if (ConvertCol(col)==-1 || row<=0 || row>8)
		return 0;
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
	/*Initialize*/
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
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
	if (TElement!=' ')
	{
		if (Sknight<='z' && Sknight>='a' )
			STeam=black;
		else
			STeam=white;
		
		if (TElement<='z' && TElement>='a' )
			TTeam=black;
		else
			TTeam=white;
		
		if (Movable && (STeam!=TTeam))
			Movable=true;
		else
			Movable=false;
	}
	return Movable;


}
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	/*queen ability same as the rook and bishop so each one can move it,it will 
		 be True*/
	if (isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow) 
		|| isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow) )
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
	scount=sourceRow*8+SColindex;
	tcount=targetRow*8+TColindex;
	Sbishop=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];

	/*if the move not valid to obey the rules return false */
	if (abs(sourceRow-targetRow)!=abs(SColindex-TColindex))
		{	
			return Movable;
		}
	/*Declare the team*/
	if (TElement!=' ')
	{
		if (Sbishop<='z' && Sbishop>='a' )
			STeam=black;
		else
			STeam=white;
		if (TElement<='z' && TElement>='a' )
			TTeam=black;
		else
			TTeam=white;
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
	if (TElement!=' ')
	{
		if (STeam!=TTeam  && Movable)
			Movable=true;
		else
			Movable=false;
	}

	return Movable;
}


int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sknight,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	/*initialize*/
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	
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
	/*Declare the team target and source team */
	if (TElement!=' ')
	{
		if (Sknight<='z' && Sknight>='a' )
			STeam=black;
		else
			STeam=white;
		
		if (TElement<='z' && TElement>='a' )
			TTeam=black;
		else
			TTeam=white;
		/* if the target place have a piece , if the team of the target piece 
			is a opposing the team , it will move else not*/
		if (Movable && (STeam!=TTeam))
			Movable=true;
		else
			Movable=false;
	}
	return Movable;
}

int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Spawn,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	
	/*Initialize*/
	Spawn=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];

	/*Declare the team of pieces*/
	if (Spawn=='p')
	{
		STeam=black;
	}
	else if (Spawn=='P')
	{
		STeam=white;
	}
	else{
		return 0;
	}

	if (TElement!=' ')
	{
		if (TElement<='z' && TElement>='a' )
			TTeam=black;
		else
			TTeam=white;
	}
	/*This is unvalid and valid states to obey the rules*/
	if (abs(targetRow-sourceRow)!=1 || abs(SColindex-TColindex)>1)
	{
		return Movable;
	}
	if (STeam)
	{
		/* if user want move place more then one return false*/
		if (targetRow-sourceRow !=1  )
		{
			Movable=false;
		}
		/*if user want to a place to space */
		else if (SColindex-TColindex==0 && board[targetRow*8+TColindex]==' ')
		{
			Movable=true;
		}
		
		/* if user want move to cross place this is only valid to take piece 
			which is opposing team , if there is a the team piece , return 1
				else 0*/
		else if(abs(SColindex-TColindex)==1 )
		{
			if (TTeam!=STeam  && board[targetRow*8+TColindex]!=' ')
				Movable=true;
			else
				Movable=false;
		}
	}
	else
	{
		
		if (targetRow-sourceRow !=-1 )
			Movable=false;
		else if (SColindex-TColindex==0 && board[targetRow*8+TColindex]==' ')
			{	
				
				Movable=true; 
				printf("burda2\n");         
			}
		else if(abs(SColindex-TColindex)==1 )
		{
			printf("burda3\n");
			if (TTeam!=STeam && board[targetRow*8+TColindex]!=' ')
				Movable=true;
			else
				Movable=false;
		}
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
	/*Initialize*/

	/*Find source element team*/
	if (Srook<='z' && Srook>='a' )
		STeam=black;
	else
		STeam=white;
	
	/*Find target element team*/
	if (TElement!=' ')
	{
		if (TElement<='z' && TElement>='a' )
		TTeam=black;
		else
		TTeam=white;
	}
	

	/* if the rook want move to piece which is not valid to general rules,
		return false*/
	
	/*if rook move on rows or cols*/
	if (abs(TColindex-SColindex)==0 )
	{
		/*search the pieces to have any element from the lower row 
			to higher row,return false*/
		if (sourceRow>targetRow)
		{
			Lower=targetRow;
			Higher=sourceRow;
		}else{
			Lower=sourceRow;
			Higher=targetRow;
		}
		for (Counter= Lower+1; Counter < Higher; ++Counter)
		{
			printf("%d %d\n",Counter,SColindex);
		
			if (board[Counter*8+SColindex]!=' ')
			{
				Isempty=false;
				return Isempty;
			}else
			{
				Isempty=true;
			}
		}
		
	}
	else if(abs(targetRow-sourceRow)==0 )
	{
		/*if rook want to move to reverse ,change the cols, else the values
			as same*/
		if (sourceCol>targetCol)
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
				printf("%d %d\n",sourceRow,Counter );
				if (board[sourceRow*8+Counter]!=' ')
				{
						Isempty=false;
						return Isempty;
				}
				else
				{
					Isempty=true;
				}
			}
		
	}
	if (Isempty)
	{
		if (TElement!=' ')
		{
			/* if the source and target team is same return false ,else true*/
			if (STeam!=TTeam)
				{
					Isempty=true;
				}
				else{
					Isempty=false;
				}
		}
	}
	/* return the result */
	return Isempty;
}	