/*
Declare an array of characters, an array of integers, and an array of floats.
Use pointer notation to:
1. Fill the arrays with data entered by user
2. display the address of each array member
3. display the data that was stored in the arrays
*/

#include<stdio.h>
int main()
{
    char cArray [3];//declares an array of characters 
    char *cPTR;
	int intArray[2];//declares array of integers
	int *intPTR;
	float fArray[2];//declares array of floats
	float *fPTR;
	
	/*
	printf("CHARACTER ARRAY\n");
	cPTR = &cArray[0];
	printf("Enter the first character: ");
	scanf("%s", cPTR);
	printf("Memory location of first value: %d\n", cPTR);//display the address
	printf("First value in char array: %c\n", *cPTR);    //display the data	
	cPTR++;
	printf("Enter the second character: ");
	scanf("%s", cPTR);
	printf("Memory location of second value: %d\n", cPTR);//display the address
	printf("Second value in char array: %c\n", *cPTR);    //display the data
	cPTR++;
	printf("Enter the Third character: ");
	scanf("%s", cPTR);
	printf("Memory location of third value: %d\n", cPTR);//display the address
	printf("Third value in char array: %c\n", *cPTR);   //display the data
	
	printf("\nINTEGER ARRAY\n");
	intPTR = &intArray[0];
	printf("Enter the first integer: ");
	scanf("%d", intPTR);
	printf("Memory location of first value: %d\n", intPTR);//display the address
	printf("First value in int array: %d\n", *intPTR);	   //display the data
	intPTR++;
	printf("Enter the second integer: ");
	scanf("%d", intPTR);
	printf("Memory location of second value: %d\n", intPTR);//display the address
	printf("Second value in int array: %d\n", *intPTR);     //display the data
	
	*/
	float sum;		
	printf("\nFLOAT ARRAY\n");	
	fPTR = &fArray[0];
	printf("Enter the first float number: ");
	scanf("%f", fPTR);
	printf("Memory location of first value: %d\n", fPTR);//display the address
	printf("First value in float array: %f\n", *fPTR);	 //display the data
	fPTR++;
	printf("Enter the second float number: ");
	scanf("%f", fPTR);
	printf("Memory location of second value: %d\n", fPTR);//display the address
	printf("Second value in float array: %f\n", *fPTR);   //display the data
	
	sum = (fArray[0] + fArray[1]);
	printf("the sum is %f\n", sum);
	
		
	system("PAUSE");
	return 0;
}
