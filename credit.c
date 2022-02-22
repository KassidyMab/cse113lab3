/**
 * @file prelab_credit.c
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

void print_card(int card[], int size);
void arradouble(int card[]);
int cardadd(int card[]);
int cardver(int card);
int digitize(char digit);
void convert_card(int card[], char copy[]);
void read(char card[], int tof);

int main(void)
{
	char visa[16];
	int card[16];
	convert_card(card, visa);

	arradouble(card);

	int total = cardver(cardadd(card));
	read(visa, total);
	return 0;
}


void read(char card[], int tof)
{

	for (int i = 0; i < 0; i++){
		printf("%c", card[i]);
	}
	printf("is a ");
	if (tof == 0){
		printf("valid card");
	} else {
		printf("invalid card");
	}
	printf(".\n");
}

void convert_card(int card[], char copy[])
{
	// 50 element array to prevent the user from overflowing it's values.
        char visa[50];
        char i, tmp;
	int len = 0;
        while ((tmp = getchar()) != '\n'){
                visa[len] = tmp;
                len++; 
        }


	for (i = 0; i < 16; i++){
		// I is compared to len to make incase its less than 16 digits.
		if (i < len){
			card [i] = copy[i];
			card[i] = digitize(visa[i]);
		} else {
			copy[i] = '0';
			card[i] = 0;
		}
	}

}


int digitize(char digit)
{
	switch (digit)
	{
	case ('0'):
		return 0;
	case('1'):
		return 1;
	case('2'): 
		return 2;
	case('3'):
		return 3;
	case('4'):
		return 4;
	case('5'):
		return 5;
	case('6'):
		return 6;
	case('7'):
		return 7;
	case('8'):
		return 8;
	case('9'):
		return 9;
	// If anything but those characters are given it's defualted as a zero.
	default:
		return 0;
	}


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
 * @brief Adds the digits of the cards together. If a single digit of
 * the number is two digits it is then modulated by 10 and a one is 
 * added.
 * 
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
	printf("%d", total);
	return total;
}

/**
 * @brief A function that checks if the modulus of the number by 10 is zero
 * if it is zero it returns valid otherwise it is invalid.
 * 
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
 * @brief A function that prints out the value of each card number
 * 
 * @param The card's number
 * @param The length of the card.
 */
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

