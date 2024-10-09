#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>

// util functions
void printArray(int arr[], int arrSize);

// color printing
void red();
void green(); 
void nocolor(); 

// generic fail functions
int failArray(int input[], int expected[], int received[]); 
int failInt(int expected, int received); 

// pass function
void pass(char *msg); 

void summary(int failed, int count);

#endif
