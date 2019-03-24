#include <stdio.h>
#include <string.h>


/* Calculating Range in C
 * Kaitlin Berryman cmpr271
 * Olivia Luetge 
cmpr 271 */

int main()

{ 
	
	// declaring variables
	int count=0, totalNumbers=0;
	float range=0, number=0, highest=0, lowest=0;
		
	// asking user for how many numbers to find the range of
	printf("Please enter how many numbers you wish to use to calculate the range.\n");

	scanf("%d", &totalNumbers);

	printf("List your numbers.\n");
	for(count; count < totalNumbers; count++)	
	{
			
		scanf("%e", &number); // reading in the number and assigning it to value
		
		// set first value as the highest and lowest
    		if(count == 0)
		{
			highest = number;
			lowest = number;
		}
		
		// compare current number entered to the highest value
		if(number > highest)
		{
			highest = number;
		}
		
		// compare current number entered to the lowest value
		if(number < lowest)
		{
			lowest = number;
		}	
	}

	

	range = highest - lowest;
	printf("The range is %e.\n", range);
	return 0;

}
