
#include <Sim.h>

#include "add8.h"

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

  FA( SD(sd,"1a"), A[7], B[7], Zero, C[7], Out[7] );
  FA( SD(sd,"1a"), A[6], B[6], Zero, C[6], Out[6] );
  FA( SD(sd,"1a"), A[5], B[5], Zero, C[5], Out[5] );
  FA( SD(sd,"1a"), A[4], B[4], Zero, C[4], Out[4] );
  FA( SD(sd,"1a"), A[3], B[3], Zero, C[3], Out[3] );
  FA( SD(sd,"1a"), A[2], B[2], Zero, C[2], Out[2] );
  FA( SD(sd,"1a"), A[1], B[1], Zero, C[1], Out[1] );
  FA( SD(sd,"1a"), A[0], B[0], Zero, C[0], Out[0] );

  Space( SD(sd,"2a") );
}

