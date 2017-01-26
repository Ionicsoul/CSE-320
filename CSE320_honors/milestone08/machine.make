#
# Usage:  make -f machine.make
# Makes:  arc
#

ARCHDIR=/user/csearch/sim
SIMLIBS=-L$(ARCHDIR)/lib -lsim -L/usr/openwin/lib -lX11 -lposix4 -ldl -lnsl

STUDENT_FILES = machine.o

SUPPLIED_FILES = \
  /user/cse320/Honors/Milestone08/clock.o \
  /user/cse320/Honors/Milestone08/memory.o \
  /user/cse320/Honors/Milestone08/registers.o \
  /user/cse320/Honors/Milestone08/components.o

arc: $(SUPPLIED_FILES) $(STUDENT_FILES)
	g++ $(SUPPLIED_FILES) $(STUDENT_FILES) $(SIMLIBS) -o arc

%.o: %.c
	g++ -I$(ARCHDIR)/include -c $*.c

clean:
	rm -f $(STUDENT_FILES)
	rm -f arc

