/*
Midterm_alex.c
Design requirements:
a.	Write the program in the function main() only.
b.	Store the temperatures in an array
c.	Move through the array, to read or write, using a pointer.
d.	The temperatures are in Fahrenheit and are of float type.

*/

#include<stdio.h>
int main()
{
    
	float fArray[7];//declares array of floats where temperature data is stored
	float *fPTR;//declares pointer
	float avg;//declares variable that carries value, "avereage", to be printed to user 
			
	printf("\n---7 DAY TEMPERATURE TRACKER---\n");	
	fPTR = &fArray[0];
	printf("Enter Day 1 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 2 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 3 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 4 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 5 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 6 temperature: ");
	scanf("%f", fPTR);
	fPTR++;
	printf("Enter Day 7 temperature: ");
	scanf("%f", fPTR);
	
	printf("\nRESULTS\n");
	printf("-------------------------------\n");
	fPTR = &fArray[0];
	printf("Day 1 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 2 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 3 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 4 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 5 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 6 temperature: %.1f F\n", *fPTR);
	fPTR++;
	printf("Day 7 temperature: %.1f F\n", *fPTR);
	
	avg = ((fArray[0] + fArray[1] + fArray[2] + fArray[3] + fArray[4] + fArray[5] + fArray[6])/7);
	printf("\nThe average temperature is %.1f Degrees Fahrenheit \n", avg);
		
	system("PAUSE");
	return 0;
}
