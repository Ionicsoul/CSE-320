proj07: proj07.support.o /user/cse320/Projects/project07.driver.o
	gcc proj07.support.o /user/cse320/Projects/project07.driver.o -o proj07
proj07.support.o: proj07.support.c
	gcc -c proj07.support.c