
//******************************************************************************
//
// DECODE
//
// Input signals:
//    1 bit  -- timing signal for synchronization (clock pulse)
//    1 bit  -- asserted before second clock pulse, used for initialization
//   32 bits -- machine language instruction
//
// Output signals:
//    1 bit  -- Instruction is valid?
//    1 bit  -- LD instruction?
//    1 bit  -- ST instruction?
//    1 bit  -- Data manipulation instruction?
//    1 bit  -- SETHI instruction?
//    1 bit  -- Branch instruction?
//    1 bit  -- CALL instruction?
//    1 bit  -- JMPL instruction?
//    1 bit  -- Instruction updates NZVC?
//    6 bits -- Opcode for ALU
//
//****************************************************************************** 
 
void DECODE( SD, Signal, Signal, Signal, Signal, Signal, Signal, Signal,
  Signal, Signal, Signal, Signal, Signal, Signal );


//******************************************************************************
//
// ALU
//
// Input signals:
//    1 bit  -- timing signal for synchronization (clock pulse)
//    1 bit  -- asserted before second clock pulse, used for initialization
//    6 bits -- operation code
//   32 bits -- operand #1
//   32 bits -- operand #2
//
// Output signals:
//   32 bits -- result
//    4 bits -- condition codes
//
//****************************************************************************** 
 
void ALU( SD, Signal, Signal, Signal, Signal, Signal, Signal, Signal );

