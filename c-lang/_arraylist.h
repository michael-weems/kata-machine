#ifndef UTILARRAYLIST_H
#define UTILARRAYLIST_H

#include <stdlib.h>

typedef struct {
	int capacity;
	int length;
	int *arr;
} Arrlist;

Arrlist *al_create(int capacity);
void al_free(Arrlist *list);
void al_prepend(Arrlist *list, int value);
void al_append(Arrlist *list, int value);
void al_insert(Arrlist *list, int idx, int value);
int al_remove(Arrlist *list, int value);
int al_remove_at(Arrlist *list, int idx);
int al_get(Arrlist *list, int idx);
int al_index_of(Arrlist *list, int value);
void al_update(Arrlist *list, int idx, int value);

#endif
