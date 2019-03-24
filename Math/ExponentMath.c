/* Exponent Math in C
 * Kaitlin Berryman */
 
#include<stdio.h>

int main()
{
	int exp1, exp2, cof1, cof2, operator;

	// ask user for coefficient values 
	printf("Please enter 2 positive integers to use as the two coefficients.\n");
	scanf("%d",&cof1);
	scanf("%d",&cof2);

	// ask user for exponent values
	printf("Please enter 2 positive integers to use as the two exponents.\n");
	scanf("%d",&exp1);
	scanf("%d",&exp2);
	
	// Find out which operation to perform
	printf("Type 0 to divide. Type 1 to multiply. Type 2 to add. Type 3 to subtract. Type 4 to test all operations.\n");
	scanf("%d",&operator);
	
	switch(operator)
	{
		// Division
		case 0:
		printf("%dX^%d / %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1/cof2,exp1-exp2);
		break;
		
		
		// Multiplication
		case 1:
		printf("%dX^%d * %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1*cof2,exp1+exp2);
		break;
		
		
		// Addition
		case 2:
		// if the exponents are the same, add the cofficients and have one term
		if(exp1 == exp2)
		{
			printf("%dX^%d + %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1+cof2,exp1);
		}
		// otherwise, the expression can't be simplified further
		else
		{
			printf("%dX^%d + %dX^%d = %dX^%d + %dX^%d\nNote - The expression was already simplified.\n",cof1,exp1,cof2,exp2,cof1,exp1,cof2,exp2);
		}
		break;
		
		
		// Subtraction
		case 3:
		// if the exponents are the same, subtract the cofficients and have one term
		if(exp1 == exp2)
		{
			printf("%dX^%d - %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1-cof2,exp1);
		}
		// otherwise, the expression can't be simplified further
		else
		{
			printf("%dX^%d - %dX^%d = %dX^%d + %dX^%d\nNote - The expression was already simplified.\n",cof1,exp1,cof2,exp2,cof1,exp1,cof2,exp2);
		}
		break;
		
		
		// Divide, multiply, add, and subtract
		case 4:
		printf("%dX^%d / %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1/cof2,exp1-exp2);
		printf("%dX^%d * %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1*cof2,exp1+exp2);
		if(exp1 == exp2)
		{
			printf("%dX^%d + %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1+cof2,exp1);
			printf("%dX^%d - %dX^%d = %dX^%d\n",cof1,exp1,cof2,exp2,cof1-cof2,exp1);
		}
		
		else
		{
			printf("%dX^%d + %dX^%d = %dX^%d + %dX^%d\tNote - The expression was already simplified.\n",cof1,exp1,cof2,exp2,cof1,exp1,cof2,exp2);
			printf("%dX^%d - %dX^%d = %dX^%d + %dX^%d\tNote - The expression was already simplified.\n",cof1,exp1,cof2,exp2,cof1,exp1,cof2,exp2);
		}
		break;
		
		
		default:
		printf("Invalid Input");
	}	
}		



