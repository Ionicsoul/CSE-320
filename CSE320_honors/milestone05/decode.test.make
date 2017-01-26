#
# Usage:  make -f decode.test.make
# Makes:  decode.test
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = decode.o decode.test.o

decode.test: $(SFILES) 
	g++ $(SFILES) $(SIMLIBS) -o decode.test

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f decode.test

