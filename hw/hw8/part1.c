/*----------------------------------------------------------------------------*/
/*HW08_part1_Mehmet_Onder_131044076_part1.c                                   */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Mehmet Onder on april 18, 2016                                	  */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/* This program is chess simulator that performs basic operations in a game	  */
/*	and rows are represented by characters and integers.					  */
/*	Program use lowercase and uppercase letters for the white and black users.*/
/*	There are chess piece to control the move to valid or invalid.			  */
/*	the program will check the king to whether a king is in check or not. 	  */
/*	There are helper function to find cell or convert the col etc.			  */
/*																			  */
/*																			  */
/*Inputs:                                                                     */
/*----------																  */
/* the source and target rows and cols,									      */
/*																			  */
/*Outputs:  																  */
/*---------                                                                   */
/* the move is valid or invalid information ,								  */
/* the king is in check or not												  */
/*  the player win or not													  */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
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
/*These will check whether a piece can move from source cell to the target cell 
according to the rules of the game.*/
int isRookMovable(char *board , char sourceCol, int sourceRow,
		 char targetCol, int targetRow);
int isKnightMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow);
int isBishopMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow);
int isQueenMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow);
int isPawnMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow);
int isKingMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow);
/*If the piece is movable ,it returns 1, otherwise 0*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
/*This function will check whether the given cell is valid
according to the board sizes and returns 1 if it is valid, otherwise 0.*/
int isValidCell(char col, int row);
/*declare the team*/
int isWhite(char player);
/*declare the team*/
int isBlack(char player);
/*Checks whether a king is in check or not.*/
int isInCheck(char* board);
/*Moves a piece from source to destination if current player’s king is not
in check and piece can move from source to destination. If player’s king
is in check, move should not be made and board should remain same.*/
int makeMove(char *board, char sc, int sr, char tc, int tr);
/*Checks whether a king is in check or not.*/
int isInCheck(char* board);
/*This function will take the row and column values of a specific cell 
	on the board.*/
void getPosition(char *col, int *row);
/* initialize the board with pieces*/
void initBoard(char *targetRow);
/*This function will print the current state of the board*/
void printBoard(char *array);
void emptyBuffer();
/* this return the piece from board which the select cell*/
char getPlayer(char *board, char sc,int sr);

/*------Helper Functions-------*/

/*this help to find index which name is taken element*/
int FindIndex(char *board,char element);
/*this find the piece team*/
Team FindTeam(char piece);
/*convert the char to integer value */
int ConvertCol(char col);

/*-----------------Function İmplementation-----------*/



/* this return the piece from board which the select cell*/
char getPlayer(char *board, char sc,int sr){
	return (board[((8-sr)*8)+ConvertCol(sc)]);
}
/* Find and return the team of select cell which is which or black*/
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

int main() {
    char board [64], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}


/* this find index in board which equal to element*/
int FindIndex(char *board,char element)
{
	int i;
	for ( i = 0; i < 64; ++i)
	{
		if (board[i]==element)
		{
			return i;
		}
	}
	return -1;

}
/*This is helper function to declare the col value*/
int ConvertCol(char col){
	if (col>='a' && col<='h')
	{
		return col-'a';
	}
	return -1;
}

/*initialize the board*/
void initBoard(char *ar)
{
	ar[0]='r';ar[1]='n';ar[2]='b';ar[3]='q';ar[4]='k';ar[5]='b';ar[6]='n';
	ar[7]='r';	
	ar[8]='p';ar[9]='p';ar[10]='p';ar[11]='p';ar[12]='p';ar[13]='p';ar[14]='p';
	ar[15]='p';
	ar[16]=' ';ar[17]=' ';ar[18]=' ';ar[19]=' ';ar[20]=' ';ar[21]=' ';ar[22]=' '
	;ar[23]=' ';
	ar[24]=' ';ar[25]=' ';ar[26]=' ';ar[27]=' ';ar[28]=' ';ar[29]=' ';ar[30]=' ';
	ar[31]=' ';
	ar[32]=' ';ar[33]=' ';ar[34]=' ';ar[35]=' ';ar[36]=' ';ar[37]=' ';ar[38]=' ';
	ar[39]=' ';
	ar[40]=' ';ar[41]=' ';ar[42]=' ';ar[43]=' ';ar[44]=' ';ar[45]=' ';ar[46]=' ';
	ar[47]=' ';
	ar[48]='P';ar[49]='P';ar[50]='P';ar[51]='P';ar[52]='P';ar[53]='P';ar[54]='P';
	ar[55]='P';
	ar[56]='R';ar[57]='N';ar[58]='B';ar[59]='Q';ar[60]='K';ar[61]='B';ar[62]='N';
	ar[63]='R';
}



