//Twofunctions_Alex.c//
//Alexander E Petrov//
//24 May 2014//
/*Program requirements: Write program with two funstions, one that adds 
three numbers, the other function subtracts a number from another*/

#include<stdio.h>

float add_numbers(float, float, float);
float subtract_anumber(float, float); //prototypes

int main()
{
	float sum;
	float a1, a2, a3;
	float difference;
	float s1, s2;
	
	sum = add_numbers(a1, a2, a3);
	printf ("\nSUM =  %.2f\n\n\n\n", sum);
	
	difference = subtract_anumber(s1, s2); 
	printf ("\nDIFFERENCE =  %.2f\n\n\n\ns", difference);
	
	system("PAUSE");
	return 0;
}

float add_numbers(float a1, float a2, float a3) //define the function for calculating the sum
{
	printf("ADDITION");
	printf("\nPlease enter first number: ");
	scanf("%f", &a1);
	printf("\nPlease enter second number: "); 
	scanf("%f", &a2);
	printf("\nPlease enter third number: ");
	scanf("%f", &a3);
	
	return (a1+a2+a3);
} 

float subtract_anumber(float s1, float s2) //define the function for calculating the difference
{
	printf("SUBTRACTION");
	printf("\nPlease enter the minuend: ");
	scanf("%f", &s1);
	printf("\nPlease enter the subtrahend: "); 
	scanf("%f", &s2);
	
	return (s1 - s2);
}
