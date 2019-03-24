/* Basic Statistics in C
 * Kaitlin Berryman cmpr271
 * Olivia Luetge cmpr 271 */

#include <stdio.h>
#include <math.h>

float meanF(float numbers[], int totalNumbers);
float medianF(float numbers[], int totalNumbers);
float modeF(float numbers[], int totalNumbers);
float rangeF(float numbers[], int totalNumbers);
float varianceF(float numbers[], int totalNumbers, float mean);
float stdDevF(float numbers[], int totalNumbers, float variance);

int main()
{
	//float avg, age[] = {1};
	int inputTracker;
	printf("If you want to input your data through the console, type 1.\n");  // Add file input later and have the user type 2
	scanf("%d",&inputTracker);
	
	// if user wants console input
	if(inputTracker == 1)
	{	
		// find out how many numbers there are in the data set
		int totalNumbers;
		printf("How many numbers are in your data set?\n");
		scanf("%d", &totalNumbers);
		
		// ask user for the numbers
		printf("List your numbers.\n");
		
		// create a numbers array containing the input
		int number = 0, count = 0;
		float numbers[totalNumbers];
		for(count = 0; count < totalNumbers; count++)	
		{
			scanf("%d", &number); // reading in the number and assigning it to value
			numbers[count] = number;
		}

		// finding the mean, median, mode, range, variance, and standard deviation of the data
		float mean, median, mode, range, variance, stdDev;
		
		// calling the calculation functions
		mean = meanF(numbers, totalNumbers); // Only name of an array is passed as an argument
		median = medianF(numbers, totalNumbers);
		mode = modeF(numbers, totalNumbers);
		range = rangeF(numbers, totalNumbers);
		variance = varianceF(numbers, totalNumbers, mean);
		stdDev = stdDevF(numbers, totalNumbers, variance);
		
		// printing the results
		printf("Mean = %.2f\n", mean);
		printf("Median = %.2f\n", median);
		printf("Mode = %.2f\n", mode);
		printf("Range = %.2f\n", range);
		printf("Variance = %.2f\n", variance);
		printf("Standard Deviation = %.2f\n", stdDev);
	} 
	
	return 0;
}

// function finds the mean of the data set
float meanF(float numbers[], int totalNumbers)
{
	int count;
	float mean, sum = 0.0;
	for (count = 0; count < totalNumbers; count++) 
	{
		sum += numbers[count];
	}
	mean = (sum / totalNumbers);
	return mean;
}

// function finds the median of the data set
float medianF(float numbers[], int totalNumbers)
{
	// sorting the numbers
	int i,j,temp;
	float median;
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
	return median;
}

// function finds the mode of the data set
float modeF(float numbers[], int totalNumbers)
{
	int modeCount, tempCount;
	float mode;
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
	return mode;
}

// function finds the range of the data set
float rangeF(float numbers[], int totalNumbers)
{
	int highest, lowest;
	float range;
	for(int count=0; count < totalNumbers; count++)	
	{
		// set first value as the highest and lowest
    	if(count == 0)
		{
			highest = numbers[count];
			lowest = numbers[count];
		}
		
		// compare current number entered to the highest value
		if(numbers[count] > highest)
		{
			highest = numbers[count];
		}
		
		// compare current number entered to the lowest value
		if(numbers[count] < lowest)
		{
			lowest = numbers[count];
		}	
	}
	range = highest - lowest;
	return range;
}

// function finds the variance of the data set
float varianceF(float numbers[], int totalNumbers, float mean)
{
	int sum1 = 0;
	float variance;
	for (int count=0; count < totalNumbers; count++)
	{
		sum1 += pow((numbers[count] - mean), 2); // subtract number by mean
	}
	variance = sum1 / (totalNumbers-1);
	return variance;
}

// function finds the standard deviation of the data set
float stdDevF(float numbers[], int totalNumbers, float variance)
{
	float stdDev = sqrt(variance);
	return stdDev;
}
