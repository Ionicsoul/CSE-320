
#include <Sim.h>
#include "/user/cse320/Honors/Milestone05/decode.h"

//******************************************************************************
// DecodeUnit -- implementation of ARC+ Decode Unit
//******************************************************************************

void DecodeUnit( SD sd, Signal IN, Signal LD, Signal ST, Signal Data,
  Signal SETHI, Signal Branch, Signal CALL, Signal JMPL, Signal Invalid,
  Signal Update, Signal Opcode )
{
  Module( (sd,"Decode Unit"), (IN),
   (LD,ST,Data,SETHI,Branch,CALL,JMPL,Invalid,Update,Opcode) );
  Signal a0, a1, b0, b1, b2, b3, b4, b5, branch, sethi, call, add, sll, srl, sra, jmpl, ld, st, invalid, ninvalid, nzvc;
  Signal test;
  

  And ( SD(sd,"2b"), (a1, a0, b5, IN[23], b3), branch);
  Or  ( SD(sd,"2d"), (branch, Zero), Branch);
  And ( SD(sd,"3c"), (a1, a0, IN[24], b4, b3), sethi);
  Or  ( SD(sd,"3d"), (sethi, Zero), SETHI);
  And ( SD(sd,"4c"), (a1, IN[30]), call);
  Or  ( SD(sd,"4d"), (call, Zero), CALL);
  And ( SD(sd,"5b"), (IN[31], a0, b5, b3), add);  
  And ( SD(sd,"6c"), (IN[31], a0, IN[24], b4, b3, IN[21], b1, IN[19]), sll);  
  And ( SD(sd,"6c"), (IN[31], a0, IN[24], b4, b3, IN[21], IN[20], a0), srl);
  And ( SD(sd,"7c"), (IN[31], a0, IN[24], b4, b3, IN[21], IN[20], IN[19]), sra);
  Not ( SD(sd,"1b"), IN[31], a1);    
  Not ( SD(sd,"2b"), IN[30], a0);    
  Not ( SD(sd,"3b"), IN[24], b5);    
  Not ( SD(sd,"4b"), IN[23], b4);    
  Not ( SD(sd,"5b"), IN[22], b3);    
  Not ( SD(sd,"6b"), IN[21], b2);    
  Not ( SD(sd,"7b"), IN[20], b1);    
  Not ( SD(sd,"8b"), IN[19], b0);    
  Or  ( SD(sd,"11c"), (branch, sethi, call, add, sll, srl, sra, jmpl, ld, st), invalid);
  Not ( SD(sd,"11d"), invalid, ninvalid);
  Or  ( SD(sd,"11e"), (ninvalid, Zero), Invalid);
  Or  ( SD(sd,"7d"), (add, sll, srl, sra), Data);
  And ( SD(sd,"8c"), (IN[31], a0, IN[24], IN[23], IN[22], b2, b1, b0), jmpl);
  Or  ( SD(sd,"8d"), (jmpl, Zero), JMPL);
  And ( SD(sd,"9c"), (IN[31], IN[30], b5, b4, b3, b2, b1, b0), ld);
  Or  ( SD(sd,"9d"), (ld, Zero), LD);
  And ( SD(sd,"10c"), (IN[31], IN[30], b5, b4, b3, IN[21], b1, b0), st);
  Or  ( SD(sd,"10d"), (st, Zero), ST);

  Or  ( SD(sd,"12c"), (add, sll, srl, sra), test);
  And ( SD(sd,"13c"), (test, IN[19]), Opcode[0]);
  And ( SD(sd,"14c"), (test, IN[20]), Opcode[1]);
  And ( SD(sd,"15c"), (test, IN[21]), Opcode[2]);
  And ( SD(sd,"16c"), (test, IN[22]), Opcode[3]);
  And ( SD(sd,"17c"), (test, IN[23]), Opcode[4]);
  And ( SD(sd,"18c"), (test, IN[24]), Opcode[5]);
  And ( SD(sd,"19c"), (IN[31], a0, b5, IN[23], b3), nzvc);
  Or  ( SD(sd,"19d"), (nzvc, Zero), Update);
} 