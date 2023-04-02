#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle_queue_char.h"
#define CUSTOMER_SIZE 80
int main(void)
{
	QUEUE checkout1, checkout2;
	QU_init(&checkout1);
	QU_init(&checkout2);
	char * customer;
	char c;
	int choice, i;
	while(1)
	{
		printf("\n|Bank Menu|\n");
		printf("_____________\n");
		printf("1. Customer arrival\n");
		printf("2. Customer checkout\n");
		printf("3. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Customer name: ");
				while ((c = getchar()) != '\n' && c != EOF);
				customer = malloc(sizeof(char) * CUSTOMER_SIZE);
				if(!customer)
				{
					printf("\nMemory allocation failed.");
					exit(0);
				}
				fgets(customer, CUSTOMER_SIZE, stdin);
				customer[strcspn(customer, "\n")] = '\0';
				if(QU_enqueue(&checkout1, customer))
				{
					printf("\n%s added to the first queue.", customer);
				}
				else if(QU_enqueue(&checkout2, customer))
				{
					printf("\n%s added to the second queue.",customer);	
				}
				else
					printf("\nThe is no more room in the queues, please get back later.");
				break;
			case 2:
				if(!QU_empty(checkout1) && !QU_empty(checkout2))
				{
					//apomakrinsh pelath apo tameio 1
					if((1 + rand() % 2) == 1)
					{
						QU_dequeue(&checkout1, &customer);
						printf("\n%s from queue 1 has been serviced.", customer);
					}
					else
					{
						QU_dequeue(&checkout2, &customer);
						printf("\n%s from queue 2 has been serviced.", customer);
					}
					free(customer);
				}
				else if(!QU_empty(checkout1))
				{
						QU_dequeue(&checkout1, &customer);
						printf("\n%s from queue 1 has been serviced.", customer);
						free(customer);
				}
				else if(!QU_empty(checkout2))
				{
						QU_dequeue(&checkout2, &customer);
						printf("\n%s from queue 2 has been serviced.", customer);
						free(customer);
				}
				else
				{
					printf("\nBoth queues are empty.");
				}
				break;
			case 3:
				printf("\nExited.");
				exit(0);
			default:
				printf("\nInvalid input.");
		}
	}
}
