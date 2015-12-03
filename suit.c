/*
 File name: suit.c

 Description: The suit file which includes all of the methods needed to play the Stud poker game.
 
 */
#include "suit.h"

/************************************
 Validate user input -Alicia & Hector
 ************************************/
int validateInput(int numberOfCards, int numberOfPlayers)
{
    int total = numberOfCards * numberOfPlayers;
    
    printf("\n\nNumber of cards per player: %d and number of players: %d\n\n", numberOfCards, numberOfPlayers);
    printf("The total number of card(s) is %d.\n\n", total);
    
    if (((total > DECK_SIZE) || (total == 0)))
    {
        printf("There are only %d cards in total available. Please try again.\n\n", DECK_SIZE);
        return FALSE; //invalid input
    }
    else if ((numberOfPlayers < PLAYER_MIN) || (numberOfPlayers > MAX_NUM_PLAYERS))
    {
        printf("There can only be a minimum of %d player(s) and a maximum of %d players. Please try again.\n\n", PLAYER_MIN, MAX_NUM_PLAYERS);
        return FALSE; //invalid input
    }
    else if ((numberOfCards < MIN_CARDS_PER_HAND) || (numberOfCards > MAX_CARDS_PER_HAND))
    {
        printf("There can only be %d card(s) per hand. Please try again.\n\n", MAX_CARDS_PER_HAND);
        return FALSE; //invalid input
    } else {
        printf("Your input is valid.\n\n");
        return TRUE; //valid input
    }
}

/************************************
 Represents a suit.
 ************************************/
char getValue(int type){
    
    switch(type){
            
        case 11:
            return 'J'; /* Jack */
        case 12:
            return 'Q'; /* Queen */
        case 13:
            return 'K'; /* King */
        case 14:
            return 'A'; /* Ace */
    }
    return '~';
}

/************************************
 Simulates a deck of cards.
 ************************************/
struct deck createDeck(){
    int i, j, index = 0;                 /* local var's */
    char *suits[NUM_SUITS] = {SPADE, CLUB, HEART, DIAMOND};
    struct deck newDeck;
    
    /* Populate the Deck with 52 cards, 13 values per suit */
    
    for(i = 0; i < NUM_SUITS;i++){
        for (j = 2; j <= NUM_VALUES + 1; j++) { //Fixed error with the number of values when creating the deck. -Alicia
            
            /* compose array of values */
            newDeck.cards[index].value = j;
            
            /* compose array of suits */
            newDeck.cards[index].suit = suits[i];
            index++;
        }
    }
    return newDeck;
}

/*************************************
 Output Deck to screen.
 *************************************/
void printDeck(struct deck *newDeck){
    int i, j,index = 0, temp;
    char special;
    
    /* Populate the Deck with 52 cards, 13 values per suit */
    
    for(i = 0; i < NUM_SUITS;i++){
		for (j = 1; j <= NUM_VALUES; j++) {
            temp = newDeck->cards[index].value;
            if (temp == JACK || temp == QUEEN || temp == KING || temp == ACE)
            {
                special = getValue(temp);
                printf(" [ %2c%s ] ", special, newDeck->cards[index].suit);
            }
            else{
                printf(" [ %2d%s ] ",newDeck->cards[index].value , newDeck->cards[index].suit);
            }
            index++;
        }
        printf("\n");
    }
}

/**************************************
 Shuffles the deck.
 **************************************/
void shuffle(struct deck *theDeck){
    
    int randon, index;                /* intance var's */
    
    /* swap the values with arbitrary value */
    
    for (index = 0; index < DECK_SIZE; index++){
        
        randon = rand() % DECK_SIZE;
        struct card temp = theDeck->cards[index];
        theDeck->cards[index] = theDeck->cards[randon];
        theDeck->cards[randon] = temp;
        
    }
}

/**************************************
 This function deals the deck for
 specific number of players.
 **************************************/
