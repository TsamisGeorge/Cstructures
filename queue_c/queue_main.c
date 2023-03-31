#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void)
{
	QUEUE qu;
	QU_init(&qu);
	int x;
	while(1)
	{
		printf("|Queue Menu|.\n");
		printf("____________\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Give an element: ");
				if(QU_enqueue(&qu, x))
		}
	}
}
