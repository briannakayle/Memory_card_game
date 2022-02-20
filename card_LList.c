/*
CMPT 125 Assignment 4 Game
Author: Brianna Espena
Student ID: []
SFU email: bke1@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: contains functions for the game that are called in the main.c and other .c files
*/

#include "card_LList.h"
#include <stdio.h>

//a function that creates a new Card_LList, which is an empty linked list.
Card_LList* createCard_LList(){
    //malloc a list
  Card_LList* LList = malloc(sizeof(Card_LList));
  //check for malloc failure
  if (LList == NULL){
      exit(0);
  }
  //set head and tail to NULL
  if(LList != NULL){
    LList->head = NULL;
    LList->tail = NULL;
  }
  return LList;
}

//a function that removes all the nodes from the list
// by freeing them one by one. The result is an empty linked list.
void clearCard_LList(Card_LList* theList){
    //initialize new node
    Card_Node* node;
    //set while loop to clear LList
    while(theList->head != NULL){
        node = theList->head;
        theList->head = theList->head->next;
        free(node);
    }
}
// a function that checks if the list is empty.
// If it is empty, return true; otherwise return false.
bool isEmptyCard_LList(Card_LList* theList){
    //check if head and tail is null
   if (theList->head == NULL && theList->tail == NULL){
       return true;
   }
   return false;
}

//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertFrontCard_LList(Card_LList* theList, Card* theCard){
    //malloc for new node
    Card_Node* node = malloc(sizeof(Card_Node));
    if (node == NULL){
        exit(0);
    }
    //set next to the original head
    node->next = theList->head;
    //set head to node
    theList->head = node;
}

//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertEndCard_LList(Card_LList* theList, Card* theCard){
    //create space for new node
    Card_Node* node = malloc(sizeof(Card_Node));
    if (node==NULL){
        exit(0);
    }
    node->card = theCard;
    //set head and tail to node because LList is empty
    if (isEmptyCard_LList(theList)== true){
        theList->head = node;
        theList->tail = node;
    }
    //if not empty then set the node as new tail
    else{
        node->next = NULL;
        theList->tail->next = node;
        theList->tail = node;
    }
}

//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeFrontCard_LList(Card_LList* theList){
    if (theList->head == NULL){
        return NULL;
    }
    //Card_Node* current = theList->head;
    theList->head = theList->head->next;
    //free(current);
    return theList->head->card;
}

//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeEndCard_LList(Card_LList* theList){
    if (theList->head == NULL){
        //if true then its an empty list
        return NULL;
    }
    if (theList->head->next == NULL){
        //free head if only one node
        free(theList->head);
        return NULL;
    }
    //create new node to store original head
    Card_Node* new_tail = theList->head;
    while(new_tail->next->next != NULL){
        new_tail = new_tail->next;
    }

    free(new_tail->next);
    new_tail->next = NULL;
    return theList->tail->card;
}
