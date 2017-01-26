#
# Usage:  make -f shift8.test.make
# Makes:  shift8.test
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = shift8.o shift8.test.o

shift8.test: $(SFILES) 
	g++ $(SFILES) $(SIMLIBS) -o shift8.test

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f shift8.test

