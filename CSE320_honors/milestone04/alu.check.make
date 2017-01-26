#
# Usage:  make -f alu.check.make
# Makes:  alu.check
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = alu.o
IFILES = /user/cse320/Honors/Milestone04/alu.check.o

alu.check: $(SFILES)
	g++ $(SFILES) $(IFILES) $(SIMLIBS) -o alu.check

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f alu.check

