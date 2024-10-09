TARGET=bubblesort

clean:
	rm -f *.o
	rm -f *.out

run: clean
	gcc -o $(TARGET).out _tests.c $(TARGET).c $(TARGET)_tests.c 
	./$(TARGET).out

bubblesort: TARGET=bubblesort
bubblesort: run
	rm -f *.out
	

twocrystalballs: TARGET=twocrystalballs
twocrystalballs: run
	rm -f *.out