void deal( struct deck *deckptr, int cnum, int pnum){

    /* variables used */
    int cardNum, card, currentCard = 0;
    
    /* simulates hands specified by user */
    struct card *players[cnum];
    
    printf("\nYou have specified %d hand(s) with %d card(s) each..\n", pnum, cnum);
    printf("\nDealing deck...\n\n");
    
    for (cardNum = 0; cardNum < cnum ; cardNum++) {
        printf("%d",cardNum);
            players[cardNum] = &deckptr->cards[currentCard];
            currentCard++;
    }
    displayHands(*players, cnum, pnum); /* print players hands */
}

struct players deal2 (int numberOfCards, struct deck *deckptr) {
    
    
    struct players newPlayer;
    int i;
    
    printf("\nDealing deck...\n\n");
    
    for (i = 0; i < numberOfCards; i++ ) {
        newPlayer.hand[i] = deckptr->cards[deckptr->numCards];
        deckptr->numCards++;
        newPlayer.cardsInHand++;
    }
    
    return newPlayer;
    
}

/*************************************
 Display players hands.
 *************************************/
void displayHands(struct card *players, int cnum, int pnum){

    /* variables used */
    int temp, player, playerNum, currentCard = 0;
    char special;
    
    /* here, traverse the hands and display them all */
    for (playerNum = 1; playerNum <= pnum; playerNum++) {
        
        
        printf("Player %d 's cards:\n", playerNum);
        
        for (player = 0; player < cnum; player++) {
        
            temp = players[currentCard].value;  /* for suits */
    
            if (temp == JACK || temp == QUEEN || temp == KING || temp == ACE)
            {
                special = getValue(temp);   /* display appropriate suit */
                
                printf(" [ %2c%s ] ",special, players[currentCard].suit);
            }else{
                printf(" [ %2d%s ] ",players[currentCard].value , players[currentCard].suit);
            }
            currentCard++;
        }
        printf("\n");
    }
}

void displayHands2(struct players *currentPlayers, int numberOfCards, int pnum, int cnum) {
    
    /* variables used */
    int temp, player, playerNum, currentCard = 0;
    char special;
    
    /* here, traverse the hands and display them all */
    for (playerNum = 0; playerNum < pnum; playerNum++) {
        
        
        printf("Player %d 's cards:\n", playerNum);
        
        for (player = 0; player < cnum; player++) {
            
            temp = currentPlayers[playerNum].hand[player].value;  /* for suits */
            
            if (temp == JACK || temp == QUEEN || temp == KING || temp == ACE)
            {
                special = getValue(temp);   /* display appropriate suit */
                
                printf(" [ %2c%s ] ",special, currentPlayers[playerNum].hand[player].suit);
            }else{
                printf(" [ %2d%s ] ",currentPlayers[playerNum].hand[player].value , currentPlayers[playerNum].hand[player].suit);
            }
            currentCard++;
        }
        printf("\n");
    }
    printf("\n");
}

/*************************************
 Return the hands.
 *************************************/
struct players getHand(int cnum, struct deck *deckpointer, int *handpointer){
    
    int index;
    struct players player;
    
    for(index = 0; index < cnum; index++){
        player.hand[index] = deckpointer->cards[*handpointer];
        *handpointer = *handpointer + 1;
        player.cardnum++;
    }
    return player;
}

/**************************************
 Goes through each player's hands
 and sorts them in ascending order.
 -Paola
 **************************************/
