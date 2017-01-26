#
# Usage:  make -f add8.test.make
# Makes:  add8.test
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = add8.o add8.test.o

add8.test: $(SFILES) 
	g++ $(SFILES) $(SIMLIBS) -o add8.test

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f add8.test

