
/******************************************************************************
  Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

   //Replace with code to generate four input signals
  Signal Strobe (1);   // Counter strobe input
  Signal ResetA (1);   // Counter reset signal (before complemented)
  Signal ResetB (1);   // Counter reset signal (after complemented)
  

        // A pulser is used to generate a temporary value of "One" on a
        // specified
        // signal line (signal value:  Zero ==> One ==> Zero)

  Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

            // Complement the reset signal (counter reset is active low)

    Not (SD("1b"), ResetA, ResetB);

   Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w, x, y, z));



   Probe ((SD("1i"), "Present"), Present );
   Probe ((SD("2h-2j"), "a"), a);
   Probe ((SD("2h-3h"), "f"), f);
   Probe ((SD("2j-3j"), "b"), b);
   Probe ((SD("3h-3j"), "g"), g);
   Probe ((SD("3h-4h"), "e"), e);
   Probe ((SD("3j-4j"), "c"), c);
   Probe ((SD("4h-4j"), "d"), d);
   
  circuits( SD("1e-4f"), w, x, y, z, Present, a, b, c, d, e, f, g);
  
  
  // Replace with code to display eight output signals
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz, andP1, andP2, andP3, andP4, andA1, andB1, andD1, andD2, andD3;
  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd, "1c"), w, notw );
  Not ( SD(sd, "2c"), x, notx );
  Not ( SD(sd, "3c"), y, noty );
  Not ( SD(sd, "4c"), z, notz );
    
  And ( SD(sd, "1c"), (notw, x, noty), andP1);
  And ( SD(sd, "2c"), (notw, noty, z), andP2);
  And ( SD(sd, "3c"), (w, notx, notz), andP3);
  And ( SD(sd, "4c"), (notw, y, notz), andP4);
 
  And ( SD(sd, "1c"), (x, z), andA1);
  And ( SD(sd, "2c"), (noty, notz), andB1);
 
  And ( SD(sd, "3c"), (notw, y), andD1);
  And ( SD(sd, "3c"), (x, z), andD2);
  And ( SD(sd, "3c"), (w, noty), andD3);
  
  Or (SD (sd, "1d"), (andP1, andP2, andP3, andP4), Present);
  Or (SD (sd, "2d"), (y, w, andA1), a);
  Or (SD (sd, "3d"), (notx, andB1), b);
  Or (SD (sd, "4d"), (w, x, noty), c);
  
  Or (SD (sd, "1d"), (andD1, andD2, andD3), d);
  Or (SD (sd, "2d"), (w, y), e);
  Or (SD (sd, "3d"), (w, x), f);
  Or (SD (sd, "4d"), (x, notz), g);
  
}

