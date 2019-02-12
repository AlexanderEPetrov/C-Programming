/*Cone_alex.c
Author: A E Petrov

Calculate the volume of a right cone. And, have the program also calculate the vertical cross section area of the cone from the center.
In addition find the area of the base of the cone.
Design Requirements:
        Write a function for each calculation
		Have the functions accept the needed paparameters and have them return the result back to main()
		As the user to enter the radius of the base and the hight of the cone in main()
		Display the results in main().
*/

#include<stdio.h>
#include<math.h>

float isosarea(float r, float h)
{
      float result;
      result = (r * h);
      return result;
}

float basearea(float r)
{
	float result;
	result = (3.14 * pow(r, 2));
	return result;
}

float conearea(float r, float h)
{
	float result;
	result = ((3.14 * h * pow(r, 2))/3);
	return result;	
}


int main()
{
    float r1, h2, varea, barea, vol;
    
    printf("Enter the radius of the right triangle: ");
    scanf("%f", &r1);
    printf("\nEnter the height of the right triangle: ");
    scanf("%f", &h2);
    
    varea = isosarea(r1, h2);
    barea = basearea(r1);
    vol = conearea(r1, h2);
    
    printf("\n\nThe area of the isosceles triangle is %.2f square areas\n", varea);
    printf("\nThe area of the base circle is %.2f square areas\n", barea);
    printf("\nThe volume of the cone is %.2f cubic volumes \n\n", vol);
    
    
    system("PAUSE");
    return 0;
}
