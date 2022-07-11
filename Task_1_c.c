#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_ARRAY_LENGTH 100 
#define STARTING_CELL 0 
#define FINISH_SEARCH -1
#define SAME_CHARACTER 0
#define MODULUE_CHAR '%'
#define MODULUE_STR "%"
#define LOWCASE_CHAR_D 'd'
#define LOWCASE_CHAR_X 'x'
#define LOWCASE_CHAR_O 'o'
#define LOWCASE_CHAR_B 'b'
#define LOWCASE_CHAR_R 'r'
#define CAPITAL_CHAR_M 'M'
#define CAPITAL_CHAR_D 'D'
#define CAPITAL_CHAR_I 'I'
#define CAPITAL_CHAR_X 'X'
#define CAPITAL_CHAR_V 'V'
#define CAPITAL_CHAR_C 'C'
#define CAPITAL_CHAR_L 'L'

void printFormattedIntegers(char format[], char numbers[]);
void searchingForFormat(char format[], int* startingIndex, int numbers[], int numberIndex);
bool checkInFormat(char ch);
void printByFormat(char ch, int number);
void printBinari(int number);
void printRomi(int number);
void predigit(char num1, char num2);
void postdigit(char c, int n);

char romanval[MAX_ARRAY_LENGTH];//array for the rome characters
int i = STARTING_CELL;
void main()
{
    char format[MAX_ARRAY_LENGTH];
    char numbers[MAX_ARRAY_LENGTH];
    gets(format);
    gets(numbers);

    printFormattedIntegers(format, numbers);
}
//The following function gets format of printing + numbers to print and prints it with the new format
void printFormattedIntegers(char format[], char numbers[])
{
    int numbersArr[MAX_ARRAY_LENGTH];
    int numberInd = 0;
    int counter = 0;
    char numbersSeps[] = " ";
    char* token;
    token = strtok(numbers, numbersSeps);
    int num;
    while (token != NULL)//getting all the numbers into an array
    {
        sscanf(token,"%d",&num);
        numbersArr[numberInd] = num;
        numberInd++;
        counter++;
        token = strtok(NULL, numbersSeps);
    }

    //searching for the % + correct character, while printing the string so far
    int foundModulueIndex = 0;
    numberInd = 0;
    searchingForFormat(format, &foundModulueIndex, numbersArr, numberInd);
    numberInd++;

    //running on the array for printing the correct formats
    while (foundModulueIndex != FINISH_SEARCH&&numberInd!=counter)//printing&scanning the string by the format
    {
        searchingForFormat(format, &foundModulueIndex, numbersArr, numberInd);
        numberInd++;
    }
    int j;
    int len = strlen(format);
    //After finishing dealing with the array - check if we need to print the rest of the array(and print it if we didn't get to the end)
    for ( j = foundModulueIndex; j < len; j++)
    {
        printf("%c", format[j]);

    }


}
//The following function gets the array and checks for % + specific characters, and prints the number by the format
void searchingForFormat(char format[], int* startingIndex, int numbers[], int numberIndex)
{
    int index = *startingIndex;
    int k;
    int arrLen = strlen(format);
    bool found = false;
    for (k = index; k < arrLen && !found; k++)
    {
        if (format[k] - MODULUE_CHAR == SAME_CHARACTER)
        {
            if (k + 1 < arrLen)//cheking that we're not getting out of the array
            {
                if (checkInFormat(format[k + 1]))//if it is an actual format than print the number with the correct format
                {
                    found = true;
                    printByFormat(format[k + 1], numbers[numberIndex]);
                }
                else
                {
                    printf(MODULUE_STR);
                    printf("%c", format[k + 1]);
                }
            }
        }
        else//if it is not "%" just print it
        {
            printf("%c", format[k]);
        }
    }
        *startingIndex = k + 2;//if we didn't finish to scan the array - save the last place


}
//The following function gets a character and checks if it is one of the formats
bool checkInFormat(char ch)
{
    if (ch - LOWCASE_CHAR_D == SAME_CHARACTER || ch - LOWCASE_CHAR_X== SAME_CHARACTER || ch - LOWCASE_CHAR_O == SAME_CHARACTER || ch - LOWCASE_CHAR_B == SAME_CHARACTER || ch - LOWCASE_CHAR_R == SAME_CHARACTER)
        return true;
    return false;
}
//The following function prints the char by the correct format
void printByFormat(char ch, int number)
{
    if (ch - LOWCASE_CHAR_D == SAME_CHARACTER)
    {
        printf("%d ", number);
    }

    if (ch - LOWCASE_CHAR_X == SAME_CHARACTER)
    {
        printf("%x ", number);
    }

    if (ch - LOWCASE_CHAR_O == SAME_CHARACTER)
    {
        printf("%o ", number);
    }

    if (ch - LOWCASE_CHAR_B == SAME_CHARACTER)
    {
        printBinari(number);
        printf(" ");
    }

    if (ch - LOWCASE_CHAR_R == SAME_CHARACTER)
    {
        printRomi(number);
    }


}
//The following function prints number in binary number
void printBinari(int number)
{
    //recursive function that prints the numbmer from lest to right with %2
    if (number == 0)
        return;
    printBinari(number / 2);
    printf("%d", number % 2);
}

