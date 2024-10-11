#include <stdio.h>
#include "hashmap.h"

// NOTE: planning to redo the arraylist for this, but for now
// NOTE: the arraylist indices will be even: key, odd: value

void hashmap_grow(HashMap *map){
	int prev = map->capacity;
	map->capacity *= 2;
	Arrlist **tmp = (Arrlist **)realloc(map->buckets, sizeof(Arrlist **) * map->capacity);
	if (tmp != NULL) {
		map->buckets = tmp;
	} else {
		exit(1);
	}

	for (int i = prev; i < map->capacity; ++i) {
		map->buckets[i] = al_create(6);
	}
}

int hash(int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

int hashmap_index(HashMap *map, int key) {
	int idx = hash(key);
	idx = idx % map->capacity;
	return idx; 
}

HashMap *hashmap_create(int capacity, float load_factor) {
	HashMap *map = malloc(sizeof(HashMap));
	map->size = 0;
	map->capacity = capacity;
	map->load_factor = load_factor;
	map->buckets = (Arrlist **)malloc(sizeof(Arrlist **) * capacity);
	for (int i = 0; i < capacity; ++i) {
		//map->buckets[i] = (Arrlist *)malloc(sizeof(Arrlist *));
		map->buckets[i] = al_create(6);
	}
	return map;
}
void hashmap_free(HashMap *map) {
	// TODO: this needs help, getting "core dumped" error
	for (int i = 0; i < map->capacity; ++i){
		al_free(map->buckets[i]);
	}
	free(map->buckets);
	free(map);
}

bool hashmap_has(HashMap *map, int key) {
	int bucket = hashmap_index(map, key);
	if (map->buckets[bucket]->length == 0) {
		return false;
	}

	int el_idx = al_index_of(map->buckets[bucket], key);
	if (el_idx == -1 || el_idx % 2 == 1) {
		return false;
	}
	int val = al_get(map->buckets[bucket], el_idx+1);
	if (val == -1) {
		return false;
	}

	return true;
}
void hashmap_set(HashMap *map, int key, int value) {
	map->size = map->size + 1;
	int bucket = hashmap_index(map, key);
	int existing_index = al_index_of(map->buckets[bucket], key);
	if (existing_index != -1 && existing_index % 2 == 0) {
		al_update(map->buckets[bucket], existing_index+1, value);
	} else {
		al_append(map->buckets[bucket], key);
		al_append(map->buckets[bucket], value);
	}

	float percentage = (float)map->size / (float)map->capacity;
	if (percentage > map->load_factor) {
		printf(" - hashmap_grow\n");
		hashmap_grow(map);
	}
}
int hashmap_get(HashMap *map, int key) {
	int bucket = hashmap_index(map, key);
	if (map->buckets[bucket]->length == 0) {
		return -1;
	}

	int el_idx = al_index_of(map->buckets[bucket], key);
	if (el_idx == -1 || el_idx % 2 == 1) {
		return -1;
	}

	return al_get(map->buckets[bucket], el_idx + 1);
}
int hashmap_delete(HashMap *map, int key) {
	int bucket = hashmap_index(map, key);
	if (map->buckets[bucket]->length == 0) {
		return -1;
	}

	int el_idx = al_index_of(map->buckets[bucket], key);
	if (el_idx == -1 || el_idx % 2 == 1) {
		return -1;
	}

	map->size = map->size - 1;
	// NOTE: do it twice to get the key + the value
	al_remove_at(map->buckets[bucket], el_idx);
	return al_remove_at(map->buckets[bucket], el_idx);
}

