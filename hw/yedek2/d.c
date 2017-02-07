#include <stdio.h>
int main()
{

	char ilk='a';
	char son='i';
	printf("a: %d \n g:%d",ilk,son);
	return 0;

}
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false,true
}bool;
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
void getPosition(char *col, int *row);
int isValidCell(char col, int row);
void initialize(char *targetRow);
void ShowBoard(char *array);
	
int isPieceMovable();
void emptyBuffer();
int main()
{
	char array[64];
	isPieceMovable(array);

	return 0;

}
void initialize(char *array)
{
		int i,j;
	for (i = 7; i>=0;i--)
	{

		for (j = 7; j>=0; j--)
		{

			array[8*i+j]='.';
		}
	}
		array[2]='M';
	array[10]='K';
	array[9]='m';
	array[10]='K';


}
void ShowBoard(char *array)
{
		int i,j;
	for ( i = 7; i>=0;i--)
	{
		if (i==7)
		{
				for (j = 0; j < 8; ++j)
				{
					char s='a'+j;
					if (j==0)
					{
						printf(" ");
					}
					printf("%c", s);
				}
				
		}
		printf("\n");
		printf("%d",i+1);
		
		for ( j = 0; j < 8; ++j)
		{
			printf("%c",array[i*8+j]);
		}
		printf("\n" );
	}


}

int isPieceMovable(char *array)
{

	char c;
	char sCol,tCol;
	int sRow,tRow;

	int SourceControl,TargerControl;
	initialize(array);
	ShowBoard(array);
	/*take a source and target*/
	getPosition(&sCol,&sRow);
	scanf("%c",&c);
	getPosition(&tCol,&tRow);

	SourceControl=isValidCell(sCol,sRow);
	TargerControl=isValidCell(tCol,tRow);
	if (TargerControl && SourceControl)
	{
		
			int a;
		
					a=isRookMovable(array , sCol, sRow-1, tCol,tRow-1);
					printf("işlem %d",a);
					
	
	}else{
		printf("yanlış");
	}
	emptyBuffer();

	return 0;
}
int ConvertCol(char col){
	if (col>=97 && col<=104)
	{
		return col-97;
	}
	return -1;
}
int isValidCell(char col, int row){
	
	if (ConvertCol(col)==-1 || row<=0 || row>8)
	{
		return 0;
	}
		return 1;
}
void getPosition(char *col, int *row)
{
	scanf("%c%d",col,row);
}

void emptyBuffer()
{
	while ( getchar() != '\n' );
}

int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int SColindex=0,TColindex=0;
	int STeam,TTeam;
	int Counter ;
	bool Isempty=true;
	SColindex=ConvertCol(sourceCol);
	TColindex=ConvertCol(targetCol);
	char Srook=board[sourceRow*8+SColindex];
	char TElement=board[targetRow*8+TColindex];
	
	if (Srook<='z' && Srook>='a' )
	{
		STeam=1;
	}
	else
	{
		STeam=0;
	}
	if (TElement<='z' && TElement>='a' )
	{
		TTeam=1;
	}
	else
	{
		TTeam=0;
	}
	
	if (abs(TColindex-SColindex)==0 || abs(sourceRow-targetRow)==0)
	{
			if (abs(TColindex-SColindex)==0 )
			{
				if (sourceRow>targetRow)
				{
					
					for (Counter= sourceRow-1; Counter > targetRow; --Counter)
					{

						if (board[Counter*8+SColindex]=='.')
							{	
								Isempty=true;
							}
						else	
							{
								return 0;
								
							}
					}
				}else
				{
				
					for (Counter= sourceRow+1; Counter < targetRow; ++Counter)
					{

						if (board[Counter*8+SColindex]=='.')
						{	
							Isempty=true;
						}
						else	
						{
							return 0;
						}
					}
				}
				
				
			}
			else
			{
				if (sourceCol>targetCol)
				{
					for (Counter= SColindex-1; Counter > TColindex; --Counter)
					{
					
						if (board[sourceRow*8+Counter]=='.')
						{	
							Isempty=true;
						}
						else	
						{
							return 0;
						}
					}
				}else
				{
					for (Counter= SColindex+1; Counter < TColindex; ++Counter)
					{
						printf("col büyük");
						if (board[sourceRow*8+Counter]=='.')
						{	
							Isempty=true;
						}
						else	
						{
								return 0;
						}
					}
				
				
				
				}
			}
			if (Isempty)
			{
				if (board[targetRow*8+TColindex]!='.')
				{
					if (STeam!=TTeam)
						{
							Isempty=true;
						}
						else{
							Isempty=false;
						}
				}
			}
			return Isempty;
				
	}
	
	
	else
	{
		return  0;
	}

}