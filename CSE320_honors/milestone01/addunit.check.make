#
# Usage:  make -f addunit.check.make
# Makes:  addunit.check
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

SFILES = addunit.o
IFILES = /user/cse320/Honors/Milestone01/addunit.check.o

addunit.check: $(SFILES)
	g++ $(SFILES) $(IFILES) $(SIMLIBS) -o addunit.check

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(SFILES)
	rm -f addunit.check

