
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  Pulser ((SD("1a"), "i -- Init"),  Init, 'i', 10000);
  Pulser ((SD("2a"), "c -- Clock"), Clock, 'c', 10000);
  
  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  Probe ((SD("1d"), "Output1"), w);
  Probe ((SD("2d"), "Output2"), x); 
  Probe ((SD("3d"), "Output3"), y);
  Probe ((SD("4d"), "Output4"), z);
  
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz, andW, andX, andY1, andY2, andY3, andZ;
  Signal Reset, W, X, Y, Z;
 
  // Replace with code for your DFFs
  
  Dff( SD(sd, "1c"), (Init, W, Clock, Zero), w);
  Dff( SD(sd, "1c"), (Zero, X, Clock, Init), x);
  Dff( SD(sd, "1c"), (Init, Y, Clock, Zero), y);
  Dff( SD(sd, "1c"), (Zero, Z, Clock, Init), z);
  
  
  // Replace with circuit implementation (Not, And, Or gates)
  
  Not ( SD(sd, "1c"), w, notw );
  Not ( SD(sd, "2c"), x, notx );
  Not ( SD(sd, "3c"), y, noty );
  Not ( SD(sd, "4c"), z, notz );
  
  And ( SD(sd, "1c"), (x, notz), W);
  And ( SD(sd, "2c"), (w, y), andX);
  And ( SD(sd, "4c"), (x, z), andY1);

  And ( SD(sd, "4c"), (x, y), andY2);
  And ( SD(sd, "4c"), (w, noty), andY3);
  And ( SD(sd, "1b"), (notw, notx), Z);

  Or (SD(sd, "1c"), (z, andX), X);
  Or (SD(sd, "2c"), (andY1, andY2, andY3), Y);


}

