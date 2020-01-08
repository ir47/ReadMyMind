//Header file for prototypes and strut definitions
#include "readmymind.h"

/**
Function used for check if a card has already been picked from the full deck of cards
The function takes in the pointer to the head node of the list and the card that has been picked from the deck
By looping through the linked list starting at the head node, the function then compares the value in the list with the card which has been passed in.
If a card is a duplicate then true will be returned if not then false.
**/
bool check_duplicates(node_t* head, struct Card* card){
  node_t* current = head;

  //Loops through the already picked cards to check for duplicates
  while (current != NULL) {
    if (current->card->value == card->value) {
      if (current->card->suit == card->suit) {

        //Returns true if duplicate is found
        return true;
      }
    }
    current = current->next;
  }

  //Returns false if no duplicate found
  return false;
}


/**
Function used for getting the users card at the end of the trick
The function takes in a node pointer which will then be used to get the middle value of the list
This value is then returned and should be the users card
**/
struct Card* get_card(node_t* head){
  node_t* current = head;

  //Loops to the middle of the list to get the users card
  for (int i = 0; i < 3; i++) {
    current = current->next;
  }

  //Returns the users card
  return current->card;
}

/**
Function used for the re-dealing of cards after the user has entered the column and all of the columns have been collected in the correct order.
The function takes in a node to a linked list
Three new head pointers are created in the function with each being used to store cards for each of the columns
The function then connects the lists together, frees the original list which was passed in and then returns the new list
**/
node_t* redeal_cards(node_t * current){

  //Allocates the space for the new list heads for when the cards are being re-dealt
  node_t *new_head = malloc(sizeof(node_t));
  node_t *new_head2 = malloc(sizeof(node_t));
  node_t *new_head3 = malloc(sizeof(node_t));

  //Counter used for keeping track which column a card should be going into
  int counter = 1;

  //Loops through the list of 21 cards
  while (current != NULL) {

    //Swtiched used to add a card to one of the three columns
    switch (counter) {
      case (1):

        //Check for if the head of the list has not been set
        if (new_head->card == NULL) {
          null_head(new_head,current->card);
        }else{

          //Adds the card to the list
          list_push(new_head,current->card);
        }
        counter++;
        current = current->next;
        break;
      case (2):

        //Check for if the head of the list has not been set
        if (new_head2->card == NULL) {
          null_head(new_head2,current->card);
        }else{
          list_push(new_head2,current->card);
        }
          counter++;
          current = current->next;
          break;
      case (3):

        //Check for if the head of the list has not been set
        if (new_head3->card == NULL) {
          null_head(new_head3,current->card);
        }else{
          //Adds the card to the list
          list_push(new_head3,current->card);
        }
        counter = 1;
        current = current->next;
        break;
    }
  }

  //Reconnects the three heads so that they all link
  link_heads(new_head,new_head2);
  link_heads(new_head2,new_head3);

  //Frees the old list
  free_node(current);

  //Retuns the new head of the newly dealt list
  return new_head;
}
