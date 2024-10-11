#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <stdbool.h>
#include "_arraylist.h"

typedef struct {
	float load_factor;
	int size;
	int capacity;
	Arrlist **buckets;
} HashMap;

HashMap *hashmap_create(int capacity, float load_factor);
void hashmap_free(HashMap *map);

bool hashmap_has(HashMap *map, int key);
void hashmap_set(HashMap *map, int key, int value);
int hashmap_get(HashMap *map, int key);
int hashmap_delete(HashMap *map, int key);

#endif
