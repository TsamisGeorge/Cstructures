#include "circle_queue_char.h"

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
	if(q -> start == q ->finish )
	{
		q -> start = -1;
		q -> finish = -1;
	}
	else
		q -> start = (q -> start + 1) % SIZE;
	return TRUE;
}
