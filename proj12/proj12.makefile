proj12: proj12.support.o /user/cse320/Projects/project12.driver.o
	gcc proj12.support.o /user/cse320/Projects/project12.driver.o -o proj12
proj12.support.o: proj12.support.c
	gcc -c proj12.support.c
