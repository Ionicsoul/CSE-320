
#include <Sim.h>

#include "shiftunit.h"

//******************************************************************************
// Shift Unit -- implementation of ARC+ Shift Unit
//******************************************************************************

void ShiftUnit( SD sd, Signal Op, Signal Input, Signal Amount, Signal Out )
{
  Module( (sd,"Shift Unit"), (Op,Input,Amount), Out );

  Sig( Op0, 2 );
  Sig( Op1, 2 );
  Sig( Op2, 2 );
  Sig( Op3, 2 );
  Sig( Op4, 2 );

  Sig( Out0, N );
  Sig( Out1, N );
  Sig( Out2, N );
  Sig( Out3, N );

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


  /* Stage 1 -- shift by 2 bits */

  Mux( SD(sd,"3c"), Amount[1],
  (
    /* Port 1 */  ( Op ),
    /* Port 0 */  ( Zero,Zero )
  ), Op1 );

  Mux( SD(sd,"3d-8d"), Op1,
  (
    /* Port 3 */  ( 2*Out0[N-1], Out0.sub(N-1,2) ),
    /* Port 2 */  ( 2*Zero, Out0.sub(N-1,2) ),
    /* Port 1 */  ( Out0.sub(N-3,0), 2*Zero ),
    /* Port 0 */  ( Out0 )
  ), Out1 );


  /* Stage 2 -- shift by 4 bits */

  Mux( SD(sd,"4e"), Amount[2],
  (
    /* Port 1 */  ( Op ),
    /* Port 0 */  ( Zero,Zero )
  ), Op2 );

  Mux( SD(sd,"4g-9g"), Op2,
  (
    /* Port 3 */  ( 4*Out1[N-1], Out1.sub(N-1,4) ),
    /* Port 2 */  ( 4*Zero, Out1.sub(N-1,4) ),
    /* Port 1 */  ( Out1.sub(N-5,0), 4*Zero ),
    /* Port 0 */  ( Out1 )
  ), Out2 );


  /* Stage 3 -- shift by 8 bits */

  Mux( SD(sd, "4h"), Amount[3], 
  (   
    ( Op ), 
    ( Zero, Zero )
  ), Op3 );

  Mux ( SD(sd, "4i-9i"), Op3, 
  (
    (8*Out2[N-1], Out2.sub(N-1,8) ),
    (8*Zero, Out2.sub(N-1,8) ), 
    (Out2.sub(N-9, 0), 8*Zero),
    (Out2)
  ), Out3 );


  /*Stage 4 -- shift by 15 bits */

  Mux( SD(sd, "4g"), Amount[4],
  (
    ( Op ),
    ( Zero, Zero )
  ), Op4 );  

  Mux ( SD(sd, "4k-9k"), Op4,
  (
    (16*Out3[N-1], Out3.sub(N-1,16) ),
    (16*Zero, Out3.sub(N-1,16) ),
    (Out3.sub(N-17, 0), 16*Zero),
    (Out3)
  ), Out );
}  
