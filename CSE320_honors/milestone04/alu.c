#include <Sim.h>
#include "/user/cse320/Honors/Milestone04/alu.h"

// insert contents of "mathunit.h"

const int N = 32;

void MathUnit( SD, Signal, Signal, Signal, Signal, Signal );

// insert contents of "mathunit.c"

void FA( SD sd, Signal a, Signal b, Signal c, Signal carry, Signal sum )
{
  Module( (sd,"FA"), (a,b,c), (carry,sum) );

  Sig( ir1, 1 );
  Sig( ir2, 1 );
  Sig( ir3, 1 );

  And( SD(sd,"2b"), b, c, ir1 );
  And( SD(sd,"2b"), a, c, ir2 );
  And( SD(sd,"2b"), a, b, ir3 );
  Or ( SD(sd,"2c"), (ir1, ir2, ir3), carry );
  Xor( SD(sd,"2c"), (a, b, c), sum );
}



//******************************************************************************
// Math Unit -- implementation of ARC+ Math Unit
//****************************************************************************** 

void MathUnit( SD sd, Signal Op, Signal A, Signal B, Signal Out, Signal Code )
{
  Module( (sd,"Math Unit"), (Op,A,B), (Out,Code) );
  Space( SD(sd,"1a") );

  // ** Invert the second operand when Op[2] is asserted **
  Sig( OperandB, N );
  
  // Complete this
  for (int i=N-1; i>=0; i--)
  {
   Xor( SD(sd,"5c"), B[i], Op[2], OperandB[i]);
  }

  // ** Addition and Subtration **
  Space( SD(sd,"5e") );

  Sig( C, N );
  Sig( ADDout, N );

  for (int i=N-1; i>=1; i--)
  {
    FA( SD(sd,"5e"), A[i], OperandB[i], C[i-1],  C[i], ADDout[i] );
  }
  FA( SD(sd,"5e"), A[0], OperandB[0], Op[2], C[0], ADDout[0] );


  // ** Bitwise AND **
  Space( SD(sd,"4e") );

  Sig( ANDout, N );

  // Complete this  
  for (int i=N-1; i>=0; i--) {
    And( SD(sd,"4e"), A[i], OperandB[i], ANDout[i]);
  }

  // ** Bitwise OR **
  Space( SD(sd,"3e") );
  Sig( ORout, N );
  
  // Complete this
  for (int i=N-1; i>=0; i--) {
    Or( SD(sd,"3e"), A[i], OperandB[i], ORout[i]);
  }


  // ** Bitwise XOR **
  Space( SD(sd,"2e") );

  Sig( XORout, N );

  for (int i=N-1; i>=0; i--)
  {
    Xor( SD(sd,"2e"), A[i], OperandB[i], XORout[i] );
  }


  // Select the appropriate intermediate output as the overall output
  Mux( SD(sd,"1f-6f"), Op.sub(1,0), 
  (
    /* 3 */  (XORout),
    /* 2 */  (ORout),
    /* 1 */  (ANDout),
    /* 0 */  (ADDout)
  ), Out );

  
  Signal Z;
  Nor( SD(sd, "1b"), Out, Z);

  
  Signal Addition;
  Signal not_temp;

  Signal C_fin;
  Signal Arithmetic;
  Signal And_temp;
  
 
  
  Or( SD(sd, "1b"), (Op[0], Op[1], Op[2]), not_temp);
  Not( SD(sd, "1b"), not_temp, Addition);
  
  Signal Subtraction;
  Signal Zero_Bits;
  Signal not_tem;
  
  Or( SD(sd, "1b"), (Op[1], Op[0]), not_tem);
  Not( SD(sd, "1b"), not_tem, Zero_Bits);
  And( SD(sd, "1b"), Zero_Bits, Op[2], Subtraction);
  
  Or( SD(sd, "1b"), Addition, Subtraction, Arithmetic);
  And( SD(sd, "1b"), (C[31], Arithmetic), And_temp);
  
  Xor( SD(sd, "1b"), And_temp, Subtraction, C_fin);
  
  Signal V;
  
  
  Signal V_log;
  Xor( SD(sd,"2a"), C[30], C[31], V_log);
  And( SD(sd,"2a"), (V_log, Arithmetic), V);
  

  // Create "0000" as the value for the condition codes (temporary)

  Or( SD(sd,"6e"), (Out[31],Z,V,C_fin), (Zero,Zero,Zero,Zero), Code );
}

