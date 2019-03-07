#include <stdio.h>
#include <string.h>


/* Calculating Mode in C
 * Kaitlin Berryman cmpr271
 * Olivia Luetge 
cmpr 271 */

int main()

{ 
	
	// declaring variables
	int totalNumbers=0, count=0, modeCount=0, tempCount=0;
	float mode=0.0, number=0.0;
		
	// asking user for how many numbers are in the data set
	printf("Please enter how many numbers you wish to use to calculate the mode?\n");

	scanf("%d", &totalNumbers);

	// create an array with the user's input
	printf("Enter the numbers.\n");
	float numbers[totalNumbers];
	for(count; count < totalNumbers; count++)	
	{
			
		scanf("%e", &number); // reading in the number and assigning it to value
    		numbers[count] = number;	
	}

	
	
	// loop through the values
	for(int i=0; i < totalNumbers; i++)
	{
		tempCount = 0;

		for(int j=i+1; j < totalNumbers; j++)
		{
			// check to see if any values match the current one
			if(numbers[i] == numbers[j])
			{
				tempCount++;
			}
		}
		
		// check to see if there's a new mode
		if(tempCount > modeCount)
		{
			modeCount = tempCount;
			mode = numbers[i];
		}	
	}

	printf("The mode of %d numbers is %e which is included %d times.\n", totalNumbers, mode, modeCount+1);
	return 0;

}