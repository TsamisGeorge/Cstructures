#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"

main()
{
	STACK st;
	ST_init(&st);
	int x = 5;
	ST_push(&st, x);
	//LL_print(st);
	x = 7;
	ST_push(&st, x);
	ST_print(st);
	ST_pop(&st, &x);
	printf("\n");
	ST_print(st);
	ST_destroy(&st);
}
