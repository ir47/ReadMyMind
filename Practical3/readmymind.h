/**
Header file used in readmymind.c , card.c and linkedlist.c
Defines prototypes for all of the functions used in all of these files
This file also contains the imports for the files and the typedef definitions for the card and node types
**/


//Ifndef used to stop issues with elements being declared or created multiple times
#ifndef readmymind
# define readmymind


//Imports used in the files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

//Defines the contant used in the full deck
const static int deck_size = 52;

//Defines the card struct type
typedef struct Card {
   char* value;
   char* suit;
} card;

//Defines the node struct type
typedef struct node {
    struct Card * card;
    struct node * next;
} node_t;


//Prototypes for the functions used in each of the files. 
node_t* set_list_head(node_t* head);
node_t* change_columns(node_t* head,node_t* head2,node_t* head3,int column);
node_t * link_heads(node_t* first_head,node_t* second_head);
node_t* redeal_cards(node_t * current);
void list_push(node_t * head, struct Card *card);
void set_null(node_t* head);
int getRandomNumber();
bool get_is_playing();
void trick(struct Card* deck[deck_size]);
char* change_value(struct Card* card);
bool check_duplicates(node_t* head, struct Card* card);
void print_all_list(node_t * head, node_t * head2, node_t * head3);
void null_head(node_t* head,struct Card* card);
void free_node(node_t* head);
void trick_loop(node_t* head,node_t* head2,node_t* head3);
int get_column();
struct Card* get_card(node_t* head);

#endif
