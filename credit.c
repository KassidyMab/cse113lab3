/**
 * @file credit.c
 * @author
 * @date
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1
#define SIZE 32

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);

int main(void)
{
	int card[NUM_DIGITS];
        /* use visa to store the credit card number from stdin */
        char visa[SIZE + 1];

	convert_card(card, visa, NUM_DIGITS);
	print_card(card, NUM_DIGITS);

	return 0;

}

void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)
		card[i] = num[i] - '0';

}


void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}
