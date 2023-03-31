//include all the libraries needed
#include <stdio.h>
#include <stdlib.h>
#include "binary_stack.h"

int main(void)
{
	//nesseccary inits and decls
	int decimal;
	STACK binary;
	ST_init(&binary);
	//get the decimal number
	do
	{
		printf("Give me a decimal number between 0 and 255: ");
		scanf("%d", &decimal);
	}
	while(!(decimal >= 0 && decimal < 256));
	int number = decimal;
	
	//turn dec into bin
	
	while(number >= 1)
	{
		ST_push(&binary, number%2);
		number = number/2;
	}
	
	//print the bin number
	printf("Binary repr of %d: ", decimal);
	while(!ST_empty(binary))
	{
		ST_pop(&binary, &number);
		printf("%d", number);
	}
}
