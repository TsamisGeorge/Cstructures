#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_SIZE 31

typedef int elem;

struct heap_tree{
	elem data[MAX_SIZE];
	int N;
};
typedef struct heap_tree HEAP;


void swap(elem *x, elem *y);
void HEAP_init(HEAP *heap);
int HEAP_insert(HEAP *heap, elem x);
int HEAP_delete(HEAP *heap, elem *x);
