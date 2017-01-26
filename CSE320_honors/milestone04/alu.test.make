#
# Usage:  make -f alu.test.make
# Makes:  alu.test
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = alu.o alu.test.o

alu.test: $(SFILES) 
	g++ $(SFILES) $(SIMLIBS) -o alu.test

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f alu.test

