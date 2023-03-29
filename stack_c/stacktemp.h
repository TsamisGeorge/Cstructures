#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10 // size of static array
#define TRUE 1
#define FALSE 0

//struct of type students, each student has 2 attributes, a name and a grade
struct student{
	char name[80];
	int grade;	
};


typedef struct student STUDENT;
typedef STUDENT ELEM;

struct stack{
	STUDENT array[STACK_SIZE]; //array of STACK_SIZE of STUDENT elements
	int top; // variable that shows where the head of the stack is(0 - STACK_SIZE - 1) else -1 if the stack is empty
};


typedef struct stack STACK; //simple synonym for the stack

//funcs to do things to the stack 
void ST_init(STACK *s);
int ST_full(STACK s);
int ST_empty(STACK s);
int ST_push(STACK *s, ELEM x);
int ST_pop(STACK *s, ELEM *x);



