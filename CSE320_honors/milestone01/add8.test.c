
#include <Sim.h>

#include "add8.h"

//******************************************************************************
//
// Test bed for Add Unit
//
// Allows user to select:
//   first operand (N bits)
//   second operand (N bits)
//
// Displays N-bit output of Add Unit
//
//****************************************************************************** 

void simnet()
{
  /** Add Unit data inputs */

  Sig( InA, N );
  Sig( InB, N );

  Space( SD("0a") );
  Space( SD("0a","First Input:") );
  Switch( SD("0a"), InA, 'A' );

  Space( SD("2a") );
  Space( SD("2a","Second Input:") );
  Switch( SD("2a"), InB, 'a' );

  /** Add Unit output */

  Sig( Out, N );

  AddUnit( SD("0b-2e"), InA, InB, Out );

  Space( SD("1f") );
  Space( SD("1f","Output:") );
  Probe( SD("1f"), Out );
}

