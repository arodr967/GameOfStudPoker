/*
  File name: suit.h
  Description: Header file which contains all of the constants, libraries, structures, and prototypes.
*/

#ifndef suit_h
#define suit_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>           // for the use of rand() and srand()
#define DECK_SIZE 52
#define MAX_NUM_PLAYERS 7          // from 1 to 1 players allowd in Stud poker -Alicia
#define PLAYER_MIN 1
#define MAX_CARDS_PER_HAND 5       // only 5 or 7 cards per hand. In this game we are choosing 5 -Alicia
#define MIN_CARDS_PER_HAND 5	   // setting the min to also be 5 because it cannot be lower.	-Alicia
#define NUM_SUITS 4
#define NUM_VALUES 13		//Added the number of values -Alicia
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14
#define ARGNUM 3
#define CARD_INPUT 1
#define PLAYER_INPUT 2
#define TRUE 1
#define FALSE 0

/*
// suit symbols cross platform
#if defined(_WIN32) || defined(_MSDOS_)
#define SPADE	"S"
#define CLUB	"C"
#define HEART	"H"
#define DIAMOND	"D"
#else
#define SPADE	"\xe2\x99\xa4"
#define CLUB	"\xe2\x99\xa7"
#define HEART	"\xe2\x99\xa5"
#define DIAMOND	"\xe2\x99\xa6"
#endif
*/

/* Display the suits with their letter. */
#define SPADE	"S"
#define CLUB	"C"
#define HEART	"H"
#define DIAMOND	"D"

/************************************
 Simulates a card with suit and value.
 ************************************/
struct card{
    char *suit;
    int value;
};

/************************************
 Define a deck of card.
 ************************************/
struct deck{
    int numCards;
    struct card cards[DECK_SIZE];
};

/***********************************
 Player.
 ***********************************/
struct player{
    card hand[MAX_CARDS_PER_HAND];
    int cardnum;
};

/***********************************
 Prototypes.
 ***********************************/ 
enum ranks {ROYAL_FLUSH = 0, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, ONE_PAIR, HIGH_CARD, NONE};
int validateInput(int numberOfCards, int numberOfPlayers);
char getValue(int type);
void printDeck(struct deck *newDeck);
struct deck createDeck();
int randValue();
void shuffle(struct deck *theDeck);
void deal( struct deck *thedeck, int numCardsPerHand, int numOfPlayers);
void displayHands(struct card *players, int numOfPlayers, int numCardsPerHand);
struct players getHand(int cnum, struct deck *deckpointer, int *handpointer);
void sortHands( struct deck *deckptr, int pnum, int cnum);
void sort(struct card *player, int numberOfCards, int players, int passnum);
void rankHands(struct players gamer[], int numberOfCards, int numberOfPlayers);
int getMin(int ranks[]);
int isRoyalFlush(struct player gamer, int numberOfCards);
int isHighCard();
int isFlush(struct player gamer, int numberOfCards);
int isStraightFlush(struct player gamer, int numberOfCards);
int isFlush(struct player gamer, int numberOfCards);

#endif /* suit_h */
