#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 5

typedef char * elem;

typedef struct{
	elem array[SIZE];
	int start;
	int finish;
} QUEUE;

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_full(QUEUE q);
int QU_enqueue(QUEUE *q, elem x);
int QU_dequeue(QUEUE *q, elem *x);
