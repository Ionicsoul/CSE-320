proj09: proj09.driver.o proj09.support.o
	gcc proj09.driver.o proj09.support.o -o proj09
proj09.driver.o: proj09.driver.c
	gcc -c proj09.driver.c
proj09.support.o: proj09.support.s
	gcc -c proj09.support.s