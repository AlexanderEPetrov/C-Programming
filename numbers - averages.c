/*Quiz1_alex.c
Author: A E Petrov
3 June 2014
Write a program that uses a function other than main to calculate the average of 
four float numbers.
Pass the four numbers as parameters to the function and return a float as the result.
Enter the four numbers in main, call the average function, then display the result.*/

#include<stdio.h>
 
float numbers (float a, float b, float c, float d) //function to calculate the average
{
	float result;
	result = ((a + b + c + d)/4);
	return result;	
}

int main()
{
    float a, b, c, d, avg;
    
    printf("Enter the first number: ");
    scanf("%f", &a);
    printf("\nEnter the second number: ");
    scanf("%f", &b);
    printf("\nEnter the third number: ");
    scanf("%f", &c);
    printf("\nEnter the fourth number: ");
    scanf("%f", &d);
    
    avg = numbers(a, b, c, d);//function called, four numbers passed as parameters
    
    printf("\n\nThe average of these four numbers is %.2f \n", avg);//result displayed 
    
    system("PAUSE");
    return 0;
}
