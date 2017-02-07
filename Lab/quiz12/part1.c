#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	int rows;
	int cols;
	float *data;

}Matrix;
Matrix Newmatrix(int cols,int rows);
int readMatrixies(FILE *fp,Matrix *mxs);
Matrix readMatrix(FILE *fp);
void writeMatrix(FILE *fp,Matrix m);
void writeMatrixes(FILE *fp,Matrix *m,int count);
void printMatrix(Matrix t);
Matrix matrixMult(Matrix a,Matrix b);
int main()
{


	return 0;

}
Matrix newMatrix(int cols,int rows)
{
	Matrix new;
	new.cols=cols;
	new.rows=rows;
	new.data=(float *)calloc(rows*cols,sizeof(float));
	return new;

}

int readMatrixes(FILE *fp,Matrix *mxs)
{
	int mcount=0,arraysize=0,i;
	Matrix Newmatrix;
	fread(&mcount,sizeof(int),1,fp);
	mxs=(Matrix *)calloc(mcount,sizeof(Matrix));
	for ( i = 1; i <= mcount; ++i)
	{
		Newmatrix=readMatrix(fp);
		mxs[arraysize]=Newmatrix;
		arraysize++;
	}
	return mcount;
}
Matrix readMatrix(FILE *fp)
{
	Matrix Nmatrix;
	fread(&Nmatrix,sizeof(Nmatrix),1,fp);
	return Nmatrix;
}
void writeMatrix(FILE *fp,Matrix m)
{
	int i;
	fwrite(&m.rows,sizeof(int),1,fp);
	fwrite(&m.cols,sizeof(int),1,fp);
	for (i = 0; i < m.cols*m.rows; ++i)
	{
		fwrite(&m.data[i],sizeof(float),1,fp);
	}
}
void writeMatrixes(FILE *fp,Matrix *m,int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		writeMatrix(fp,m[i]);
	}
}
void printMatrix(Matrix t)
{
	int k;
	for ( k = 0; k < t.rows*t.cols; ++k)
	{

		if ((k+1)%t.cols==0)
		{
			printf("%f\n",t.data[k] );
		}else
		{
			printf("%f ",t.data[k] );
		}
	}
}
Matrix matrixMult(Matrix a,Matrix b)
{
	Matrix mult;
	float **yenia,**yenib;
	int i,row=-1,col=-1,j;
	int son=0;
	yenia=(float **)calloc(a.rows,sizeof(float *));
	yenib=(float **)calloc(b.rows,sizeof(float *));
	for (i = 0; i < a.rows; ++i)
	{
		yenia[i]=(float *)calloc(a.cols,sizeof(float));
	}
	for ( i = 0; i < a.rows*a.cols; ++i)
	{
		if (i % a.cols!=0)
		{
				yenia[row][col]=a.data[i];
		}
		else
		{
			row++;
			col=0;
			yenia[row][col]=a.data[i];
		}
	}
	for (i = 0; i < b.rows; ++i)
	{
		yenib[i]=(float *)calloc(b.cols,sizeof(float));
	}
	for ( i = 0; i < b.rows*a.cols; ++i)
	{
		if (i % b.cols!=0)
		{
				yenib[row][col]=b.data[i];
		}
		else
		{
			row++;
			col=0;
			yenia[row][col]=a.data[i];
		}
	}
	mult=newMatrix(b.cols,a.rows);

	for ( i = 0; i < a.rows; ++i)
	{
		for ( j = 0; j < b.cols; ++j)
		{
			mult.data[son]=yenia[i][j]*yenib[j][i];
			son++;
		}
	}
	return mult;
	

}