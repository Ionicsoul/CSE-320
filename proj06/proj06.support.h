
#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf (""))

union sp_item
{
  float frep;
  unsigned irep;
};

float mult( float, float );

