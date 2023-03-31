#include <stdio.h>
#include <stdlib.h>
#include "metathematic.h"

int main(void)
{
	char c;
	STACK st;
	ST_init(&st);
	double x;
	double y1, y2;
	printf("Give the metathematic expression: ");
	c = getchar();
	while(c != 'x')
	{
		if(c >= '0' && c <= '9')
		{
			x = c - '0';
			ST_push(&st, x);
		}
		else
		{
			ST_pop(&st, &y1);
			ST_pop(&st, &y2);
			switch(c)
			{
				case('+'):
					x = y1 + y2;
					break;
				case('-'):
					x = y2 - y1;
					break;
				case('*'):
					x = y1 * y2;
					break;
				case('/'):
					x = y2 / y1;
					break;
			}
			ST_push(&st, x);
		}
		c = getchar();
	}
	ST_pop(&st, &x);
	printf("Outcome: %.3f", x);
}
