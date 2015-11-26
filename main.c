/*
 File name: main.c

 Disclaimer: We hereby certify that this collective work is our own
 and none of it is the work of any other person or entity.
 
 Created by Alicia Rodriguez, Paola Jiron, and Hector Mejia.

 Description: Can be added later.
 */
#include "suit.h"

int main(int argc, const char * argv[]) {
    
    /* local variables used here */
    
    int max, numCardsPerHand, numOfPlayers, i, j, cardsPtr = 0, *ptr = &cardsPtr;
    struct deck thedeck, *pointer = &thedeck;
    thedeck = createDeck();
    struct players gamer [MAX_NUM_PLAYERS];
    time_t t;
    
    srand((unsigned)time(&t));               // generate seed for random value
    
    /* validation of user input. No more than 3 args. */
    if( argc == ARGNUM ){
        
        /* parse the arguments to integer values
         and compute maximum legal values allowed
         for game */
        
        numCardsPerHand = atoi(argv[CARD_INPUT]);
        numOfPlayers = atoi(argv[PLAYER_INPUT]);
        
       if(validateInput(numCardsPerHand, numOfPlayers)) /* If the validateInput function returns
                                                        a 1 then the inputs were correct and the 
                                                        game of cards can begin */
        {
            /* create and display deck, shuffle the deck,
             deal and display hands */
            
            thedeck = createDeck();
            printf("\nThe standard deck:\n\n");
            printDeck(pointer);
            printf("\nThe shuffled deck:\n\n");
            shuffle(pointer);
            printDeck(pointer);
            deal(pointer, numCardsPerHand, numOfPlayers);
            sortHands(pointer, numCardsPerHand, numOfPlayers);
			rankHands(pointer, numCardsPerHand, numOfPlayers);
        }
    }else{
        /* here as specified, display error and terminate due to incorrect number of args entered by user */
        
        printf("Sorry that is incorrect. You must enter the number of cards per hand\n");
        printf("followed by the number of players separated by a space.\n\n");
    }
    
    return 0;
}