void sortHands( struct deck *deckptr, int cnum, int pnum){


    /* variables used */
    int cardNum, card = 0, currentCard = 0, count = 0, passnum = 0, cardsPerPlayer = cnum; 
    
    /* simulates hands specified by user */
    struct card *players[cnum];

    printf("\nSorting hands...\n\n");

    for (cardNum = 0; cardNum < cnum ; cardNum++) {
        
        /* all cards go to single player */
        if (pnum == DECK_SIZE-1) {
            
            for (; card < pnum; card++) {
                players[card] = &deckptr->cards[currentCard];
                currentCard++;
            }
        }else{
            players[cardNum] = &deckptr->cards[currentCard];
            currentCard++;
        }
        /* sort each player's hand */
        while(count < pnum){
            sort(*players, cardsPerPlayer, pnum, passnum);
            passnum += cnum;
            cardsPerPlayer += cnum;
            count++;
        }
    }  
    displayHands(*players, cnum, pnum); /* print sorted hands */
    printf("\n");

}

void sortHands2(struct players *currentPlayers, int cnum, int pnum) {
    
    /* variables used */
    int cardNum, card = 0, currentCard = 0, count = 0, passnum = 0, cardsPerPlayer = cnum;
    int i, j;
    
    /* simulates hands specified by user */
    
    printf("\nSorting hands...\n\n");
    
    for (i = 0; i < pnum ; i++) {
        sort2(currentPlayers[i].hand, cnum);
        
    }
    printf("\n");
    
}

void sort2(struct card *hand, int numberOfCards) {
    
    
    int i, j, minValueCard, minIndex;
    struct card temp;
    
    for (i = 0; i < numberOfCards; i++) {
        minValueCard = hand[i].value;
        minIndex = i;
        for (j = i + 1; j < numberOfCards; j++) {
            
            if (hand[j].value < minValueCard) {
                minValueCard = hand[j].value;
                minIndex = j;
            }
        }
        temp = hand[i];
        hand[i] = hand[minIndex];
        hand[minIndex] = temp;
    }
    
}

/**************************************
     SelectionSort helper function.
      -Paola
 **************************************/
void sort(struct card *player, int numberOfCards, int numplayers, int passnum){

    /* variables used */
    int pass = passnum, k, min, minIndex, pnum = numplayers;
    struct card temp;

    /* traverse and sort each hand by defining and comparing min values */
        for (; pass < numberOfCards; pass++)
        {

            min = player[pass].value;
            minIndex = pass;
            for (k = pass + 1; k < numberOfCards; k++)
            {
                if (player[k].value < min)
                {
                    min = player[k].value;
                    minIndex = k;
                }
            }
            /* swap cards after finding min, placing all in ascending order */
            temp = player[pass];
            player[pass] = player[minIndex];
            player[minIndex] = temp;
       }
   
    return;
}

/**************************************
Function which will determine what type of
hand each player has and ranks them.
-Alicia
**************************************/
void rankHands(struct player gamer[], int numberOfCards, int numberOfPlayers)
{
	int pnum;
	//struct card *cards[numberOfCards];

	//create an array which will be used to check which player has the best hand
	int playerCheck[numberOfPlayers + 1];

	//traverse through the each players
	for (pnum = 1; pnum <= numberOfPlayers; pnum++)
	{
		/* set the playercheck array with the minimum number for each player
		   that is returned when checking what rank is it. */

		/* e.g. ) so, playerCheck[1] is going to have
		   the hand which is returned by applying all of the checks, 
		   but it will get the minimum because that would be the best hand
		   for that specific player... and so on.*/
		playerCheck[pnum] = getMin([isRoyalFlush(gamer[pnum], numberOfCards)]);
	}

	//then here another for loop which will determine the winner.

}

/**************************************
Function which will get an int array
of all of the ranks, (which return ints), 
and return the minimum of those ranks
because that will be the best rank.
-Alicia
**************************************/
int getMin(int ranks[])
{
	//int royalFlush, int straightFlush, int fourOfAKind, 
	//int fullHouse, int flush, int straight, int threeOfAKind, int twoPair, int onePair
	int min = NONE;
	int i;

	for (i = 0; i < 9; i++) //must create constant for 9. 9 is how many cards are being tested.
	{
		if (ranks[i] < min)
			min = ranks[i];
	}

	return min;
}
