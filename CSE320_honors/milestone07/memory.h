
//******************************************************************************
//
// IMEM
//
// Reads contents of file "testcases", stores in instruction memory (cache)
//
// Input signals:
//   14 bits -- address from which to fetch instruction (bits 16:2 of NPC)
//
// Output signals:
//   32 bits -- instruction
//
//****************************************************************************** 
 
void IMEM( SD sd, Signal, Signal );


//******************************************************************************
//
// DMEM
//
// Input signals:
//    1 bit  -- used for synchronization (clock pulse)
//    1 bit  -- asserted when instruction reads from Data Memory
//    1 bit  -- asserted when instruction writes into Data Memory
//   32 bits -- effective address
//   32 bits -- operand to be written (ST instructions)
//
// Output signal:
//   32 bits -- operand to be read (LD instructions)
// 
//****************************************************************************** 

void DMEM( SD, Signal, Signal, Signal, Signal, Signal, Signal );

