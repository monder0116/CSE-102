printf("1.ülke\n");
	strcpy(countries[0].CName,"a");
	countries[0].Soldiers=44;
	countries[0].Population=5;
	strcpy(countries[0].Neighbors[0],"b");
	strcpy(countries[0].Neighbors[1],"c");
	strcpy(countries[0].Neighbors[2],"g");
	strcpy(countries[1].CName,"b");
	countries[1].Population=10;
	countries[1].Soldiers=66;
	strcpy(countries[1].Neighbors[0],"g");
	strcpy(countries[1].Neighbors[1],"f");
	strcpy(countries[2].CName,"g");
	countries[2].Soldiers=55;
	countries[2].Population=2;
	strcpy(countries[2].Neighbors[0],"m");
	strcpy(countries[2].Neighbors[1],"n");
	strcpy(countries[3].CName,"c");
	countries[3].Soldiers=55;
	countries[2].Population=8;
	strcpy(countries[3].Neighbors[0],"g");
	strcpy(countries[3].Neighbors[1],"ff");
	int sort(int *numbers,int len)
{
	int i,j;
	for (i = 0; i < len; ++i)
	{
		for (j = i; j<len; ++j)	
		{
			if (numbers[i]>numbers[j])
			{
				int temp=numbers[j];
				numbers[j]=numbers[i];
				numbers[i]=temp;
			}
		}
	}
}