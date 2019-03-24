#include <stdio.h>
#include <string.h>


/* Calculating Median in C
 * Kaitlin Berryman cmpr271
 * Olivia Luetge 
cmpr 271 */

int main()

{ 
	
	// declaring variables
	int totalNumbers=0, count=0;
	float median=0, number=0;	

	// asking user for console input and how many numbers to use
	printf("Please enter how many numbers you wish to use to calculate the median.\n");

	scanf("%d", &totalNumbers);
	
	// create an array with the user's input
	printf("List your numbers.\n");
	float numbers[totalNumbers];
	for(count; count < totalNumbers; count++)	
	{
			
		scanf("%e", &number); // reading in the number and assigning it to value
    		numbers[count] = number;
	}


	
	// sorting the array to be in order from least to greatest
	int i,j,temp;
	for(i=0; i<totalNumbers-1; i++)
	{
		for(j=i+1; j<totalNumbers; j++)
		{
			if(numbers[j] < numbers[i])
			{	
				// switch places
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	
	// if there's an even amount of numbers, median equals the average of the middle values
	if(totalNumbers%2 == 0)
	{
		median = (numbers[totalNumbers/2] + numbers[totalNumbers/2 -1]) / 2;
	}
	
	// if there's an odd amount of numbers, median equals the middle value
	else
	{
		median = numbers[totalNumbers/2];
	}

	printf("The median of the %d number(s) is %e\n", totalNumbers, median);
	return 0;
}	
