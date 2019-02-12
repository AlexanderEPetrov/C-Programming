/*extraassignment_alex.c
Write a program that finds the mean and the standard deviation of a set of numbers.  
Program design requirements:
Store the numbers in an array using a loop and pointer notation
Research how the standard deviation is calculated and apply it to your program.
Don't exceed 6 numbers in your set but no less than 4.*/

#include<stdio.h>
#include<math.h>

float main()
{
	float array[5];
	float *ptr;
	ptr = &array[0];
	int i = 0;
	float max, sum, mean, dif, variance, stdev;
	
	while (i<5)//store numbers in array
	{
		printf("Enter number: ");
		scanf ("%f", &(*ptr));
		i++;
		ptr++;
	}
		
	sum = 0;
	for (i = 0; i< 5; i++)
	{
		sum += array[i]; 
	}
	mean = sum/5;
	printf ("\n\nThe Mean is %.2f\n", mean);
	
	dif = 0;
	for (i = 0; i< 5; i++)
	{
		dif += pow((mean - array[i]), 2);
	}
	variance = (dif/5);//This is the method for "population" standard deviation, where n = 5.
	stdev = sqrt(variance);
	printf("\nThe Standard deviation is: %.2f\n\n", stdev);
	
	system("PAUSE");
	return 0;
}

//Source: http://www.mathsisfun.com/data/standard-deviation.html
