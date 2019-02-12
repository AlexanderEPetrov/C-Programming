/*Assignment3_alex.c
Author: A E Petrov
8 June 2014
Redo Quiz 1 using pointers. Pass the four values to find their average by REFERENCE!
Ask for the numbers in main()
Pass by reference from main to the function that averages the number.
Have the function return a value back to main to print the result.*/

#include<stdio.h>
 
float numbers (float *a, float *b, float *c, float *d) //function to calculate the average
{
	float result;
	result = ((*a + *b + *c + *d)/4);
	return result;	
}

int main()
{
    float a, b, c, d, avg;
    float *pa, *pb, *pc, *pd;
    
    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;
    
    printf("Enter the first number: ");
    scanf("%f", &a);
    printf("\nEnter the second number: ");
    scanf("%f", &b);
    printf("\nEnter the third number: ");
    scanf("%f", &c);
    printf("\nEnter the fourth number: ");
    scanf("%f", &d);
    
    avg = numbers(pa, pb, pc, pd);//function called
    printf("\n\nThe average of these four numbers is %.2f \n", avg);//result displayed 
    
    system("PAUSE");
    return 0;
}
