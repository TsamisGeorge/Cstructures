#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10

typedef int elem;
struct queue{
	elem array[SIZE];
	int start;
	int finish;
};

typedef struct{
	elem stack_array[SIZE];
	int top;
} STACK;

typedef struct queue QUEUE;

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_full(QUEUE q);
int QU_enqueue(QUEUE *q, elem x);
int QU_dequeue(QUEUE *q, elem *x);
void QU_print(QUEUE *q);
void QU_reverse(QUEUE *q);


void ST_init(STACK *s);
int ST_full(STACK s);
int ST_empty(STACK s);
int ST_push(STACK *s, elem x);
int ST_pop(STACK *s, elem *x);


