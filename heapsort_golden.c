#include "heapsort.h"

void heapsort(int *arr, int arrSize) {
	// TODO:
}
#include "_testutils.h"
#include "heapsort.h"

int leftchild(int n) {
	return (n*2) + 1;
}
int rightchild(int n) {
	return (n*2) + 2;
}
int parent(int n) {
	return (n-1) / 2;
}
void swap(int *arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

typedef struct {
	int size;
	int capacity;
	int *arr;
} Heap;

Heap *heap_create(int capacity){
	Heap *heap = malloc(sizeof(Heap *));
	heap->arr = calloc(capacity, sizeof(int *));
	heap->size = 0;
	heap->capacity = capacity;
	return heap;
}
void heap_free(Heap *heap) {
	free(heap->arr);
	free(heap);
}
void heap_insert(Heap *heap, int value){
	int c = heap->size;
	int p = parent(c);

	heap->arr[c] = value;
	while (heap->arr[p] > heap->arr[c]) {
		swap(heap->arr, p, c);

		c = p;
		p = parent(p);
		if (c == 0) {
			break;
		}
	}
	heap->size++;
}


int heap_delete(Heap *heap) {
	int out = heap->arr[0];
	heap->size--;

	int c = 0;
	swap(heap->arr, c, heap->size); 

	while (c <= heap->size) {

		int l = leftchild(c);
		int r = rightchild(c);
		if (l >= heap->size) {
			break;
		}

		if (heap->arr[l] > heap->arr[r]) {
			swap(heap->arr, r, c);
			c = r;
		} else {
			swap(heap->arr, l, c);
			c = l;
		}
	}

	printf("delete %d: ", out);
	printArray(heap->arr, heap->size);
	printf("\n");

	return out;
}


void heapsort(int *arr, int arrSize) {
	Heap *heap = heap_create(arrSize);

	for (int i = 0; i < arrSize; ++i) {
		heap_insert(heap, arr[i]);
	}

	for (int i = 0; i < arrSize; ++i) {
		arr[i] = heap_delete(heap);
	}
	
	heap_free(heap);
}
