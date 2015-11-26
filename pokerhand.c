/*  
	File name: pokerhand.c
*/
#include "suit.h"

/**************************************
Determine whether a hand has a Royal Flush.
A Royal Flush is a straight from ten to an ace
with all five cards of the same suit. In poker,
all suits are ranked equally. -Alicia
**************************************/
int isRoyalFlush(struct card *cards, int numberOfCards)
{
	int tempValue, hand, firstCard, currentCard = 0;
	int value = 10; /* Starting value for a royal flush. Might want to
					   put a constant for this later. */
	char *suit1 = cards[firstCard].suit;	/* Get the suit of the first card... */
	char *suit2; /* Get the suit of the second card to compare suit1 with. */

	for (hand = 0; hand < numberOfCards; hand++)
	{
		while (currentCard < numberOfCards)
		{
			if (currentCard + 1 < numberOfCards) {
				suit2 = cards[currentCard + 1].suit;
			}

			tempValue = cards[currentCard].value;	/* Get the value of the card... */

			if ((tempValue == value) && (suit1 == suit2))
			{
				value++; /* Evaluate the next value */
				return TRUE;
			}
			else {
				return FALSE; /* Otherwise, it is not a Royal Flush */
				//break; /* Not sure if I can do this here... */
			}
			currentCard++; /* Continue to the next card */
		}
	}
	//return FALSE;
}

/**************************************
Determine whether a hand has a High Card.
A High Card is any hand that is not the ones 
already defined. -Alicia
**************************************/
int isHighCard()
{
	return TRUE;
}
