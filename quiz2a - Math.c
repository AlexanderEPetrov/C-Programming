//Quiz2_alex.c
//AE_Petrov
//BasicCalculator
/*Write a program that will add, subtract,divide, multiply two numbers, 
square root a number and raise a number to any power.*/
//Each arithmetic operation with take parameters by reference
//Each function will print its result from the arithmetic operation.
//numbers are float type.

#include<stdio.h>
#include<math.h>

float addition (float *augend, float *addend) 
{
	float result;
	result = (*augend + *addend);
	printf("The sum is %.2f \n", result);
}

float subtraction (float *s1, float *s2) 
{
	float result;
	result = (*s1 - *s2);
	printf("The difference is %.2f \n", result);
}

float division (float *d1, float *d2)
{
	float result;
	result = (*d1/ *d2 );
	printf("The quotient is %.2f \n", result);
}

float multiplication (float *m1, float *m2)
{
	float result;
	result = (*m1 * (*m2));
	printf("The product is %.2f \n", result);
}

float squareroot (float *r)
{
	float result;
	result = sqrt(*r);
	printf("The root is %.2f \n", result);
}

float exponentiation (float *p1, float *p2)
{
	float result;
	result = pow(*p1, *p2);
	printf("The power is %.2f \n", result);
}

int main()
{ 
	float a1, a2, s1, s2, d1, d2, m1, m2, r, p1, p2, sum, difference, quotient, product, root, power;
	float *augend, *addend, *minuend, *subtrahend, *dividend, *divisor, *multiplicand, *multiplier, *raticand, *base, *exponent;
		
	augend = &a1;
	addend = &a2;
	printf("ADDITION\n");
	printf("Please enter the augend: ");
    scanf("%f", &a1);
    printf("Please enter the addend: ");
    scanf("%f", &a2);
    sum = addition(augend, addend);
    
    minuend = &s1;
	subtrahend = &s2;
    printf("\nSUBTRACTION\n");
	printf("Please enter the minuend: ");
    scanf("%f", &s1);
    printf("Please enter the subtrahend: ");
    scanf("%f", &s2);
    difference = subtraction(minuend, subtrahend);
    
    dividend = &d1;
	divisor = &d2;
    printf("\nDIVISION\n");
	printf("Please enter the dividend: ");
    scanf("%f", &d1);
    printf("Please enter the divisor: ");
    scanf("%f", &d2);
    quotient = division(dividend, divisor);
    
    multiplicand = &m1;
	multiplier = &m2;
    printf("\nMULTIPLICATION\n");
	printf("Please enter the multiplicand: ");
    scanf("%f", &m1);
    printf("Please enter the multiplier: ");
    scanf("%f", &m2);
    product = multiplication(multiplicand, multiplier);
    
    raticand = &r;
    printf("\nSQUAREROOT\n");
	printf("Please enter the raticand: ");
    scanf("%f", &r);
    root = squareroot(raticand);
    
   	base = &p1;
	exponent = &p2;
    printf("\nExponentiation\n");
	printf("Please enter the base: ");
    scanf("%f", &p1);
    printf("Please enter the exponent: ");
    scanf("%f", &p2);
    power = exponentiation(base, exponent);
    
    system("PAUSE");
    return 0;
}