/* this is control the move to valid or invalid,
-If move is invalid, returns 0
-If move is invalid because same player's king is in check, returns 1
-If move is valid, returns 2
-If move is valid and opponent player's king is in check, returns 3 */
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	char SElement; /* Source Piece*/
	Team STeam; /* Source Team*/
	/*when move is valid but the king in check , the move will no be valid so
		Result1 is check the valid state on board,
		result2 is check the king state*/
	int result1=0,result2=0;
	
	int TempSource,TempTarget;/*when the move will not be valid, go back to old
		state, these are save the the old position*/ 
	SElement=getPlayer(board,sc,sr); /*select the piece*/
	STeam=FindTeam(SElement);/* select source team, the white or black*/
	if (isPieceMovable(board,sc,sr,tc,tr))
	{
		TempSource=board[((8-sr)*8)+ConvertCol(sc)];
		TempTarget=board[((8-tr)*8)+ConvertCol(tc)];
		/*move the piece to new positon*/
		board[((8-sr)*8)+ConvertCol(sc)]=' ';
		board[((8-tr)*8)+ConvertCol(tc)]=TempSource;
		
		if ((STeam==white && isInCheck(board)==2)
			|| (STeam==black && isInCheck(board)==1))
		{
			result1=3;
		}
		else
		{
			result1=2;
		}
		if ((STeam==white && isInCheck(board)==1) 
			|| (STeam==black && isInCheck(board)==2))
		{
			result2=1;
		}
		if (result1==2 && result2==1)
		{
			/*when move is valid but the king in check , t
				he move will no be valid*/
			board[((8-sr)*8)+ConvertCol(sc)]=TempSource;
			board[((8-tr)*8)+ConvertCol(tc)]=TempTarget;
			return 1;

		}
		/*the move is valid or opponent king in check return the state*/
		return result1;
	}
	else
	{
		/*move is invalid*/
		return 0;
	}
}

/*Control the king to check which team black or white*/
/*
If white king is in check, returns 1
If black king is in check, returns 2
If there is no check, returns 0 */
int isInCheck(char* board){
	int KingIndex;
	int index,Process=0;
	/* Firstly control the White team in check*/
	KingIndex=FindIndex(board,'K');
	for (index = 0; index < 64; ++index)
	{
		switch(board[index])
		{
			/* if each one is valid,the king is incheck*/
			case 'r':
				Process= isRookMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'b':
				Process= isBishopMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'n':
				Process=isKnightMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'q':
				Process=isQueenMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'p':
				Process=isPawnMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
		}
		if (Process)
		{
			return 1;
		}
	}
	/* then control the black tean in check*/
	KingIndex=FindIndex(board,'k');
	for (index = 0; index < 64; ++index)
	{
		switch(board[index])
		{
			/* if each one is valid , the king is check*/
			case 'R':
				Process= isRookMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'B':
				Process= isBishopMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'N':
				Process=isKnightMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'Q':
				Process=isQueenMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
			case 'P':
				Process=isPawnMovable(board,'a'+ (index % 8),8-index/8,
						(KingIndex%8)+'a',8-KingIndex/8);
				break;
		}
		if (Process )
		{
	;
			return 2;
		}
	}

	return 0;
}
/*this is help to main function to find the team */
int isBlack(char player)
{
	if (player>='a' && player<='z')
	{
		return 1;
	}
	return 0;
}
/* this is help to main function to find team*/
int isWhite(char player)
{
	if (player>='A' && player<='Z')
	{
		return 1;
	}
	return 0;
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
/*If the piece is movable it returns 1, otherwise 0.
1)Whether the move is valid according to the general rules of the game,
if there is another piece of the same player on the target cell, the move is 
not valid. 
2) Whether the move is valid dependsing
on the type of the piece in the source cell and the state of the board*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
	int Process,SourceControl,TargetControl;
	char SElement;
	SElement=getPlayer(board,sc,sr);
	/*Control them to valid or unvalid*/
	SourceControl=isValidCell(sc,sr);
	TargetControl=isValidCell(tc,tr);
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*Declare to piece which name is and control to movable */
	switch(SElement)
	{	
		case 'R':
		case 'r':
			Process=isRookMovable(board,sc,sr,tc,tr);
			break;
		case 'N':
		case 'n':
			Process=isKnightMovable(board,sc,sr,tc,tr);
			break;
		case 'B':
		case 'b':
			Process=isBishopMovable(board,sc,sr,tc,tr);
			break;
		case 'Q':
		case 'q':
			Process=isQueenMovable(board,sc,sr,tc,tr);
			break;
		case 'K':
		case 'k':
			Process=isKingMovable(board,sc,sr,tc,tr);
			break;
		case 'P':
		case 'p':
			Process=isPawnMovable(board,sc,sr,tc,tr);
			break;
	}
	return Process;
}

