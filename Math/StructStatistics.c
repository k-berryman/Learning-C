/*
   Statistics using Structs
   Kaitlin Berryman 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define noOfRecords 67
#define maxRowSize 1024
#define maxColumnSize 6

// finding the mean, median, mode, range, variance, and standard deviation of the data
float mean = 0.0, median = 0.0, mode = 0.0, range = 0.0, variance = 0.0, stdDev = 0.0;

typedef struct record
{
    char sex;
    float WTsep, WTapr, WTdiff, BMIsep, BMIapr;
} record;

int main()
{
	int rowCount;
	struct record *records = malloc (noOfRecords * sizeof *records); 	// typedef of record this is a dynamic array of records

	getData(records);
	
	// calling the calculation functions
	meanF(records);
	medianF(records);
	modeF(records);
	rangeF(records);
	varianceF(records);
	stdDevF(records);

	// printing the results
	printf("Mean = %.2f\n", mean);
	printf("Median = %.2f\n", median);
	printf("Mode = %.2f\n", mode);
	printf("Range = %.2f\n", range);
	printf("Variance = %.2f\n", variance);
	printf("Standard Deviation = %.2f\n", stdDev);
	
	return 0;
}

void getData(record *records)
{
   	FILE *input; 		// pointer to the file
	char row[maxRowSize]; 	// string array to hold 1 row of data

	char *column;  		// pointer to the column in the row
     	int rowCount = 0;

   	// open file for writing
   	input = fopen ("input.csv", "r");
   	if (input == NULL)
  	{
		printf("Error opening file\n");
       		exit (1);
	}

	// read file contents until EOF
	for(rowCount=0;rowCount<noOfRecords;rowCount++)
	{
		fgets(row, maxRowSize, input);
		//printf("%d ", rowCount);
 		column = strtok(row,",");
                records[rowCount].sex = column[0];
     		// printf("%c ", records[rowCount].sex);
		column = strtok(NULL,",");
                records[rowCount].WTsep = atof(column);
		// printf("%f ", records[rowCount].WTsep);
		column = strtok(NULL,",");
                records[rowCount].WTapr = atof(column);
		// printf("%f ", records[rowCount].WTapr);
                records[rowCount].WTdiff = records[rowCount].WTapr - records[rowCount].WTsep;
		// printf("%f\n", records[rowCount].WTdiff);

		column = strtok(NULL,",");
                records[rowCount].BMIsep = atof(column);

		column = strtok(NULL,",");
                records[rowCount].BMIapr = atof(column);
	}

       //close file
       fclose(input);
}

// function finds the mean of the data set
void meanF(record * records)
{
	int count;
	float  sum = 0.0;
	for (count = 0; count < noOfRecords; count++) 
	{
		sum += records[count].WTdiff;
	}
	mean = sum / noOfRecords;
}

// function finds the median of the data set
void medianF(record * records)
{
	// sorting the numbers
	int i,j,temp;
	for(i=0; i<noOfRecords-1; i++)
	{
		for(j=i+1; j<noOfRecords; j++)
		{
			if(records[j].WTdiff < records[i].WTdiff)
			{	
				// switch places
				temp = records[i].WTdiff;
				records[i].WTdiff = records[j].WTdiff;
				records[j].WTdiff = temp;
			}
		}
	}
	
	// if there's an even amount of numbers, median equals the average of the middle values
	if(noOfRecords%2 == 0)
	{
		median = (records[noOfRecords/2].WTdiff + records[noOfRecords/2 -1].WTdiff) / 2;
	}
	
	// if there's an odd amount of numbers, median equals the middle value
	else
	{
		median = records[noOfRecords/2].WTdiff;
	}
}

// function finds the mode of the data set
void modeF(record * records)
{
	int modeCount, tempCount = 0;

	// loop through the values
	for(int i=0; i < noOfRecords; i++)
	{
		for(int j=i+1; j < noOfRecords; j++)
		{
			// check to see if any values match the current one
			if(records[i].WTdiff == records[j].WTdiff)
			{
				tempCount++;
			}
		}
		
		// check to see if there's a new mode
		if(tempCount > modeCount)
		{
			modeCount = tempCount;
			mode = records[i].WTdiff;
		}	
	}
}

// function finds the range of the data set
void rangeF(record *records)
{
	float highest, lowest;
	for(int count=0; count < noOfRecords; count++)	
	{
		// set first value as the highest and lowest
    	if(count == 0)
		{
			highest = records[count].WTdiff;
			lowest = records[count].WTdiff;
		}
		
		// compare current number entered to the highest value
		if(records[count].WTdiff > highest)
		{
			highest = records[count].WTdiff;
		}
		
		// compare current number entered to the lowest value
		if(records[count].WTdiff < lowest)
		{
			lowest = records[count].WTdiff;
		}	
	}
	range = highest - lowest;
}

// function finds the variance of the data set
void varianceF(record *records)
{
	int sum1 = 0;
	for (int count=0; count < noOfRecords; count++)
	{
		sum1 += pow((records[count].WTdiff - mean), 2); // subtract number by mean
	}
	variance = sum1 / (noOfRecords-1);
}

// function finds the standard deviation of the data set
void stdDevF()
{
	stdDev = sqrt(variance);
}
