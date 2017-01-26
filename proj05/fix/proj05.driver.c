#include <stdio.h>


int decode( int, const char[], char[]);


int main() {			//Main function of the project for test conversions.

	int A = 127;
	int B = -6;
	char C[80];


	decode( A, "dec", &C[0] );
	decode( A, "hex", &C[0] );
	decode( A, "bin", &C[0] );
	decode( B, "dec", &C[0] );
	decode( B, "oct", &C[0] );
	decode( B, "bin", &C[0] );
	return 0;
}


