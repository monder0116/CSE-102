#include <stdio.h>

int sum();

int main()
{

	printf("toplam:%d",sum());
	
	return 0;
}
int sum()
{


	int n;
	int m;
	int result=0;
	while(1)
	{
		scanf("%d %d",&n,&m);
		
		if (n%2==1)
		{
			/* code */
			result+=m;

		}
		if (n==1)
		{
			/* code */
			return result;

		}
	}
}
