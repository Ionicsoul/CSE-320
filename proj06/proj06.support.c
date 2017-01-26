
#include <stdio.h>

union sp_item
{
  float frep;
  unsigned irep;
};

float mult( float x, float y){		//This is the function which takes in two floats and returns the multiplication of them.
	
	
	
	union sp_item x_union;			//Makes unions for the two variables.
	union sp_item y_union;

	x_union.frep = x;		//Assigns the given values to the frep of union.
	y_union.frep = y;

	unsigned int x_exp;			//Makes 6 variables for the storing the different parts of it.
	unsigned int y_exp;

	unsigned int x_sign;	
	unsigned int y_sign;

	unsigned int x_frac;
	unsigned int y_frac;

	
	// x_exp = x_union.irep << 1 >> 24;
	x_exp = y_union.irep >> 23 << 24 >> 24;			//Extracting the exponent.
	// y_exp = y_union.irep << 1 >> 24;
	y_exp = y_union.irep >> 23 << 24 >> 24;

	x_frac = x_union.irep << 9 >> 9;		//Extracting the fraction.
	y_frac = y_union.irep << 9 >> 9;
	
	x_sign = x_union.irep >> 31;			//Extracting the sign.
	y_sign = y_union.irep >> 31;

	unsigned long long x_signi; 
	unsigned long long y_signi;

	x_signi = x_frac | 0x800000;			//Making the significand
	y_signi = y_frac | 0x800000;

	int final_exp;
	final_exp = x_exp + y_exp + 0x7f;		//Finding the true exponent by bias 127.
	
	unsigned long long final_signi; 
	final_signi = x_signi * y_signi;
	final_signi = final_signi & 0x000000000008;
	if(final_signi & 0x800000000000ULL){		
		final_signi = final_signi >> 1;	
		final_exp += 1;
	}

	union sp_item final;
	int final_sign;	
	if(x_sign == y_sign){
		final_sign = 0;	
	}
	else{
		final_sign = 1;	
	}
	
	if(final_signi & 0x00FFFFFFFFFFFF00ULL){
		final_signi + 1;	
	}
	final_sign << 31;			
	final_exp = final_exp  << 23;
	final_signi = final_signi << 18 >> 41;			
	
	final.irep = final_sign | final_exp | final_signi;		//Adding all the parts together.
	return final.frep;
	
}



