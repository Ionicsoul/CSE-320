#
# Usage:  make -f shiftunit.check.make
# Makes:  shiftunit.check
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = shiftunit.o
IFILES = /user/cse320/Honors/Milestone03/shiftunit.check.o

shiftunit.check: $(SFILES)
	g++ $(SFILES) $(IFILES) $(SIMLIBS) -o shiftunit.check

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f shiftunit.check

