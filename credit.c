 /**
 * @file lab3.c
 *
 * @author Kassidy Maberry
 *
 * @date 2/21/2022
 *
 * Assignment: Lab 3
 *
 * @brief a program that uses the luhns algorithm to verify a card.
 *
 * @details The program will take a user input and then run it through the
 * luhns algorithm to verify that the card is a true card.
 *
 * @bugs none
 *
 * @todo none
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1

void print_card(int card[], int size);
void arradouble(int card[]);
int cardadd(int card[]);
int cardver(int card);
void convert_card(int card[], char copy[]);
void read(char card[], int tof);

int main(void)
{
	char visa[17];
	int card[16];
	convert_card(card, visa);
	arradouble(card);


	int total = cardver(cardadd(card));
	read(visa, total);
	return 0;
}

/**
 * Reads out the original user input and then if the card is valid or not.
 * @param card[] is the origial card input.
 * @param tof is used to check if it is a valid input.
 */
void read(char card[], int tof)
{
	
	for (int i = 0; i < 16; i++){
		printf("%c", card[i]);
	}
	printf(" is a ");
	if (tof == 0){
		printf("valid card");
	} else {
		printf("invalid card");
	}
	printf(".\n");
}


/**
 * Takes the users input, copies it to another array to save the character
 * inputs, and then converts an array into integers.
 * @param card[] a interger array for calculations.
 * @param copy[] a character array for printing out.
 */
void convert_card(int card[], char copy[])
{
	// 50 element array to prevent the user from overflowing it's values.
        char visa[50];
        char i, tmp;
	int len = 0;
	printf("Please enter a card number: ");
	fgets(visa, 20, stdin);

	for (i = 0; i < 16; i++){		
		copy[i] = visa[i];
		card[i] = visa[i] - '0';
	}
	copy[16] = '\0';

}



/**
 * A function that goes through and multiplies every even digit and zero by
 * 2. Updating the arrary.
 * 
 * @param card The digits on the card.
 */
void arradouble(int card[])
{
	
	for(int i = 0; i < NUM_DIGITS-1; i++)
	{
		if (i%2 == 0 || i == 0){
		card[i] = card[i] * 2;
		} 
	
	}
}


/**
 * Adds the digits of the cards together. If a single digit of
 * the number is two digits it is then modulated by 10 and a one is 
 * added.
 * @param card The current cards numbers.
 * @return total The value of all of the numbers added together.
 */
int cardadd(int card[])
{
	int total = 0;
	for (int i = 0; i < 16; i++)
	{
		if (card [i] > 10){
			total = total + 1 + (card[i]%10);
		} else {
			total = total + card[i];
		}
	}
	
	return total;
}

/**
 * A function that checks if the modulus of the number by 10 is zero
 * if it is zero it returns valid otherwise it is invalid.
 * @param total The added amount of each credit card value after theyve been
 * compiled.
 * @return A true or false statement mentioning if it is valid or not. 
 */
int cardver(int total)
{
	if (total%10 == 0){
		return VALID;
	} else {
		return INVALID;
	}
}




/**
 * A function that prints out the value of each card number
 * @param The card's number
 * @param The length of the card.
 */
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

