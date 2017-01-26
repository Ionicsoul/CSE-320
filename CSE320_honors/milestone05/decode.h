
//******************************************************************************
//
// DecodeUnit
//
// Input signals:
//   32 bits -- machine language instruction
//
// Output signals:
//    1 bit  -- LD instruction?
//    1 bit  -- ST instruction?
//    1 bit  -- Data manipulation instruction?
//    1 bit  -- SETHI instruction?
//    1 bit  -- Branch instruction?
//    1 bit  -- CALL instruction?
//    1 bit  -- JMPL instruction?
//    1 bit  -- Instruction is invalid?
//    1 bit  -- Instruction updates NZVC?
//    6 bits -- Opcode for ALU
//
//****************************************************************************** 
 
void DecodeUnit( SD, Signal, Signal, Signal, Signal, Signal, Signal, Signal,
  Signal, Signal, Signal, Signal );

