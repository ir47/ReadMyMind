//Header file for prototypes and strut definitions
#include "readmymind.h"

/**
Main function for the running of the card trick
**/
int main (){
  struct Card* deck[deck_size];
  char* suitValues[] = {"Hearts  ","Clubs   ","Diamonds","Spades  "};
  char* cardValues[] = {"A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K "};
  int i;
  printf("Read my mind \n");

  int count =0;

  for (int i = 0; i<4; i++) {
    char* suit = suitValues[i];
      for (int j = 0; j < 13; j++) {
        deck[count] = malloc(sizeof(struct Card));
        deck[count]->suit = suit;
        deck[count]->value = cardValues[j];
        count ++;
      }
}
bool is_playing = true;
while (is_playing == true) {

node_t *head = malloc(sizeof(node_t));
if (head == NULL) {
  printf("List creation error");
}
srand(time(NULL));

int random_card = getRandomNumber();

head->card = deck[random_card];
head->next = NULL;

  for (i =0; i<20; i++) {
    random_card = getRandomNumber();
    bool is_duplicate = check_duplicates(head,deck[random_card]);
    while (is_duplicate == true) {
      random_card = getRandomNumber();
      is_duplicate = check_duplicates(head,deck[random_card]);
    }
    list_push(head,deck[random_card]);
  }

node_t* head2 = set_list_head(head);
node_t* head3 = set_list_head(head2);

print_all_list(head,head2,head3);

trick_loop(head,head2,head3);
 is_playing = get_is_playing();
}

printf("\n---- Thank you for playing! ----\n");

}

/**
Function used to check if the user would like to do the trick again.
The function contains the input validation for the user input
Returns if the player would like to do the trick again or not
**/
bool get_is_playing(){
  char is_playing;
  bool is_valid = false;
  printf("---- Would you like to play again? (Y/N) ----\n---- ");

//Input validation for user entering if playing again
  while (!is_valid) {
        char term;
        if(scanf("%c%c", &is_playing, &term) != 2 || term != '\n'){
          is_valid = false;
            printf("\n---- Invalid Input! Please enter Y to play again or N to quit ----\n---- ");
            scanf("%*s");
            while((getchar())!='\n');
          }else if (is_playing != 'Y' && is_playing != 'N'){
              printf("\n---- Invalid Input! Please enter Y to play again or N to quit ----\n---- ");
            }else{
              is_valid = true;
            }
          }
  return is_playing == 'Y';
}

/**
Main loop for the trick.
Takes in the three pointers to the top of each of the columns
Loops three times each time each time getting the users column input from the get_column() function
After the loop has finished the users card will be displayed
**/
void trick_loop(node_t* head,node_t* head2,node_t* head3) {

  //Loops three times in order for the trick to work correctly
  for (int i = 0; i < 3; i++) {

  //Gets the column from the user
  int column = get_column();

  //Switches the columns around in the list so the users card is in the middle column
  head = change_columns(head,head2,head3,column);

  //Re-distributes the cards into their new columns
  head = redeal_cards(head);

  //Sets the new heads of the newly editied columns
  head2 = set_list_head(head);
  head3 = set_list_head(head2);

  //Displayes the newly created columns to the user
  print_all_list(head,head2,head3);

    }
  //Gets the users card from the middle column and then displays the card to the user
  struct Card* usersCard = get_card(head2);
  printf("\n\n---- Your Card is:  %s of  %s\n\n",usersCard->value,usersCard->suit );
}

/**
Function used for the freeing of a linked list
A node pointer is taken in, with the function looping from that point to free the nodes in the linked list
**/

void free_node(node_t* head){
  node_t* current;
  while (head != NULL) {
    current = head;
    head = head->next;
    free(current);
  }
}

/**
Function used for getting the column input from the user
The function contains input validation which makes it so only an int can be entered
The validation is also used to make sure only 1, 2 or three can be entered
if an incorrect input is entered a message will be displayed and the user can enter the column in again
The users column is the return when a correct input is entered
**/

int get_column(){
  int column = 0;
  bool is_valid = false;
  printf("\n---- Which column is your card in? ----\n---- ");

//Input validation loop
  while (!is_valid) {
    char term;
    if(scanf("%d%c", &column, &term) != 2 || term != '\n'){
      is_valid = false;
        printf("\n---- Invalid Input! Please enter 1, 2 or 3 ----\n---- ");
        scanf("%*s");
  }else if (column<1 || column>3){
    printf("\n---- Invalid Column! Please enter 1, 2 or 3  ----\n---- ");
  }else{
    is_valid = true;
  }
    }

  //Returns the users column choice
  return column;
}

/**
This function returns a random number
Its main purpose is for selecting a random card from the deck of cards
**/
int getRandomNumber(){
  return rand()%52;
}
