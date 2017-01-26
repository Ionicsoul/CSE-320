
int is_infinity( double );         /* Test if argument is Infinity */
int is_nan( double );              /* Test if argument is NaN */
int is_zero( double );             /* Test if argument is Zero */
int is_denormal( double );         /* Test if argument is denormal */

void negate( double, double* );    /* Return negation of argument */
void absolute( double, double* );  /* Return absolute value of argument */

void classify( double, char* );    /* Return string with classification */

union dp_item
{
  double drep;
  unsigned long long int irep;
};

