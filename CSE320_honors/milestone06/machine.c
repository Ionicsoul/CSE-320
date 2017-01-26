#include <Sim.h>
#include "/user/cse320/Honors/Milestone06/clock.h"
#include "/user/cse320/Honors/Milestone06/memory.h"
#include "/user/cse320/Honors/Milestone06/registers.h"
#include "/user/cse320/Honors/Milestone06/components.h"
//******************************************************************************
//
// ARC+ machine
//
//******************************************************************************
void simnet()
{
  Sig( cp, 1 );
  Sig( run, 1 );
  Sig( npc, 32 );
  Sig( pc, 32 );
  Sig( ir, 32 );
  Sig( npc_plus4, 32 );
  Sig( imem_out, 32 );
  Sig( nzvc, 4 );
  Sigv( four, 32, 0x00000004 );
  Sig( RegAOut, 32);
  Sig( RegBOut, 32);
  Sig( RegCOut, 32);
  Sig( Valid, 1);
  Sig( Ld, 1);
  Sig( St, 1);
  Sig( Data, 1);
  Sig( Sethi, 1);
  Sig( Branch, 1);
  Sig( Call, 1);
  Sig( Jmpl, 1);
  Sig( Nzvc, 1);
  Sig( Opcode, 6);
  Sig( Operand1, 32);
  Sig( Operand2, 32);
  Sig( Result, 32);
  Sig( CondCode, 4);
  Sig( DataOut, 32);
  Sig( LdOut, 32);
  Sig( SethiOut, 32);
  Sig( CallOut, 32);
  Sig( JmplOut, 32);
  Sig( RegIn, 32);
  Sig( StCmd, 1);
  Sig( BranchCmd, 1);
  Sig( Enable, 1);
  Sig( NotMem, 1);
  Sig( SetNZVC, 1);
  Sig( LdInstruct, 32);
  Nand("1a",(ir[31],ir[30]),NotMem);
  And("1a",(NotMem,ir[31],ir[23]),SetNZVC);
  Sig( Invalid, 1);
  CLOCK( "1a", cp, run );
  Adder( "9b", (npc, four), npc_plus4 );
  NPC( "7d-9d", cp, run, One, npc_plus4, npc );
  
  IMEM( "4e-6e", npc.sub(15,2), imem_out );
  PC( "7f-9f", cp, run, One, npc, pc );
  
  IR( "4f-6f", cp, run, One, imem_out, ir );
  NZVC( "4i", cp, run, SetNZVC, CondCode, nzvc );
  
And("1a",(ir[31],ir[30],ir[21]),StCmd);
Nor("1a",(ir[31],ir[30],ir[29]),BranchCmd);
Nor("1a",(Valid, Zero),Invalid);
Nor("1a",(StCmd,BranchCmd,Invalid),Enable);
  DECODE( "4g", cp, run, ir, Valid, Ld, St, Data, Sethi, Branch, Call, Jmpl,
    Nzvc, Opcode);

    ALU( "4k", cp, run, Opcode, RegAOut, Operand2, Result, CondCode);
    REG( "ki-3j", cp, run, (ir.sub(18,14)),(ir.sub(4,0)),
          (ir.sub(29,25)), Enable, Result, RegAOut, RegBOut, RegCOut );
    Mux( "7j",(ir[13]),((19*Zero,ir.sub(12,0)),(RegBOut)),Operand2);
    
}