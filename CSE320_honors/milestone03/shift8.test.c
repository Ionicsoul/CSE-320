
#include <Sim.h>

#include "shift8.h"

//******************************************************************************
//
// Test bed for Shift Unit
//
// Allows user to select:
//   shift operation (2 bits)
//   value to be shifted (N bits)
//   shift amount (3 bits)
//
// Displays N-bit output of Shift Unit
//
//****************************************************************************** 

void simnet()
{
  Sig( op, 2 );    // Shift operation
  Sig( in, N );    // Operand to be shifted
  Sig( amt, 3 );   // Shift amount
  Sig( out, N );   // Output of Shift Unit

  Space( SD("1a") );
  Space( SD("1a","Shift Op:") );

  Switch( SD("1a"), op, 'o' );

  Space( SD("1a") );
  Space( SD("1a","Input:") );

  Switch( SD("1a"), in, '1' );

  Space( SD("1a") );
  Space( SD("1a","Shift Amount:") );

  Switch( SD("1a"), amt, 'a' );

  Space( SD("1a") );

  ShiftUnit( SD("1b-1e"), op, in, amt, out );

  Space( SD("1f") );
  Space( SD("1f","Output:") );

  Probe( SD("1f"), out );
}

