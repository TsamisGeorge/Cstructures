#include "queue.h"

void QU_init(QUEUE *q)
{
	q -> finish = -1;
}

int QU_empty(QUEUE q)
{
	return q.finish == -1;
}

int QU_full(QUEUE q)
{
	return q.finish == SIZE - 1;
}

int QU_enqueue(QUEUE *q, elem x)
{
	if(QU_full(*q))	
		return FALSE;
	else
	{
		q -> finish ++;
		q -> array[q->finish] = x;
		return TRUE;
	}
}

int QU_dequeue(QUEUE *q, elem *x)
{
	int i;
	if(QU_empty(*q))
		return FALSE;
	else
	{
		*x = q->array[0];
		for(i=0;i<=q->finish;i++)
			q -> array[i] = q -> array[i +	 1];
		q -> finish --;
		return TRUE;
	}
}
