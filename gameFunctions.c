/*
Card 
Game
Author: Brianna
Student ID: []
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: contains functions for the game that are called in the main.c
*/
#include "gameFunctions.h"

//a function that adds the card to the player's winning pile by calling
// the appropriate function from card_LList and update the cards won.
// Also marks the card as taken ('0').
void addCardToPlayer(Player* thePlayer, Card* theCard){
    //insert to end of win pile
    thePlayer->cardsWon += 1;
    insertEndCard_LList(&(thePlayer->winPile), theCard);
    theCard->value = '0';
}

//a function that checks if the user choice is valid:
// if any of the choices are invalid, report that and return false.
bool checkPlayerInput(Deck* theDeck, Player* thePlayer, char row, char col){
    //printf("inputted r=%d c=%d\n", row, col);
    //check if row and col in bounds
    if (row > 47 && row < 52){
        if (col > 96 && col < 110){
            //char arithmetic to convert into int
            if(theDeck->cards[((row-48)*13)+(col-97)].value == '0'){//check if card val is '0'
                printf("That card is already taken\n");
                return false;
            }
            return true;
        }
    }
    printf("invalid input\n");
    return false;
}

//a function that checks if there is a match:
// if the two choices are the same, report it and return false.
// if there is a match, return true; otherwise, return false.
bool checkForMatch(Deck* theDeck, Player* thePlayer,
                      char r1, char c1, char r2, char c2){
    //if same row and col then same card
    if (r1 == r2 && c1 == c2){
        printf("Error: same card\n");
        return false;
    }
    else{
        int ind1 = (r1-48)*13 + (c1-97);//char arithmetic to find index
        int ind2 = (r2-48)*13 + (c2-97);
        int val1 = theDeck->cards[ind1].value;//store card values in a new variable
        int val2 = theDeck->cards[ind2].value;
        if (val1 == val2){//check if same value
            return true;
        }
    }
    return false;
}

//a function that checks if the game has a winner
// (all cards in the deck is taken)
bool checkForWinner(const Deck* theDeck){
    //loop through all cards return false if there's a card without value 0
    for (int i = 0; i<NUM_OF_CARDS_IN_DECK; i++){
        if (theDeck->cards[i].value != '0'){
            return false;
        }
    }
    return true;
}
