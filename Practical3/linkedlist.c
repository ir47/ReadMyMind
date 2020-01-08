//Header file for prototypes and strut definitions
#include "readmymind.h"

/**
Function used for the linking of two linked list heads
The function takes in two linked list heads and the it loops to the end of the first one
After it has reached the end of the first list it will set the next value to the head of the second list head
This connected list is then returned
**/
node_t * link_heads(node_t* first_head,node_t* second_head){

  //Sets the head of the list to the variable current which is used for the loop
  node_t* current = first_head;
  for (int i = 0; i < 6; i++) {
    current = current->next;
  }
  current->next = second_head;

  return first_head;
}

/**
Function used for setting the top value in a linked list
Takes in a linked list node and a card
**/
void null_head(node_t* head,struct Card* card){
  head-> card = card;
  head-> next = NULL;
}

/**
Sets a second linked list head node to the value after the last entry in a linked list
Takes in a linked list node and then the function loops through and returns the new head for the other linked list
**/
node_t* set_list_head(node_t* head){
  node_t* current = head;
  for (int i = 0; i < 6; i++) {
    current = current->next;
  }
  node_t* second_head = current->next;
  current->next = NULL;
  return second_head;
}
/**
Sets the next value of a head of a list to null
Takes in a head node and a card value
This function is used when moving column 2 to the end of the 21 list of cards as if it is not set to Null an infinit loop will be created
**/
void set_null(node_t* head){
  node_t* current = head;
  for (int i = 0; i < 6; i++) {
    current = current->next;
  }
  current->next = NULL;
}

/**
Function used for rearranging the linked list depending on which column the users card is in
Takes in three linked list nodes and the users column input
Function contains a switch case which will link the correct lists to each other depending on the input
**/
node_t* change_columns(node_t * head,node_t * head2,node_t * head3,int column){

  //Switch case which will rearrange the links in the list depnding on which column the user selects
  switch (column) {
    case (1):
        link_heads(head2,head);
        link_heads(head,head3);
        return head2;
        break;
    case (2):
        link_heads(head,head2);
        link_heads(head2,head3);
        return head;
        break;
  case (3):
      link_heads(head,head3);
      link_heads(head3,head2);
      set_null(head2);
  return head;
    break;
    default:
      break;
      }
    return head;
  }

/**
Function for printing the 21 cards used in the trick
The function takes in each of the head nodes for the three columns
It then loops through the lists printing out each of the values in the columns
**/
void print_all_list(node_t * head, node_t * head2, node_t * head3) {

  //Assigns each of the column heads to variables used in the loop
        node_t * list1pos = head;
        node_t * list2pos = head2;
        node_t * list3pos = head3;

        printf("\n---- Column 1 ----    ---- Column 2 ----    ---- Column 3 ----\n" );
        while (list1pos != NULL) {
          //change_value(list1pos->card);
            printf("     %s of %s   ", list1pos->card->value,list1pos->card->suit);
            printf("     %s of %s   ", list2pos->card->value,list2pos->card->suit);
            printf("     %s of %s", list3pos->card->value,list3pos->card->suit);
            printf("\n" );

            list1pos = list1pos->next;
            list2pos = list2pos->next;
            list3pos = list3pos->next;
        }
}

/**
Function used for adding cards to a list
Takes in the head of the list and the card which is to be added to the list
Loops through from the passed in head until the next value is null then the space is malloced and the card is added
**/
void list_push(node_t * head, struct Card *card) {
    //printf("card:%c%c\n",card->value,card->suit );
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->card = card;
    current->next->next = NULL;
}
