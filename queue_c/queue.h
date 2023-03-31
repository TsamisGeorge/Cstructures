#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10

typedef int elem;
struct queue{
	elem array[SIZE];
	int finish;
};

typedef struct queue QUEUE;

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_full(QUEUE q);
int QU_enqueue(QUEUE *q, elem x);
int QU_dequeue(QUEUE *q, elem *x);
