#include "circle_queue.h"

void QU_init(QUEUE *q)
{
	q -> start = -1;
	q -> finish = -1;
}

int QU_empty(QUEUE q)
{
	return q.finish == -1;
}

int QU_full(QUEUE q)
{
	return q.start == (q.finish + 1) % SIZE;
}

int QU_enqueue(QUEUE *q, elem x)
{
	if(QU_full(*q))
		return FALSE;
	if(QU_empty(*q))
	{
		q -> start = 0;
		q -> finish = 0;
	}
	else
		q -> finish = (q -> finish + 1) % SIZE;
	q -> array[q -> finish] = x;
	return TRUE;
}

int QU_dequeue(QUEUE *q, elem *x)
{
	if(QU_empty(*q))
		return FALSE;
	*x = q -> array[q -> start];
	if(q -> start == q -> finish)
	{
		q -> start = -1;
		q -> finish = -1;
	}
	else
		q -> start = (q -> start + 1) % SIZE;
	return TRUE;
}

void QU_print(QUEUE *q)
{
	QUEUE temp;
	QU_init(&temp);
	int x;
	//print the elements on the original queue
	while(!QU_empty(*q))
	{
		QU_dequeue(q, &x);
		printf("[%3d]", x);
		QU_enqueue(&temp, x);
	}
	
	//return the elements to the original queue
	
	while(!QU_empty(temp))
	{
		QU_dequeue(&temp, &x);
		QU_enqueue(q, x);
	}
}

void QU_reverse(QUEUE *q)
{
	STACK st;
	ST_init(&st);
	int x;
	while(!QU_empty(*q))
	{
		QU_dequeue(q, &x);
		ST_push(&st, x);
	}
	
	while(!ST_empty(st))
	{
		ST_pop(&st, &x);
		QU_enqueue(q, x);
	}
}

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
	return s.top == SIZE -1;
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
		s->stack_array[s->top] = x;
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
		*x = s -> stack_array[s -> top];
		s->top--;
		return TRUE	;
	}	
}


