
#include <Sim.h>

#include "/user/cse320/Honors/Milestone05/decode.h"

//******************************************************************************
//
// Test bed for Decode Unit
//
// Allows user to select:
//   bits 31:30
//   bits 24:19
//
// Displays nine 1-bit signals and 6-bit opcode
//
//****************************************************************************** 

void simnet()
{
  Sig( OP, 2 );       // Bits 31:30 of the instruction
  Sig( OP3, 6 );      // Bits 24:19 of the instruction

  Sig( LD, 1 );       // LD instruction?
  Sig( ST, 1 );       // ST instruction?
  Sig( Data, 1 );     // Data manipulation instruction?
  Sig( SETHI, 1 );    // SETHI instruction?
  Sig( Branch, 1 );   // Branch instruction?
  Sig( CALL, 1 );     // CALL instruction?
  Sig( JMPL, 1 );     // JMPL instruction?
  Sig( Invalid, 1 );  // Instruction is invalid?
  Sig( Update, 1 );   // Instruction updates NZVC?
  Sig( Opcode, 6 );   // Opcode for ALU

  Space( SD("1a") );
  Space( SD("1a","Bits 31:30:") );
  Switch( SD("1a"), OP, 'a' );

  Space( SD("1a") );
  Space( SD("1a","Bits 24:19") );
  Switch( SD("1a"), OP3, 'c' );
  Space( SD("1a") );

  Space( SD("1a") );

  DecodeUnit( SD("1b-1e"), (OP,5*Zero,OP3,19*Zero), 
    LD, ST, Data, SETHI, Branch, CALL, JMPL, Invalid, Update, Opcode );

  Space( SD("1f") );
  Space( SD("1f","Control Signals:") );
  Probe( SD("1f"), LD );
  Probe( SD("1f"), ST );
  Probe( SD("1f"), Data );
  Probe( SD("1f"), SETHI );
  Probe( SD("1f"), Branch );
  Probe( SD("1f"), CALL );
  Probe( SD("1f"), JMPL );
  Probe( SD("1f"), Invalid );
  Probe( SD("1f"), Update );

  Space( SD("1f") );
  Space( SD("1f","ALU Opcode:") );
  Probe( SD("1f"), Opcode );

  Space( SD("1f") );
}

