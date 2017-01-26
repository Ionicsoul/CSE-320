#include "/user/cse320/Projects/project09.support.h"

#include <stdio.h>


int main()
{	
	union dp_item inf;
	union dp_item zero;
	union dp_item denormal;
	union dp_item nan;
	
	
	inf.irep       = 0x7ff0000000000000ULL;
	zero.irep	   = 0x0000000000000000ULL;
	nan.irep       = 0x7ff0000000000001ULL;
	denormal.irep  = 0x0000000000000001ULL;
	
	double negate_num = 6.5;
	double absolute_num = -5.4;
	double negate_num_again = -4.56;
	double absolute_num_again = 43.4;
	
	int a = is_denormal(denormal.drep);			
	printf("Is it denormal: %d \n", a);			//Yes

	int b = is_infinity(inf.drep);
	printf("Is it infinity: %d \n", b);			//Yes
	
	int c = is_nan(nan.drep);
	printf("Is it NaN: %d \n", c);				//Yes
	
	int d = is_zero(zero.drep);
	printf("Is it zero: %d \n\n", d);				//Yes
	
	double negate_res;
	negate(negate_num, &negate_res);
	printf("The negative of the number %f is: %f \n", negate_num, negate_res);

	
	double absolute_res;
	absolute(absolute_num, &absolute_res);
	printf("The absolute of the number %f is: %f \n\n", absolute_num, absolute_res);
	
	double negate_res_again;
	negate(negate_num_again, &negate_res_again);
	printf("The negative of the number %f is: %f \n", negate_num_again, negate_res_again);

	
	double absolute_res_again;
	absolute(absolute_num_again, &absolute_res_again);
	printf("The absolute of the number %f is: %f \n", absolute_num_again, absolute_res_again);
	
	char p;
	printf("\nThe classification is: ");	//Zero
	classify(zero.drep, &p);				
	printf("\n");
	
	char q;
	printf("The classification is: ");		//Infinity
	classify(inf.drep, &q);
	printf("\n");
	
	char r;
	printf("The classification is: ");		//Not a number
	classify(nan.drep, &r);
	printf("\n");
	
	char s;
	printf("The classification is: ");		//Denormal number
	classify(denormal.drep, &s);
	printf("\n");
	
	char t;
	printf("The classification is: ");		//Normal number
	classify(negate_num, &t);
	printf("\n");
	
	return 0;

}		

