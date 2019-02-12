//sphereV1.c
//AP
//*calculate the cross section area, the surface area, circumference and the volume of a sphere*//
//*program requirements: each calculation is done in a function formula: a = (cross section) s= surface, c = circumference, v = volume, all fns rill return result to main()no global variables*//


#include<stdio.h>
#include<math.h>

int main()
{
    //declare variables
    float rad, pi, vol, a, s, c ;
    
    //assign variable pi
    pi = 3.1415;

    //assign a value to the variable from the keyboard
    printf("Enter Radius: ");
    scanf("%f", &rad);
	
	//calculate volume of sphere
    vol=(4.0/3)*pi*pow(rad,3);
    
    //calculate cross section
    a = (rad)* 2;  
    
    //calculate surface area
    s = 4*pi*pow(rad,2);
    
    //calculate circumference
    c = 2*pi*(rad);
    
    //display output to 3 decimal places
    printf("\nThe Volume is %.3f\n", vol);
    printf("\n");
    printf("\nThe Cross section is %.3f\n", a);
    printf("\n");
    printf("\nThe Surface area is %.3f\n", s);
    printf("\n");
    printf("\nThe Circumference is %.3f\n", c);
    printf("\n");
    system("pause");
    return 0;
}
