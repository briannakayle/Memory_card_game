/*
CMPT 125 Assignment 4 Game
Author: Brianna Espena
Student ID: 301433268
SFU email: bke1@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: contains functions for the game that are used in the main.c
*/
#include "gameObjects.h"

//a function that initializes all the fields of a Deck.
// For each suit, the values of the cards are
// ‘A’, ‘2’, ‘3’, …, ‘9’, ,'T', ‘J’, ‘Q’, ‘K’.
void initializeDeck(Deck* theDeck, char* brandName){
    theDeck->brand = brandName;
    char value_arr[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    int i=0;
    int j=0;
    
    for(j=0; j<13; j++) // sets first 13 to spades and respective value same concept for next 3 for loops
	{
		theDeck->cards[j].suit = Spades;
		theDeck->cards[j].value = value_arr[i];
		i++;
	}

    i=0;
	for(j=13; j<26; j++){
		theDeck->cards[j].suit = Hearts;
		theDeck->cards[j].value = value_arr[i];
		i++;
	}

	i=0;
	for(j=26; j<39; j++){
		theDeck->cards[j].suit = Clubs;
		theDeck->cards[j].value = value_arr[i];
		i++;
	}

	i=0;
	for(int j=39; j<52; j++){
		theDeck->cards[j].suit = Diamonds;
		theDeck->cards[j].value = value_arr[i];
		i++;
	}
}

//a function that shuffles the deck
void shuffleDeck(Deck* theDeck){
    int n = NUM_OF_CARDS_IN_DECK;
    int i;
    if (n > 1) {
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          Card t = theDeck->cards[j];
          theDeck->cards[j] = theDeck->cards[i];
          theDeck->cards[i] = t;
        }
    }
}

//a function that prints the content of a Deck.
//accepts a second bool parameter:
//if true, print face up, if false, print face down.
//if the card is won by a player, leave it blank.
void printDeck(const Deck* theDeck, bool faceUp){
    printf("  ");
    int ch = 97;
    //prints the columns (a, b, c, ..., m)
    for (int i = 0; i<13; i++){
        printf("%c  ", ch);
        ch++;
    }
    printf("\n");
    if (faceUp){
        for (int i = 0; i<4; i++){
            printf("%d ", i);// prints the rows (0-3)
                for (int j = 0; j<13; j++){ //loop to print the cards
                    if(theDeck->cards[(i*13) +j].value != '0'){ // check if card is taken
                        //print card depending on suit
                        if (theDeck->cards[(i*13) +j].suit == 0){
                            printf("%c", theDeck->cards[(i*13) +j].value);
                            printf("\u2660 ");
                        }
                        else if (theDeck->cards[(i*13) +j].suit == 1){
                            printf("%c", theDeck->cards[(i*13) +j].value);
                            printf("\u2661 ");
                        }
                        else if (theDeck->cards[(i*13) +j].suit == 2){
                            printf("%c", theDeck->cards[(i*13) +j].value);
                            printf("\u2663 ");
                        }
                        else if (theDeck->cards[(i*13) +j].suit == 3){
                            printf("%c", theDeck->cards[(i*13) +j].value);
                            printf("\u2662 ");
                        }
                    }else{
                        printf("   ");//if cards is taken
                        
                    }
                }
            printf("\n");
            
        }
    }
    else if(!faceUp){
        //print rows (0-3)
        for (int i = 0; i<4; i++){
            printf("%d ", i);
            //loop to print card facing down if not taken
            for (int j =0; j<13; j++){
                //check if card is taken 
                if(theDeck->cards[(i*13) +j].value != '0'){ 
                    printf("%c\u218C ", '?');
                }
                else{
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
}


//a function that initializes all the fields of a Player.
void initializePlayer(Player* thePlayer, char* theName){
    //initialize player name, cards won and winpile
    thePlayer->name = theName;
    thePlayer->cardsWon = 0;
    thePlayer->winPile.head = NULL;
    thePlayer->winPile.tail = NULL;
}

//a function clears the winning pile of the player by calling the necessary
// function on a Card_LList.
void clearPlayer(Player* thePlayer){
    clearCard_LList(&thePlayer->winPile);
}