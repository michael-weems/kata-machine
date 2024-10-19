#include "minheap.h"

int minheap_leftchild(int n) {
	return (n*2) + 1;
}
int minheap_rightchild(int n) {
	return (n*2) + 2;
}
int minheap_parent(int n) {
	return (n-1) / 2;
}
void minheap_swap(int *arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

struct MinHeap *minheap_create(int capacity){
	struct MinHeap *heap = malloc(sizeof(struct MinHeap *));
	heap->arr = calloc(capacity, sizeof(int *));
	heap->size = 0;
	heap->capacity = capacity;
	return heap;
}
void minheap_destroy(struct MinHeap *heap) {
	free(heap->arr);
	free(heap);
}
void minheap_insert(struct MinHeap *heap, int value){
	int c = heap->size;
	int p = minheap_parent(c);

	heap->arr[c] = value;
	while (heap->arr[p] > heap->arr[c]) {
		minheap_swap(heap->arr, p, c);

		c = p;
		p = minheap_parent(p);
		if (c == 0) {
			break;
		}
	}
	heap->size++;
}


int minheap_remove(struct MinHeap *heap) {
	int out = heap->arr[0];
	heap->size--;

	int c = 0;
	minheap_swap(heap->arr, c, heap->size); 

	while (c < heap->size) {

		int l = minheap_leftchild(c);
		int r = minheap_rightchild(c);

		if (r < heap->size && heap->arr[l] > heap->arr[r] && heap->arr[r] < heap->arr[c]) {
			minheap_swap(heap->arr, r, c);
			c = r;
			continue;
		} else if (l < heap->size && heap->arr[l] < heap->arr[c]){
			minheap_swap(heap->arr, l, c);
			c = l;
			continue;
		}

		// NOTE: either arr[c] < arr[l] && arr[c] < arr[r] OR l and r are > heap->size
		break;
	}

	return out;
}
