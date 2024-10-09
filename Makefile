clean:
	rm -f *.o
	rm -f *.out

bubblesort: clean
	gcc -o bubblesort.out _tests.c bubblesort.c bubblesort_tests.c 
	./bubblesort.out

