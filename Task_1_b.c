#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STARTING_POINT 1
#define ZERO 0
#define MIN_NUMBER_LENGTH 0
#define NUM_DECREASING_VAR 10

void printMultTable(int MaxMult);
int numOfDig(int num);


void main()
{
	int maxMult;
	printf("Please enter number:\n");
	scanf("%d", &maxMult);
	printMultTable(maxMult);
}

/*The following function prints the multiplication table of MaxMult*/
void printMultTable(int MaxMult)
{
	int k, j;
	int numLen;
	for (k=STARTING_POINT; k <= MaxMult; k++)
	{
		
		for (j = STARTING_POINT; j < MaxMult; j++)
		{
			numLen = numOfDig(j * MaxMult);//checking the length of the last num on the colloum
			printf("%*d ", numLen, k * j);//printing by the length of the longest length in the colloum
		}
		numLen = numOfDig(j * MaxMult);
		printf("%*d\n", numLen, k * j);

	}
}
//The following function gets number and returns the numebr of digits
int numOfDig(int num)
{
	int counter = MIN_NUMBER_LENGTH;
	while (num > ZERO)
	{
		counter++;
		num /= NUM_DECREASING_VAR;
	}
	return counter;
}