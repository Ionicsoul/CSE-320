#include <stdlib.h>
#include <stdio.h>
#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf (""))
#include "/user/cse320/Projects/project06.support.h"

int main(){
	
	int a=24.5;
	int b=12.2;
	printf("%f \n", mult(a,b));	
	return 0;
}