#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>

typedef struct {
	int capacity;
	int length;
	int *arr;
} Arraylist;

Arraylist *arraylist(int capacity);
void arraylist_free(Arraylist *list);
void arraylist_prepend(Arraylist *list, int value);
void arraylist_append(Arraylist *list, int value);
void arraylist_insert(Arraylist *list, int idx, int value);
int arraylist_remove(Arraylist *list, int value);
int arraylist_remove_at(Arraylist *list, int idx);
int arraylist_get(Arraylist *list, int idx);
int arraylist_index_of(Arraylist *list, int value);
void arraylist_update(Arraylist *list, int idx, int value);

#endif
