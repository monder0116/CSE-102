#include <stdio.h>


int main()
{


	int arr[]={0,1,3,4,5,6,7,8,9,15,-5,0,9,10,23};
	int ind1,ind2;
	int ss=find_indice(arr,14,-2,&ind1,&ind2);
	if (ss==0)
	{
		/* code */
		printf("index1:%d\nindex2:%d",ind1,ind2);
	}else{
		printf("yok");
	}

	return 0;
}
int find_indice(const int arr[],int size,int target,int *ind_1,int *ind_2)
{
	int i,j;
	int temp1,temp2;
	for(i=0;i<size;i++)
	{	
		temp1=arr[i];
		for (j = 0; j < size; ++j)
		{
			temp2=arr[j];
			if (temp2+temp1==target)
			{
				*ind_1=i;
				*ind_2=j;
				return 0;
			}
		}

	}



}
