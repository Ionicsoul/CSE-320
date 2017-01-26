#
# Usage:  make -f math8.test.make
# Makes:  math8.test
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = math8.o math8.test.o

math8.test: $(SFILES) 
	g++ $(SFILES) $(SIMLIBS) -o math8.test

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f math8.test

