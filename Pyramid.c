/* Name: Alex_pyramidH2.c */
/* Purpose: Calculates & prints volume and surface area of a right pyramid*/
/* Author: A. E. Petrov */
/* Date: 19 Febuary 2014 */


#include<stdio.h>
#include<math.h>

//float function
float vol(float width, float height);
float surfa(float width, float height);


int main()
{
    //declare variables
    float width, height, v, sa;
    

    //assign values to the variables from the keyboard
    printf("Enter Base Width: ");
    scanf("%f", &width);
    
    printf("Enter Height: ");
    scanf("%f", &height);
	
	    
    //display output to 3 decimal places
    v = vol(width, height);
    printf("\nThe Volume is %.3f\n", v);
    printf("\n");
    
    sa = surfa(width, height);
    printf("\nThe Surface Area is %.3f\n", sa);
    printf("\n"); 
    return 0;
    
}

//Calculations as functions//
float vol(float width, float height)
{
	return (1.0/3)*height*pow(width,2);
}

float surfa(float width, float height)
{
	return ((pow(width,2)) + (width*2.0)*(sqrt((pow(width,2))+((pow(height,2))/4))));
}
