#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10 // size of static array
#define TRUE 1
#define FALSE 0

//defining the struct of the stack

typedef double elem; //changing the name of int to elem

struct stack{
	elem array[STACK_SIZE]; //array of STACK_SIZE elem(int) elements
	int top; // variable that shows where the head of the stack is(0 - STACK_SIZE - 1) else -1 if the stack is empty
};

typedef struct stack STACK; //simple synonym for the stack

//funcs to do things to the stack 
void ST_init(STACK *s);
int ST_full(STACK s);
int ST_empty(STACK s);
int ST_push(STACK *s, elem x);
int ST_pop(STACK *s, elem *x);
