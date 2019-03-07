#include <stdio.h>
#include <string.h>


/* Calculating Mean in C
 * Kaitlin Berryman cmpr271
 * Olivia Luetge 
cmpr271 */

int main()

{ 
	
	// declaring variables
	int totalNumbers=0, count=0;
	float number=0, sum=0, mean=0;
		
	// asking user for console input and how many numbers to average
	printf("Please enter how many numbers you wish to use to calculate the mean.\n");

	scanf("%d", &totalNumbers);

	printf("List your numbers\n");
	for(count; count < totalNumbers; count++)	
	{
			
		// reading in the console input & assigning it to number
		scanf("%e", &number);
		
		// sum equals sum + value
		sum += number;	
	}

	

	mean = sum / totalNumbers;
	printf("The mean of the %d number(s) is %e\n", totalNumbers, mean);

	return 0;

}


