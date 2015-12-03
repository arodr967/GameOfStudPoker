/*  
	File name: pokerhand.c
*/
#include "suit.h"

/**************************************
Determine whether a player has a Royal Flush.
A Royal Flush is a straight from ten to an ace
with all five cards of the same suit. In poker,
all suits are ranked equally. -Alicia
**************************************/
int isRoyalFlush(struct player gamer, int numberOfCards)
{
	//struct card *cards int numberOfCards;

	int tempValue, firstCard, currentCard = 0;
	int value = 10; /* Starting value for a royal flush. Might want to
					   put a constant for this later. */
	char *suit1 = gamer.hand[firstCard].suit;	/* Get the suit of the first card... */
	char *suit2; /* Get the suit of the second card to compare suit1 with. */

	//for (hand = 0; hand < numberOfCards; hand++)
	//{
		while (currentCard < numberOfCards)
		{
			if (currentCard + 1 < numberOfCards) {
				suit2 = gamer.hand[currentCard + 1].suit;
			}

			tempValue = gamer.hand[currentCard].value;	/* Get the value of the card... */

			if ((tempValue == value) && (suit1 == suit2))
			{
				value++; /* Evaluate the next value */
				//return TRUE;
			}
			else {
				return NONE; /* Otherwise, it is not a Royal Flush */
				//break; /* Not sure if I can do this here... */
			}
			currentCard++; /* Continue to the next card */
		}
	//}
	return ROYAL_FLUSH;
}

/**************************************
Determine whether a player has a Straight
Flush. A Straight Flush is any straight with
all five cards of the same suit. -Alicia
**************************************/
int isStraightFlush(struct player gamer, int numberOfCards)
{
	if (isStraight(gamer, numberOfCards) && isFlush(gamer, numberOfCards))
		return STRAIGHT_FLUSH;

	else
		return NONE;
}

/**************************************
Determine whether a player has a Flush.
A Flush is any five cards of the same suit
(not consecutive). -Alicia
**************************************/
int isFlush(struct player gamer, int numberOfCards)
{
	int firstCard, currentCard = 0;

	char *suit1 = gamer.hand[firstCard].suit;	/* Get the suit of the first card... */
	char *suit2; /* Get the suit of the second card to compare suit1 with. */

	while (currentCard < numberOfCards)
	{
		if (currentCard + 1 < numberOfCards) {
			suit2 = gamer.hand[currentCard + 1].suit;
		}

		if (suit1 != suit2) { 
			return NONE;
		}
		currentCard++; /* Continue to the next card */
	}

	return FLUSH;
}

/**************************************
Determine whether a player has a Straight.
A Straight is any five consecutive cards of
different suits. -Alicia
**************************************/
int isStraight(struct player gamer, int numberOfCards)
{
	int currentCard = 0;
	int value1, value2;

	while (currentCard < numberOfCards)
	{
		value1 = gamer.hand[currentCard].value;

		if (currentCard + 1 < numberOfCards) {
			value2 = gamer.hand[currentCard + 1].value;
		}

		if (value1++ != value2) {
			return NONE;
		}
		currentCard++; /* Continue to the next card */
	}

	return STRAIGHT;
}

/**************************************
Determine whether a player has a High Card.
A High Card is any hand that is not the ones 
already defined. -Paola
**************************************/
int hasHighCard(struct deck *deckptr, int numberOfCards, int numberOfPlayers){
    
    /* instance var's and LOOP 1 var's*/
    int player = 1, cardValue, countCards = numberOfPlayers*numberOfCards, playersHighCard = 1, getCard;
    int cNum = numberOfCards, count = 0;

    /* compilation of each player's highest card in hand */
    struct card HighCards[numberOfPlayers];

    /* LOOP 2 var's*/
    int pNum = 1;
    int maxVal, tempVal;
    int highestInHand[numberOfPlayers+1];

    /* LOOP 1: make a list of each player's highest card in hand */
    for(;player < numberOfPlayers; player++){
        while (countCards > 0){
            playersHighCard++;
            if(playersHighCard == cNum){

                /* current player's high card found here */
                getCard = deckptr->cards[playersHighCard-1].value;   

                HighCards[player] = deckptr->cards[playersHighCard-1];
                printf("GETTING CARD %d\n", HighCards[player].value);
                cNum+=numberOfCards;
            }
              countCards--;       
        } 
    }
    printf("GETTING CARD %d\n", HighCards[1].value);
    printf("GETTING CARD %d\n", HighCards[2].value);
    printf("GETTING CARD %d\n", HighCards[3].value);
    printf("GETTING CARD %d\n", HighCards[4].value);
    printf("GETTING CARD %d\n", HighCards[5].value);

    maxVal = HighCards[3].value;
    printf("PLAYER 1 HIGH CARD VAL %d\n", maxVal );
    printf("PLAYER 2 HIGH CARD VAL %d\n", maxVal );
    printf("PLAYER 3 HIGH CARD VAL %d\n", maxVal );
    printf("PLAYER 4 HIGH CARD VAL %d\n", maxVal );
    printf("PLAYER 5 HIGH CARD VAL %d\n", maxVal );

    /* LOOP 2*/
    /* Which player has high card? */

    // while(pNum < numberOfPlayers){

    //     printf("HERE\n");
    //     maxVal = HighCards[pNum]->value;
    //     tempVal = HighCards[pNum+1]->value;

    //     printf("PLAYER %d HAS CARD %d\n",pNum, maxVal);

    //     printf("PLAYER %d HAS CARD %d\n",pNum+1, tempVal);
    //     if(tempVal>maxVal){
    //          maxVal = tempVal;    /* highest by far */
    //     }
    //     else{
    //          highestInHand[pNum]=TRUE;
    //     }
    //     printf("%d\n", highestInHand[pNum]);

    //     pNum++;
    //     printf("HERE 2\n");
    // }

    return TRUE;    
}

int findHighCard(struct players *currentPlayers, int numberOfPlayers, int numberOfCards) {
    int i, maxVal, playerWithHighCard = 0;
    maxVal = currentPlayers[0].hand[numberOfCards-1].value;
    
    for (i = 1; i<numberOfPlayers; i++) {
        if(currentPlayers[i].hand[numberOfCards-1].value > maxVal) {
            maxVal = currentPlayers[i].hand[numberOfCards-1].value;
            playerWithHighCard = i;
        }
    }
    
    printf("The max valued card is [%d] and Player [%d] has it\n", maxVal, playerWithHighCard);
    return playerWithHighCard;
}
