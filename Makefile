TARGET=bubblesort

clean:
	rm -f *.o
	rm -f *.out

run: clean
	gcc -o $(TARGET).out _tests.c $(TARGET).c $(TARGET)_tests.c 
	./$(TARGET).out

# Sorting
bubblesort: TARGET=bubblesort
bubblesort: run
	rm -f *.out

quicksort: TARGET=quicksort
quicksort: run
	rm -f *.out

	
# Search
linearsearch: TARGET=linearsearch
linearsearch: run
	rm -f *.out

# Simple problems
twocrystalballs: TARGET=twocrystalballs
twocrystalballs: run
	rm -f *.out

