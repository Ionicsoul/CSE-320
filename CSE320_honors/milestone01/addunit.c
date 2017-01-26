
#include <Sim.h>

#include "addunit.h"

//******************************************************************************
// FA -- implementation of full adder
//****************************************************************************** 

void FA( SD sd, Signal a, Signal b, Signal c, Signal carry, Signal sum )
{
  Module( (sd,"FA"), (a,b,c), (carry,sum) );

  Sig( ir1, 1 );
  Sig( ir2, 1 );
  Sig( ir3, 1 );

  And( SD(sd,"0a"), b, c, ir1 );
  And( SD(sd,"0a"), a, c, ir2 );
  And( SD(sd,"0a"), a, b, ir3 );
  Or ( SD(sd,"0b"), (ir1, ir2, ir3), carry );
  Xor( SD(sd,"0b"), (a, b, c), sum );
}

//******************************************************************************
// Add Unit -- implementation of 8-bit ripple-carry adder (incomplete)
//****************************************************************************** 

void AddUnit( SD sd, Signal A, Signal B, Signal Out )
{
  Module( (sd,"Add Unit"), (A,B), (Out) );

  Space( SD(sd,"0a") );

  Sig( C, N );

  FA( SD(sd,"1a"), A[31], B[31], C[30], C[31], Out[31] );
  FA( SD(sd,"1a"), A[30], B[30], C[29], C[30], Out[30] );
  FA( SD(sd,"1a"), A[29], B[29], C[28], C[29], Out[29] );
  FA( SD(sd,"1a"), A[28], B[28], C[27], C[28], Out[28] ); 
  FA( SD(sd,"1a"), A[27], B[27], C[26], C[27], Out[27] ); 
  FA( SD(sd,"1a"), A[26], B[26], C[25], C[26], Out[26] );   
  FA( SD(sd,"1a"), A[25], B[25], C[24], C[25], Out[25] ); 
  FA( SD(sd,"1a"), A[24], B[24], C[23], C[24], Out[24] ); 
  FA( SD(sd,"1a"), A[23], B[23], C[22], C[23], Out[23] );
  FA( SD(sd,"1a"), A[22], B[22], C[21], C[22], Out[22] );
  FA( SD(sd,"1a"), A[21], B[21], C[20], C[21], Out[21] );
  FA( SD(sd,"1a"), A[20], B[20], C[19], C[20], Out[20] ); 
  FA( SD(sd,"1a"), A[19], B[19], C[18], C[19], Out[19] ); 
  FA( SD(sd,"1a"), A[18], B[18], C[17], C[18], Out[18] );
  FA( SD(sd,"1a"), A[17], B[17], C[16], C[17], Out[17] );
  FA( SD(sd,"1a"), A[16], B[16], C[15], C[16], Out[16] );
  FA( SD(sd,"1a"), A[15], B[15], C[14], C[15], Out[15] );
  FA( SD(sd,"1a"), A[14], B[14], C[13], C[14], Out[14] );
  FA( SD(sd,"1a"), A[13], B[13], C[12], C[13], Out[13] );
  FA( SD(sd,"1a"), A[12], B[12], C[11], C[12], Out[12] );
  FA( SD(sd,"1a"), A[11], B[11], C[10], C[11], Out[11] );
  FA( SD(sd,"1a"), A[10], B[10], C[9], C[10], Out[10] );
  FA( SD(sd,"1a"), A[9], B[9], C[8], C[9], Out[9] );
  FA( SD(sd,"1a"), A[8], B[8], C[7], C[8], Out[8] );

  FA( SD(sd,"1a"), A[7], B[7], C[6], C[7], Out[7] );
  FA( SD(sd,"1a"), A[6], B[6], C[5], C[6], Out[6] );
  FA( SD(sd,"1a"), A[5], B[5], C[4], C[5], Out[5] );
  FA( SD(sd,"1a"), A[4], B[4], C[3], C[4], Out[4] );
  FA( SD(sd,"1a"), A[3], B[3], C[2], C[3], Out[3] );
  FA( SD(sd,"1a"), A[2], B[2], C[1], C[2], Out[2] );
  FA( SD(sd,"1a"), A[1], B[1], C[0], C[1], Out[1] );
  FA( SD(sd,"1a"), A[0], B[0], Zero, C[0], Out[0] );





  Space( SD(sd,"2a") );
}

