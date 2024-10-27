#ifndef SORTING_H
#define SORTING_H

typedef void (*SortStrategy) (int *arr, int arrSize);
SortStrategy sortFactory(char *strategy);

int sortingTests(char *sortingStrategy); 

#endif
