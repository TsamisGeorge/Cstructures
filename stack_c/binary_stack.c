#include "char_stack.h"

//ST_init(), initializing the stack
// we need to make changes to the stack thus we pass by reference a pointer to a struct object
void ST_init(STACK *s)
{
	s->top = -1; // the top member of the s 
}

// ST_empty(), returns 1 if the stack is empty, else 0 if the stack is not empty
// it doesn't make changes to the stuck thus we don't need a pointer to the stack, so we pass by value 
int ST_empty(STACK s)
{
	return s.top == -1;
}

//ST_full(), returns 1 if the stack is full, else 0 if the stack is not full
// it doesn't make changes so we make a pass by value call 
int ST_full(STACK s)
{
	return s.top == STACK_SIZE -1;
}

//ST_push(), pushes the elem x in the last place of the array if the array is not full
int ST_push(STACK *s, elem x)
{
	//because we have a pointer in the ST_push parameters, we need to do *s while using ST_full()
	//so that it passes it by value(dereferencing it), which is what we need for ST_full
	if (ST_full(*s))
		return FALSE;
	else
	{
		s->top++;
		s->array[s->top] = x;
		return TRUE;
	}
}

//ST_pop(), pops the last element of the array of the stack if the stack is not emptry
int ST_pop(STACK *s,elem *x)
{
	if(ST_empty(*s))
		return FALSE;
	else
	{
		*x = s -> array[s -> top];
		s->top--;
		return TRUE	;
	}	
}
