#include <stdio.h>

int lwRev(int arr[],int size);

int main()
{
	int array[]={1,5,6,7};
	int size=4;
	int result=lwRev(array,size);
	int c1;
	for(c1=0;c1<size;c1++)
	{
		printf("%d",array[c1]);
	}
	return 0;
}
int lwRev(int arr[],int size)
{
	int c1;
	int temp1;
	int temp2;
	if (arr == NULL && size<=0)
	{
		return -1;
	}
	for(c1=0;c1<size/2;c1++)
	{
		temp1=arr[c1];
		temp2=arr[size-c1-1];
		arr[c1]=temp2;
		arr[size-c1-1]=temp1;				
	}
	return 0;
}


