s=bubble
TARGET=bubblesort
TEST_FILES=$(filter $(wildcard *_tests.c), $(wildcard *.c))
GOLDEN_FILES=$(filter $(wildcard *_golden.c), $(wildcard *.c))
C_FILES=$(filter-out $(GOLDEN_FILES), $(filter-out $(TEST_FILES), $(wildcard *.c)))

clean:
	rm -f *.o
	rm -f *.out

run: clean
	gcc -g $(C_FILES) $(TARGET)_tests.c -o $(TARGET).out -lm
	./$(TARGET).out
	#valgrind -s --leak-check=yes ./$(TARGET).out

# sorting
# usage: make sort s=quick
#      : make sort s=merge
#      : make sort s=bubble
#      : make sort s=selection
#      : etc...
sort: TARGET=$(s)sort
sort: run
	rm -f *.out

arraylist: TARGET=arraylist
arraylist: run
	rm -f *.out
hashmap: TARGET=hashmap
hashmap: run
	rm -f *.out
	
redblacktree: TARGET=redblacktree
redblacktree: run
	rm -f *.out

# Search
linearsearch: TARGET=linearsearch
linearsearch: run
	rm -f *.out

binarysearch: TARGET=binarysearch
binarysearch: run
	rm -f *.out

# Simple problems
twocrystalballs: TARGET=twocrystalballs
twocrystalballs: run
	rm -f *.out

