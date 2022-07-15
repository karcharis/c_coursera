#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


int main(void) {

  // initialize a full set of cards
  
  card_t fullSet[52];
  
  for (size_t i = 0; i < 52; i++) {
    fullSet[i] = card_from_num(i);
  }
  
  // initialize a deck
  card_t * cardsDeck[52]; 
  deck_t deck = (deck_t) {.cards = cardsDeck, .n_cards = 52};

  for (size_t i = 0; i < 52; i++) {
    deck.cards[i] = &fullSet[i];
  }

  printf("Testing print_hand..\n");
  print_hand(&deck);
  printf("\n");

  printf("Testing deck_contains..\n");
  for (int i = 0; i < 52; i++) {
    printf("calling deck_contains(&deck, fullSet[%d])\n", i);
    int flag = deck_contains(&deck, fullSet[i]);
    printf("Let us print full deck, after calling deck_contains(&deck, fullSet[%d])\n",i);
    print_hand(&deck);
    printf("\n");
    if (flag) {
      printf("deck contains the %d-th card ", i);
      print_card(fullSet[i]);
      printf("\n");
    }
  }

  shuffle(&deck);
  printf("Here is a shuffled deck\n");
  print_hand(&deck);
  printf("deck_contains() returns %d\n", deck_contains(&deck, fullSet[10]));
  printf("\n");


  assert_full_deck(&deck);

  shuffle(&deck);

  printf("Here is the deck after another suffle\n");
  print_hand(&deck);
  printf("\n");
  
  printf("Finally let us add a duplicate card on the deck, and run assert_valid_deck\n");
  deck.cards[1] = &fullSet[1];
  printf("Print deck with a double 3s\n");
  print_hand(&deck);
  printf("\n");
  assert_full_deck(&deck);

  return EXIT_SUCCESS;
}
