#include <Sim.h>

#include "mathunit.h"

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
   Xor( SD(sd,"4b"), B[i], Op[2], OperandB[i]);
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
  for (int i=N-1; i>=0; i--) {
    And( SD(sd,"3d"), A[i], OperandB[i], ANDout[i]);
  }
  // ** Bitwise OR **
  Space( SD(sd,"2d") );
  Sig( ORout, N );
  // INCOMPLETE
  for (int i=N-1; i>=0; i--) {
    Or( SD(sd,"2d"), A[i], OperandB[i], ORout[i]);
  }
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

  
  // Copy of carry out
  // Copy of carry out is C[31]
  Signal Z;
  Nor( SD(sd, "0a"), Out, Z);


  Signal C_fin;
  Signal Arithmetic;
  Signal And_temp;
  
  // Doing addition
  Signal Addition;
  Signal not_temp;
  
  Or( SD(sd, "0a"), (Op[0], Op[1], Op[2]), not_temp);
  Not( SD(sd, "0a"), not_temp, Addition);
  

  Signal Subtraction;
  Signal Zero_Bits;
  Signal not_tem;
  
  Or( SD(sd, "0a"), (Op[1], Op[0]), not_tem);
  Not( SD(sd, "0a"), not_tem, Zero_Bits);
  And( SD(sd, "0a"), Zero_Bits, Op[2], Subtraction);
  
  Or( SD(sd, "0a"), Addition, Subtraction, Arithmetic);
  And( SD(sd, "0a"), (C[31], Arithmetic), And_temp);
  
  Xor( SD(sd, "0a"), And_temp, Subtraction, C_fin);
  
 
  Signal V;
  
  Signal V_log;
  Xor( SD(sd,"2a"), C[30], C[31], V_log);
  And( SD(sd,"2a"), (V_log, Arithmetic), V);
  

  // Creates "0000"

  Or( SD(sd,"6e"), (Out[31],Z,V,C_fin), (Zero,Zero,Zero,Zero), Code );
}