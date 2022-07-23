#include <stdio.h>
#include <stdlib.h>
#include "future.h"

deck_t * new_empty_deck(void) {
  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = NULL;

  return d;
}


int main(void) {
  
  //A. create full deck
  card_t set[52];
  for (size_t i = 0; i < 52; i++) {
    set[i] = card_from_num(i);
  }
  deck_t * deck = new_empty_deck();
  deck->n_cards = 0;
  deck->cards = NULL;
  
  for (size_t i = 0; i < 52; i++) {
    add_card_to(deck, set[i]);
  }
    
  //B. create a empty fc
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;

  //C. Make two hands 
  //C.1. hand1 
  //C.1.1 
  deck_t * hand1 = new_empty_deck();
  card_t test1[4] = { set[11], set[21], set[6], set[31] };
  for (size_t i = 0; i < 4; i++) {
    add_card_to(hand1, test1[i]);
  }
  //@testing
  print_hand(hand1);
  printf("\n");
  //C.1.2. add two empty cards 0? 1?
  for (size_t i = 0; i < 2; i++) {
    add_future_card(fc, i, add_empty_card(hand1));
  }
  //@testing
  print_hand(hand1);
  printf("\n");

  //C.2 hand2
  //C.2.1.
  deck_t * hand2 = new_empty_deck();
  card_t test2[3] = { set[20], set[36], set[39] };
  for (size_t i = 0; i < 3; i++) {
    add_card_to(hand2, test2[i]);
  }
  //@testing
  print_hand(hand2);
  printf("\n");
  //C.2.2. add three empty cards 0? 2? 3?
  add_future_card(fc, 3, add_empty_card(hand2)); // this line adds 3?
  for (size_t i = 0; i<3; i+= 2) { //this adds 0? 2?
    add_future_card(fc, i, add_empty_card(hand2));
  }
  //@testing
  print_hand(hand2);
  printf("\n");

  
  //D. build remaining deck 
  //D.1. make deck_t ** hands
  deck_t ** hands = malloc(2*sizeof(*hands));
  hands[0] = hand1;
  hands[1] = hand2;
  //D.2 free and empty deck
  free_deck(deck);
  //D.3
  deck = build_remaining_deck(hands, 2);
  //D.4
  free(hands);

  //E. suffle
  shuffle(deck);
  printf("the suffled deck is:\n");
  
  //Z. Test future_from_deck
  future_cards_from_deck(deck, fc);
  
  print_hand(deck);
  printf("\nThe two hands are\n");
  print_hand(hand1);
  printf("; ");
  print_hand(hand2);
  printf("\n");

  free_deck(deck);
  free_deck(hand1);
  free_deck(hand2);
 
  for (size_t i = 0; i < fc->n_decks; i++) {
   free(fc->decks[i].cards);
  } 
  free(fc->decks);
  free(fc);
  
  return EXIT_SUCCESS;
}
