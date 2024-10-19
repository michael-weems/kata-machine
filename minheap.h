#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdlib.h>

struct MinHeap {
	int size;
	int capacity;
	int *arr;
};

struct MinHeap *minheap_create(int capacity);
void minheap_destroy(struct MinHeap *heap);

int minheap_remove(struct MinHeap *heap);
void minheap_insert(struct MinHeap *heap, int key);

#endif