//The following function prints number in rome numbers
void printRomi(int number)
{  
    int j;

    if (number <= 0)
    {
        printf("Invalid number");
    }
    while (number != 0)
    {/*Check if the number is greater than 1000 or 900 or 500
     or 400 or 100 or 90 or 50 or 40 or 10 or 9 or 5 or 4 or 1,
     And store it in an array of the rome number */
        if (number >= 1000)
        {
            postdigit(CAPITAL_CHAR_M, number / 1000);
            number = number - (number / 1000) * 1000;
        }
        else if (number >= 500)
        {
            if (number < (500 + 4 * 100))
            {
                postdigit(CAPITAL_CHAR_D, number / 500);
                number = number - (number / 500) * 500;
            }
            else
            {
                predigit(CAPITAL_CHAR_C, CAPITAL_CHAR_M);
                number = number - (1000 - 100);
            }
        }
        else if (number >= 100)
        {
            if (number < (100 + 3 * 100))
            {
                postdigit(CAPITAL_CHAR_C, number / 100);
                number = number - (number / 100) * 100;
            }
            else
            {
                predigit(CAPITAL_CHAR_L, CAPITAL_CHAR_D);
                number = number - (500 - 100);
            }
        }
        else if (number >= 50)
        {
            if (number < (50 + 4 * 10))
            {
                postdigit(CAPITAL_CHAR_L, number / 50);
                number = number - (number / 50) * 50;
            }
            else
            {
                predigit(CAPITAL_CHAR_X, CAPITAL_CHAR_C);
                number = number - (100 - 10);
            }
        }
        else if (number >= 10)
        {
            if (number < (10 + 3 * 10))
            {
                postdigit(CAPITAL_CHAR_X, number / 10);
                number = number - (number / 10) * 10;
            }
            else
            {
                predigit(CAPITAL_CHAR_X, CAPITAL_CHAR_L);
                number = number - (50 - 10);
            }
        }
        else if (number >= 5)
        {
            if (number < (5 + 4 * 1))
            {
                postdigit(CAPITAL_CHAR_V, number / 5);
                number = number - (number / 5) * 5;
            }
            else
            {
                predigit(CAPITAL_CHAR_I, CAPITAL_CHAR_X);
                number = number - (10 - 1);
            }
        }
        else if (number >= 1)
        {
            if (number < 4)
            {
                postdigit(CAPITAL_CHAR_I, number / 1);
                number = number - (number / 1) * 1;
            }
            else
            {
                predigit(CAPITAL_CHAR_I, CAPITAL_CHAR_V);
                number = number - (5 - 1);
            }
        }
    }
    //print the rome number
    for (j = 0; j < i; j++)
        printf("%c", romanval[j]);
}

//The following function puts in the array the previous rome digit
void predigit(char num1, char num2)
{
    romanval[i++] = num1;
    romanval[i++] = num2;
}

//The following function puts in the array the next rome digit
void postdigit(char c, int n)
{
    int j;
    for (j = 0; j < n; j++)
        romanval[i++] = c;
}