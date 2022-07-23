#include <stdio.h>
#include <stdlib.h>
#include "eval.h"

void test_match_counts(deck_t * hand) {
  
  unsigned * match_counts = get_match_counts(hand);
  
  print_hand(hand);
  printf("\n");
  for (size_t i=0; i < hand->n_cards; i++) {
    printf("%i  ", match_counts[i]);
  }
  printf("\n");
  
  free(match_counts);
}


int main(int argc, char ** argv) {

  //create a hand
  
  deck_t *  hand1 = malloc(sizeof(*hand1));
  hand1->cards = NULL;
  hand1->n_cards = 0;

  int values[4] = { 9, 4, VALUE_ACE, 2 };
  int counts[4] = { 1, 2, 3, 2 };

  int next = 0;
  for (int i = 0; i < 4; i++) {
    for (int j =0; j < counts[i]; j++) {
      add_card_to(hand1, card_from_num(13*j + values[i] - 2));
      next++;
    }
  }

  //create another one
  card_t test[6] = { card_from_num(9),
                     card_from_num(23),
                     card_from_num(36),
                     card_from_num(1),
                     card_from_num(14),
                     card_from_num(27)
  };

  deck_t *  hand2 = malloc(sizeof(*hand2));
  hand2->cards = NULL;
  hand2->n_cards = 0;

  for (size_t i = 0; i < 6; i++) {
    add_card_to(hand2, test[i]);
  }

  //A. test get_match_counts
  test_match_counts(hand1);
  test_match_counts(hand2);


  //B. test make_deck_excluded
  deck_t * d = make_deck_exclude(hand1);
  printf("the deck remaining after drawing the hand\n");
  print_hand(hand1);
  printf("\nis\n");
  print_hand(d);
  printf("\n");

  free_deck(d);
  d=NULL;

  //C. check the build_remain
  deck_t ** hands = malloc(2*sizeof(*hands));
  hands[0] = hand1;
  hands[1] = hand2;
  
  d = build_remaining_deck(hands, 2);

  printf("the deck remaining after drawing the hand\n");
  print_hand(hand1);
  printf("\nand the hand\n");
  print_hand(hand2);
  printf("\nis\n");
  print_hand(d);
  printf("\n");

  free_deck(d);
  free_deck(hand1);
  free_deck(hand2);
  free(hands);
}

     
  