// insert contents of "shiftunit.h"

void ShiftUnit( SD, Signal, Signal, Signal, Signal );

// insert contents of "shiftunit.c"

void ShiftUnit( SD sd, Signal Op, Signal Input, Signal Amount, Signal Out )
{
  Module( (sd,"Shift Unit"), (Op,Input,Amount), Out );

  Sig( Out0, N );
  Sig( Out1, N );
  Sig( Out2, N );
  Sig( Out3, N );
  
  Sig( Op0, 2);
  Sig( Op1, 2);
  Sig( Op2, 2);
  Sig( Op3, 2);
  Sig( Op4, 2);
  
 

  /* Stage 0 -- shift by 1 bit */

  Mux( SD(sd,"4b"), Amount[0],
  (
    /* Port 1 */  ( Op ),
    /* Port 0 */  ( Zero,Zero )
  ), Op0 );

  Mux( SD(sd,"4c-9c"), Op0,
  (
    /* Port 3 */  ( 1*Input[N-1], Input.sub(N-1,1) ),
    /* Port 2 */  ( 1*Zero, Input.sub(N-1,1) ),
    /* Port 1 */  ( Input.sub(N-2,0), 1*Zero ),
    /* Port 0 */  ( Input )
  ), Out0 );


 
  /* Stage 2 -- shift by 4 bits */

  Mux( SD(sd,"4f"), Amount[2],
  (
    /* Port 1 */  ( Op ),
    /* Port 0 */  ( Zero,Zero )
  ), Op2 );

  Mux( SD(sd,"3g-9g"), Op2,
  (
    /* Port 3 */  ( 4*Out1[N-1], Out1.sub(N-1,4) ),
    /* Port 2 */  ( 4*Zero, Out1.sub(N-1,4) ),
    /* Port 1 */  ( Out1.sub(N-5,0), 4*Zero ),
    /* Port 0 */  ( Out1 )
  ), Out2 );

  
  /* Stage 1 -- shift by 2 bits */

  Mux( SD(sd,"4d"), Amount[1],
  (
    /* Port 1 */  ( Op ),
    /* Port 0 */  ( Zero,Zero )
  ), Op1 );

  Mux( SD(sd,"4e-9e"), Op1,
  (
    /* Port 3 */  ( 2*Out0[N-1], Out0.sub(N-1,2) ),
    /* Port 2 */  ( 2*Zero, Out0.sub(N-1,2) ),
    /* Port 1 */  ( Out0.sub(N-3,0), 2*Zero ),
    /* Port 0 */  ( Out0 )
  ), Out1 );
  
  
  /*Stage 4 -- shift by 15 bits */

  Mux( SD(sd, "3i"), Amount[4],
  (
    ( Op ),
    ( Zero, Zero )
  ), Op4 );  

  Mux ( SD(sd, "3j-8j"), Op4,
  (
    (16*Out3[N-1], Out3.sub(N-1,16) ),
    (16*Zero, Out3.sub(N-1,16) ),
    (Out3.sub(N-17, 0), 16*Zero),
    (Out3)
  ), Out );

  /* Stage 3 -- shift by 8 bits */

  Mux( SD(sd, "3g"), Amount[3], 
  (   
    ( Op ), 
    ( Zero, Zero )
  ), Op3 );

  Mux ( SD(sd, "3h-8h"), Op3, 
  (
    (8*Out2[N-1], Out2.sub(N-1,8) ),
    (8*Zero, Out2.sub(N-1,8) ), 
    (Out2.sub(N-9, 0), 8*Zero),
    (Out2)
  ), Out3 );
  
}  

//******************************************************************************
// ALU -- implementation of ARC+ ALU
//******************************************************************************

void ALU( SD sd, Signal OP, Signal A, Signal B, Signal R, Signal ICC )
{
  Module( (sd,"ALU"), (OP,A,B), (R,ICC) );
 
  Sig( OutShift, N);
  Sig( OutMath, N);

  ShiftUnit( SD(sd,"1b"), OP.sub(1,0), A, B, OutShift);
  MathUnit( SD(sd, "1a"), OP.sub(2,0), A, B, OutMath, ICC);
  
  Signal(Output);
  And(SD(sd, "4j"), OP.sub(5,5), OP.sub(2,2), Output);
  
  Mux( SD(sd, "3j"), Output,
   (
    (OutShift),
    (OutMath)
   ), R ); 
} 
