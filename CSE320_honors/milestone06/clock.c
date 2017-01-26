
#include <Sim.h>

#include "clock.h"

extern int userRunTimeFlag[];

//******************************************************************************
// CLOCK -- implementation of ARC+ Clock Unit
//******************************************************************************

void CLOCK( SD sd, Signal ClockPulse, Signal Running )
{
  Module( (sd,"CLOCK"), Signal(0), Signal(0) );
 
  const int cycle = 10000;

  Sig( count, 12 );

  Sig( clockOut, 1 );
  Sig( gateSwOut, 1 );
  Sig( pulserOut, 1 );
  Sig( gateOut, 1 );


  Space( SD(sd,"1a") );

  /* Manual clock mode (default) */

  if (userRunTimeFlag[0] < 0)
  {
    Pulser( SD(sd,"1a"), ClockPulse, 'c', cycle/2 );
    Switch( SD(sd,"1a"), Running, 'r' );
  }


  /* Automatic clock mode */

  else if (userRunTimeFlag[0] == 0)
  {
    Clock( SD(sd,"1a"), ClockPulse, cycle/4, cycle/2, cycle );
    PowerOn( SD(sd,"1a"), Running, cycle );
  }


  /* Debugging clock mode (start in automatic, go to manual) */

  else if (userRunTimeFlag[0] > 0)
  {
    Pulser( SD(sd,"1a"), pulserOut, 'c', cycle/2 );
    PowerOn( SD(sd,"1a"), gateSwOut, userRunTimeFlag[0]*cycle, One );
    Clock( SD(sd,"1a"), clockOut, cycle/4, cycle/2, cycle );
    PowerOn( SD(sd,"1a"), Running, cycle );

    Gate( SD(sd,"1b"), (gateSwOut, clockOut), gateOut );

    Or( SD(sd,"1c"), (pulserOut, gateOut), ClockPulse );
  }

  Counter( SD(sd,"1d"), (Running, ClockPulse), count );

  if (userRunTimeFlag[1] == 0)
  {
    Sigv( C, 8, 'C' );
    Sigv( L, 8, 'L' );
    Sigv( sp, 8, 0x20 );  // ASCII blank
    Sigv( nl, 8, 0x0A );  // ASCII newline

    Stderr( SD(sd,"1a"), (Running, ClockPulse, nl) );
    Stderr( SD(sd,"1a"), (Running, ClockPulse, C) );
    Stderr( SD(sd,"1a"), (Running, ClockPulse, L) );
    Stderr( SD(sd,"1a"), (Running, ClockPulse, sp) );
    HexOut( SD(sd,"1a"), (Running, ClockPulse ), count );
    Stderr( SD(sd,"1a"), (Running, ClockPulse, nl) );
  }
}

