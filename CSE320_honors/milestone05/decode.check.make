#
# Usage:  make -f decode.check.make
# Makes:  decode.check
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = decode.o
IFILES = /user/cse320/Honors/Milestone05/decode.check.o

decode.check: $(SFILES)
	g++ $(SFILES) $(IFILES) $(SIMLIBS) -o decode.check

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f decode.check

