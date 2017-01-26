#
# Usage:  make -f mathunit.check.make
# Makes:  mathunit.check
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = mathunit.o
IFILES = /user/cse320/Honors/Milestone02/mathunit.check.o

mathunit.check: $(SFILES)
	g++ $(SFILES) $(IFILES) $(SIMLIBS) -o mathunit.check

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f mathunit.check

