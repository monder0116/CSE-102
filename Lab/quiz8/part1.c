#include <stdio.h>

int main()
{
	int i1=2,i2=1,i3=9;
	int i;
	int *arr[3];
	
	printf("%d",lwSort(arr,3));
	
	/*for ( i = 0; i < 3; ++i)
	{
		printf("%d\n",*arr[i] );
	}*/
	return 0;
}
int lwSort(int* arr[],int size)
{
	int c1,c2,*temp;
	if (size<=0 || arr==NULL)
	{
		return -1;
	}
	for ( c1 = 0; c1 < size; ++c1)
	{
		for ( c2 = c1; c2 < size; ++c2)
		{
			if (*arr[c1]>*arr[c2])
			{
				temp=arr[c1];
				arr[c1]=arr[c2];
				arr[c2]=temp;
			}
		}
	}
	return 0;
}