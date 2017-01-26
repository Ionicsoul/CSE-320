
#include <Sim.h>

#include "math8.h"

//******************************************************************************
//
// Test bed for Math Unit
//
// Allows user to select:
//   operation (3 bits)
//   first operand (N bits)
//   second operand (N bits)
//
// Displays N-bit output of Math Unit and 4-bit Condition Codes
//
//****************************************************************************** 

void simnet()
{
  /** Math Unit control signals */

  Sig( Op, 3 );

  Space( SD("0a") );
  Space( SD("0a", "Control Signals:") );
  Switch( SD("0a"), Op, 'n');

  /** Math Unit data inputs */

  Sig( InA, N );
  Sig( InB, N );

  Space( SD("1a") );
  Space( SD("1a","First Input:") );
  Switch( SD("1a"), InA, 'A' );

  Space( SD("2a") );
  Space( SD("2a","Second Input:") );
  Switch( SD("2a"), InB, 'a' );

  Space( SD("3a") );

  /** Math Unit outputs */

  Sig( Out, N );
  Sig( Code, 4 );

  MathUnit( SD("0b-3e"), Op, InA, InB, Out, Code );

  Space( SD("0f") );

  Space( SD("1f") );
  Space( SD("1f","Output:") );
  Probe( SD("1f"), Out );

  Space( SD("2f") );
  Space( SD("2f","Condition Codes:") );
  Probe( SD("2f"), Code );

  Space( SD("3f") );
}

