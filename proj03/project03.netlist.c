
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

  // Replace with code to generate four input signals
 // Signal Strobe (1);   // Counter strobe input
 // Signal ResetA (1);   // Counter reset signal (before complemented)
 // Signal ResetB (1);   // Counter reset signal (after complemented)
 // Signal Output (4);   // Counter output

        // A pulser is used to generate a temporary value of "One" on a
        // specified
        // signal line (signal value:  Zero ==> One ==> Zero)

  // Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  // Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

            // Complement the reset signal (counter reset is active low)

    //Not (SD("1b"), ResetA, ResetB);

   // Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe),Output);



   Probe ((SD("1f"), "Present"), Present );
   Probe ((SD("2f"), "a"), a);
   Probe ((SD("3e"), "f"), f);
   Probe ((SD("3g"), "b"), b);
   Probe ((SD("4f"), "g"), g);
   Probe ((SD("5e"), "e"), e);
   Probe ((SD("5g"), "c"), c);
   Probe ((SD("6f"), "d"), d);
   
  circuits( SD("1c-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);
  
  Switch(SD("1a"), w, 'w');
  Switch(SD("2a"), x, 'x');
  Switch(SD("3a"), y, 'y');
  Switch(SD("4a"), z, 'z');
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
  Signal notw, notx, noty, notz, andP1, andP2, andP3, andP4;
  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD("1c"), w, notw );
  Not ( SD("2c"), x, notx );
  Not ( SD("3c"), y, noty );
  Not ( SD("4c"), z, notz );
    
  And ( SD("1c"), (notw, x, noty), andP1);
  And ( SD("2c"), (notw, noty, z), andP2);
  And ( SD("3c"), (w, notx, notz), andP3);
  And ( SD("4c"), (notw, y, notz), andP4);
 
  

}

