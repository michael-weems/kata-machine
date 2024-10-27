#include "_testutils.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define NOCOLOR "\033[0m"

void printArray(int arr[], int arrSize) {
	printf("[");
	for (int i = 0; i < arrSize; ++i) {
		printf("%d", arr[i]);
		if (i != arrSize - 1) {
			printf(", ");
		}
	}
	printf("]");
}
int expect_array(int *expected, int *actual, int arrLength) {
	int errors = 0;

	for (int i = 0; i < arrLength; ++i) {
		if (expected[i] != actual[i]) {
			++errors;
		} 
	}

	if (errors == 0) {
		printf("%spass:%s ", GREEN, NOCOLOR);
		printArray(actual, arrLength);
		printf("\n");
		return 0;
	}

	printf("%sfail:%s\nexpected: [", RED, NOCOLOR);
	for (int i = 0; i < arrLength; ++i) {
		if (expected[i] != actual[i]) {
			printf("%s%d%s", GREEN, expected[i], NOCOLOR);
		} else {
			printf("%d", expected[i]);
		}

		if (i < arrLength-1){
			printf(", ");
		}
	}
	printf("]\n");

	printf("  actual: [");
	for (int i = 0; i < arrLength; ++i) {
		if (expected[i] != actual[i]) {
			printf("%s%d%s", RED, actual[i], NOCOLOR);
			++errors;
		} else {
			printf("%d", actual[i]);
		}

		if (i < arrLength-1){
			printf(", ");
		}
	}
	printf("]\n\n");

	return errors;
}

void red() {
	printf(RED);
}

void green() {
	printf(GREEN);
}

void nocolor() {
	printf(NOCOLOR);
}

int failArray(int input[], int expected[], int received[]) {
	red();
	printf("fail: input ");
	printArray(input, 10);
	printf(" - expected ");
	printArray(expected, 10);
	printf(" - received ");
	printArray(received, 10);
	nocolor();
	printf("\n");
	return 1;
}

int failInt(int expected, int received) {
	red();
	printf("fail: expected %d - received %d\n", expected, received);
	nocolor();
	return 1;
}

int failBool(bool expected, bool received) {
	red();
	printf("fail: expected %s - received %s\n", expected ? "true" : "false", received ? "true" : "false");
	nocolor();
	return 1;
}

int fail(char *msg) {
	red();
	printf("fail: %s\n", msg);
	nocolor();
	return 1;
}

void pass(char *msg) {
	green();
	printf("pass: %s\n", msg);
	nocolor();
}

void summary(int failed, int count) {
	if (failed > 0) {
		red();
	}
	printf("%d failed", failed);
	nocolor();
	printf(" + ");
	green();
	printf("%d succeeded", count - failed);
	if (failed > 0) {
		nocolor();
	}
	printf(" / %d total tests\n", count);
	nocolor();
}
