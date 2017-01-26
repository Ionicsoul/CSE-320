
#include <Sim.h>

#include "/user/cse320/Honors/Milestone04/alu.h"

//******************************************************************************
//
// Test bed for ALU
//
// Allows user to select:
//   operation code (6 bits)
//   upper byte of first operand (8 bits)
//   upper byte of second operand (8 bits)
//
// Displays 32-bit result from the ALU and the 4-bit Integer Condition Codes
//
//****************************************************************************** 

void simnet()
{
  Sig( OP, 6 );    // Operation code
  Sig( A, 4 );     // Upper 4 bits of operand #1
  Sig( a, 4 );     // Lower 4 bits of operand #1
  Sig( B, 4 );     // Upper 4 bits of operand #2
  Sig( b, 4 );     // Lower 4 bits of operand #2
  Sig( R, 32 );    // Result
  Sig( ICC, 4 );   // Integer condition codes

  Space( SD("1a") );
  Space( SD("1a","Opcode:") );
  Switch( SD("1a"), OP, 'o' );

  Space( SD("1a") );
  Space( SD("1a","Operand #1:") );
  Switch( SD("1a"), A, 'A' );
  Space( SD("1a") );
  Switch( SD("1a"), a, 'W' );

  Space( SD("1a") );
  Space( SD("1a","Operand #2:") );
  Switch( SD("1a"), B, 'a' );
  Space( SD("1a") );
  Switch( SD("1a"), b, 'w' );

  Space( SD("1a") );

  ALU( SD("1b-1e"), OP, (A,24*Zero,a), (B,24*Zero,b), R, ICC );

  Space( SD("1f") );
  Space( SD("1f","Output:") );
  Probe( SD("1f"), R );

  Space( SD("1f") );
  Space( SD("1f","Condition Codes:") );
  Probe( SD("1f"), ICC );

  Space( SD("1f") );
}

