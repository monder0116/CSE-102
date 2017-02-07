#include <stdio.h>

double calculator(double num1,double num2,char operation);

int main()
{
	printf("%lf \n",calculator(6.0,3.0,'+'));
	printf("%lf \n",calculator(6.0,3.0,'-'));
	printf("%lf \n",calculator(6.0,3.0,'*'));
	printf("%lf \n",calculator(6.0,3.0,'+'));
	return 0;

}

double calculator(double num1,double num2,char operation)
{
	double result;

	switch(operation)
	{
		case '+':
			result=num1+num2;
			break;
		case '-':
			result=num1-num2;
			break;
		case '*':
			result=num1*num2;
			break;
		case '/':
			result=num1/num2;
			break;
		default:
			break;
	}
	return result;
}
