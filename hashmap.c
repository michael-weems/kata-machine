#include "hashmap.h"

// NOTE: planning to redo the arraylist for this, but for now
// NOTE: the arraylist indices will be even: key, odd: value

void hashmap_grow(HashMap *map){
	
}

int hash(int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

int hashmap_index(HashMap *map, int key) {
	 
}

HashMap *hashmap_create(int capacity, float load_factor) {
	
}
void hashmap_free(HashMap *map) {
	
}

bool hashmap_has(HashMap *map, int key) {
	
}
void hashmap_set(HashMap *map, int key, int value) {
	
}
int hashmap_get(HashMap *map, int key) {
	
}
int hashmap_delete(HashMap *map, int key) {
	
}

