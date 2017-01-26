

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
  Sig( callOrjmpl, 1);
Sig( first, 2);
Sig( second, 1);
Sig( address, 32);
Sig( tempRes, 32);
Sig( rs1rs2, 32);
Sig( rs1simm13, 32);
Sig( simm13, 32);

Sig( stbranch, 1);
Sig( stbranch1, 1);
   
  Nand("2b",(ir[31],ir[30]),NotMem); 
  And("2b",(NotMem,ir[31],ir[23]),SetNZVC); 
  Sig( Invalid, 1); 
  CLOCK( "2b", cp, run ); 
  Adder( "10c", (npc, four), npc_plus4 ); 
  NPC( "8e-10e", cp, run, One, npc_plus4, npc ); 
   
  IMEM( "5f-7f", npc.sub(15,2), imem_out ); 
  PC( "8g-10g", cp, run, One, npc, pc ); 
   
  IR( "5g-7g", cp, run, One, imem_out, ir ); 
  NZVC( "5j", cp, run, SetNZVC, CondCode, nzvc ); 
   
 // And("2b",(ir[31],ir[30],ir[21]),StCmd); 
  //Nor("2b",(ir[31],ir[30],ir[29]),BranchCmd); 
  Nor("2b",(Valid, Zero),Invalid); 
  Or( "2b", (St, Branch), stbranch);
  Not( "2b", stbranch, stbranch1);  
  And( "2b", (stbranch1, Valid), Enable);

  ///Nor("2b",(StCmd,BranchCmd,Invalid),Enable); 

  DECODE( "5e", cp, run, ir, Valid, Ld, St, Data, Sethi, Branch, Call, Jmpl, Nzvc, Opcode); 
     
  REG( "2j-4j", cp, run, (ir.sub(18,14)),(ir.sub(4,0)), 
          (ir.sub(29,25)), Enable, Result, RegAOut, RegBOut, RegCOut ); 

  Mux( "3k",(ir[13]),((19*Zero,ir.sub(12,0)),(RegBOut)),Operand2); 
  ALU( "3l", cp, run, Opcode, RegAOut, Operand2, tempRes, CondCode);
  



  Adder( "10c", (RegAOut, RegBOut), rs1rs2);
  Adder( "10c", (RegAOut, (19*Zero,ir.sub(12,0))), rs1simm13);

 
  Mux( "3k",(ir[13]),((rs1simm13),(rs1rs2)), address); 

  DMEM( "1l", cp, Ld, St, address, RegCOut, LdInstruct);
  
  //Or("2b", (Call, Jmpl), callOrjmpl);
  
  //Encoder( "3d",  (callOrjmpl, Data, Sethi, Ld), first, second);
  //Encoder( "3d",  (Call, Jmpl, Data, Sethi), first, second);


  //Mux( "2m", ... );
  //Mux (position, (select port), (data port), signal_out);

  Mux (SD("2m"), (ir.sub(31,30)), ((LdInstruct), (tempRes), (pc), (ir.sub(21,0), 10*Zero)), Result);

}





















// Mux( "1a",(Data),((Result),(32*Zero)),DataOut);
// Mux( "1a",(Ld),((LdInstruct),(32*Zero)),LdOut);
// Mux( "1a",(Sethi),((ir.sub(21,0),10*Zero),(32*Zero)),SethiOut);
// Mux( "1a",(Call),((pc),(32*Zero)),CallOut);
// Mux( "1a",(Jmpl),((pc),(32*Zero)),JmplOut);
 
// Or("1a",(DataOut,LdOut,SethiOut,CallOut,JmplOut),RegIn);
  
//}
