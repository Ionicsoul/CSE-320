
//******************************************************************************
//
// Register File
//
// Input signals:
//    1 bit  -- timing signal for synchronization (clock pulse)
//    1 bit  -- asserted before second clock pulse, used for initialization
//    5 bits -- register number A (register to be read)
//    5 bits -- register number B (register to be read)
//    5 bits -- register number C (register to be read and written)
//    1 bit  -- control signal (update the register file when asserted)
//   32 bits -- value to be written into Reg[C]
//
// Output signals:
//   32 bits -- contents of Reg[A]
//   32 bits -- contents of Reg[B]
//   32 bits -- contents of Reg[C]
//
//****************************************************************************** 
 
void REG( SD, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal,
  Signal, Signal );


//******************************************************************************
//
// NPC, PR and IR
//
// Input signals:
//    1 bit  -- timing signal for synchronization (clock pulse)
//    1 bit  -- asserted before second clock pulse, used for initialization
//    1 bit  -- enable signal (register written when asserted)
//   32 bits -- value to be written into register
//
// Output signals:
//   32 bits -- contents of register
//
//******************************************************************************

void NPC( SD, Signal, Signal, Signal, Signal, Signal );
void  PC( SD, Signal, Signal, Signal, Signal, Signal );
void  IR( SD, Signal, Signal, Signal, Signal, Signal );


//******************************************************************************
//
// NZVC
//
// Input signals:
//    1 bit  -- timing signal for synchronization (clock pulse)
//    1 bit  -- asserted before second clock pulse, used for initialization
//    1 bit  -- enable signal (register written when asserted)
//    4 bits -- value to be written into register
//
// Output signals:
//    4 bits -- contents of register
//
//******************************************************************************
  
void NZVC( SD, Signal, Signal, Signal, Signal, Signal );