/*if the place obey to rules return true else false*/
int isValidCell(char col, int row)
{
	row=8-row;
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
	int SColindex;
	int TColindex;
	int SourceControl,TargetControl;
	/*Initialize*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	sourceRow=8- sourceRow;
	targetRow=8- targetRow;
	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	/*Declare the team target and source team */
	STeam=FindTeam(Sknight);
	TTeam=FindTeam(TElement);

	/* check the cell to valid or not*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*King move only a cell to everwhere if target place avaible to move,
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
int isQueenMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow)
{

	int SourceControl,TargetControl;
	/*invalid place control*/
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
int isBishopMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow)
{

	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sbishop,TElement;
	int SColindex;
	int TColindex;
	int Counter;
	int scount,tcount;
	int SourceControl,TargetControl;
	int increase=0;
	/*initialize*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	sourceRow=8- sourceRow;
	targetRow=8- targetRow;
	
	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	/* Find the number of cell*/
	scount=sourceRow*8+SColindex;
	tcount=targetRow*8+TColindex;
	/*Find The element*/
	Sbishop=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];

	/*Declare the team target and source team */
	STeam=FindTeam(Sbishop);
	TTeam=FindTeam(TElement);
	/* Check the cell to valid or not*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}
	/*if the move is invalid to obey the rules return false */
	if (abs(sourceRow-targetRow)!=abs(SColindex-TColindex))
	{	
			return 0;
	}
	
	
	if (scount>tcount)
	{
		int temp=tcount;
		tcount=scount;
		scount=temp;
	}
		if (abs(tcount- scount)%7==0)
		{
			increase=7;
		}
		else 
		{
			increase=9;
		}
		/*Search the places to be null,else return false*/
		for (Counter=scount+increase; Counter < tcount; Counter+=increase)
		{
			if (board[Counter]!=' ')
			{
				return false;
			}
		}
		/*the places are null so it will move*/
		Movable=true;
		/*if arget and source team not equal to each other and movable true
			, movable true ,else false*/
		if (STeam!=TTeam  && Movable)
			Movable=true;
		else
			Movable=false;
	return Movable;
}


int isKnightMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	char Sknight,TElement;
	int SColindex=ConvertCol(sourceCol);
	int TColindex=ConvertCol(targetCol);
	int SourceControl,TargetControl;
	/*initialize*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	sourceRow=8- sourceRow;
	targetRow=8- targetRow;
	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	Sknight=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];
	/*Declare the team target and source team */
	STeam=FindTeam(Sknight);
	TTeam=FindTeam(TElement);
	/* Check the cell to valid or not*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}


	/*if  the move is valid to rules, Moveable true else false*/
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
		/*the source team is not equal to target team and moveanle true,
		 moveable will be true else false */
		if (Movable && (STeam!=TTeam))
			Movable=true;
		else
			Movable=false;
	}
	/*the target team is empty return the moveable*/
	return Movable;
}


int isPawnMovable(char *board, char sourceCol, int sourceRow,
	 char targetCol, int targetRow){
	/*Declares*/
	Team STeam,TTeam;
	bool Movable=false;
	int sindex,tindex,SColindex,TColindex;/* this is help to calculate states*/
	char TElement,SElement;
	int SourceControl,TargetControl;
	/*Initialize*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	/* Change the row order*/
	sourceRow=8- sourceRow;
	targetRow=8- targetRow;

	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	TElement=board[targetRow*8+TColindex];
	SElement=board[sourceRow*8+SColindex];
	/*Find the cell numbers*/
	sindex=sourceRow*8+SColindex;
	tindex=targetRow*8+TColindex;
    /*Declare the teams*/
	STeam=FindTeam(SElement);
	TTeam=FindTeam(TElement);
	/* Check the cell to valid or not*/
	if (TargetControl!=1 || SourceControl!=1)
	{
		return 0;
	}

	if (STeam==white)
	{
		if (TTeam==empty)
		{
			/*the pawn move only eight cell when target team is empty*/
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
			/*the pawn move only seven or nine cell when target team is black*/
				if ((sindex-tindex)==7 ||(sindex-tindex) ==9 )
				{
					Movable=true;
				}
				else
				{
					Movable=false;

				}
		}else
		/*when the targer team is same with source team*/
			Movable=false;

	}else if(STeam==black)
	{
		if (TTeam==empty)
		{
			/*the pawn move only eight cell when target team is empty*/
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
			/*the pawn move only seven or nine cell when target team is white*/
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
int isRookMovable(char *board , char sourceCol, int sourceRow,
	 char targetCol, int targetRow)
{
	/*Declares*/
	Team STeam,TTeam;
	bool Isempty=false;
	int SColindex;
	int TColindex;
	int Counter;
	int Lower,Higher;
	char Srook;
	char TElement;
	int SourceControl,TargetControl;
	/*Initialize*/
	SourceControl=isValidCell(sourceCol,sourceRow);
	TargetControl=isValidCell(targetCol,targetRow);
	/* Change the row order*/
	sourceRow=8- sourceRow;
	targetRow=8- targetRow;
	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	Srook=board[sourceRow*8+SColindex];
	TElement=board[targetRow*8+TColindex];

	 /*Declare the teams*/
	STeam=FindTeam(Srook);
	TTeam=FindTeam(TElement);
	/* Check the cell to valid or not*/
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
		/*there is no piece in rows*/
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
			/*there is no piece in cols*/
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