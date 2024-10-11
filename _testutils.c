#include "_testutils.h"

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

void red() {
	printf("\033[0;31m");
}

void green() {
	printf("\033[0;32m");
}

void nocolor() {
	printf("\033[0m");
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
