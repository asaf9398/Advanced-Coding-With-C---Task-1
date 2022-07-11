#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NUM_FOR_MULTIPLICAION_TABLE 10
#define STARTING_POINT 1

void printingMultiplicationTableOfTen();


void main()
{
	printingMultiplicationTableOfTen();
}

/*The following function prints the multiplication table of 10*/
void printingMultiplicationTableOfTen()
{
	int i,k;
	for ( i = STARTING_POINT; i <= NUM_FOR_MULTIPLICAION_TABLE; i++)
	{
		for (k = STARTING_POINT; k < NUM_FOR_MULTIPLICAION_TABLE; k++)
		{

			printf("%2d ", i * k);
		}
		//printing with 3 digits on the 10th collum because 100 has 3 digits
		printf("%3d\n", i * k);	
	}

}