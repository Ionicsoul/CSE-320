
#include <Sim.h>

#include "math8.h"

//******************************************************************************
// FA -- implementation of full adder
//****************************************************************************** 

void FA( SD sd, Signal a, Signal b, Signal c, Signal carry, Signal sum )
{
  Module( (sd,"FA"), (a,b,c), (carry,sum) );

  Sig( ir1, 1 );
  Sig( ir2, 1 );
  Sig( ir3, 1 );

  And( SD(sd,"1a"), b, c, ir1 );
  And( SD(sd,"1a"), a, c, ir2 );
  And( SD(sd,"1a"), a, b, ir3 );
  Or ( SD(sd,"1b"), (ir1, ir2, ir3), carry );
  Xor( SD(sd,"1b"), (a, b, c), sum );
}

//******************************************************************************
// Math Unit -- implementation of ARC+ Math Unit
//****************************************************************************** 

void MathUnit( SD sd, Signal Op, Signal A, Signal B, Signal Out, Signal Code )
{
  Module( (sd,"Math Unit"), (Op,A,B), (Out,Code) );

  Space( SD(sd,"0a") );


  // ** Invert the second operand when Op[2] is asserted **

  Sig( OperandB, N );

  // INCOMPLETE

  for (int i=N-1; i>=0; i--)
  {
    Or( SD(sd,"4b"), B[i], Zero, OperandB[i] );
  }


  // ** Addition and Subtration **

  Space( SD(sd,"4d") );

  Sig( C, N );
  Sig( ADDout, N );

  for (int i=N-1; i>=1; i--)
  {
    FA( SD(sd,"4d"), A[i], OperandB[i], C[i-1],  C[i], ADDout[i] );
  }
  FA( SD(sd,"4d"), A[0], OperandB[0], Op[2], C[0], ADDout[0] );


  // ** Bitwise AND **

  Space( SD(sd,"3d") );

  Sig( ANDout, N );

  // INCOMPLETE


  // ** Bitwise OR **

  Space( SD(sd,"2d") );

  Sig( ORout, N );

  // INCOMPLETE


  // ** Bitwise XOR **

  Space( SD(sd,"1d") );

  Sig( XORout, N );

  for (int i=N-1; i>=0; i--)
  {
    Xor( SD(sd,"1d"), A[i], OperandB[i], XORout[i] );
  }


  // Select the appropriate intermediate output as the overall output

  Mux( SD(sd,"0e-5e"), Op.sub(1,0), 
  (
    /* Port 3 */  (XORout),
    /* Port 2 */  (ORout),
    /* Port 1 */  (ANDout),
    /* Port 0 */  (ADDout)
  ), Out );


  // INCOMPLETE

  // Create "0000" as the value for the condition codes (temporary)

  Or( SD(sd,"6e"), (Zero,Zero,Zero,Zero), (Zero,Zero,Zero,Zero), Code );
}

