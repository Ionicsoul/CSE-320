/**

Name: Jaiwant Bhushan
Project 06: Multiplying two floating points

**/


#include <stdlib.h>
#include <stdio.h>
#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf (""))
#include "/user/cse320/Projects/project06.support.h"

int main(){				//Main function to test different cases
	
	int a=9.5;
	int b=5.2;
	printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	a=0;
	b=0;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	a=0;
	b=23.4;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));

	a=NAN;
	b=23.4;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	
	a=INFINITY;
	b=NAN;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));

	a=NAN;
	b=INFINITY;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	a=NAN;
	b=2.4;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	a=56.7;
	b=INFINITY;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));
	
	
	a=0;
	b=INFINITY;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));

	a=0;
	b=NAN;
printf("A: %d B: %d Result should be: %f and the calculated is: %f \n", a, b, a*b, mult(a,b));

}