#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#include "cards.h"



// debugging the eval.c

deck_t make_hand(deck_t * d, card_t ** hand) {

  shuffle(d);

  for (size_t i = 0; i < 7; i++) {
    hand[i] = d->cards[i];
  }
  
  deck_t h = {.cards = hand, .n_cards = 7};

  return h;

}

void is_straight_at_tester(deck_t * hand) {
 
  printf("Your hand is:\n\n\t");
  print_hand(hand);
  printf("\n\n");                                                                  
                                                       
                                   
  sort_hand(hand);                                                                        
  printf("-------------------\n");
  printf("Your hand sorted is:\n\n\t");                                                 
  print_hand(hand);
  printf("-------------------\n");
  printf("\n\n");                                                                       

  // is_straight_at_deck 
  printf("Cheking hand for a straight\n");
  printf("-------------------\n");
  for (size_t i = 0; i < 3; i++) {
    printf("Checking for straight in position %zu:\n", i+1);
    printf("\t\tis_straight_at returns %d\n\n", is_straight_at(hand, i, NUM_SUITS));
    printf("Cheking hand for a spades straight in position %zu: \n", i+1);
    printf("\t\tis_straight_at returns %d\n\n", is_straight_at(hand, i, SPADES));
  }
  printf("-------------------\n");
}

/*
void pairs_checher(deck_t * hand) {

  unsigned * match_counts =  get_match_counts(hand);
  for (size_t i = 0; i < 7, i++) {
    printf("|%zu", match_counts[i]);
  }
  printf("|\n");
  
  n_of_a_kind = get_largest_element(match_counts, 7);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  printf("\t- your hand has a %d of a kind at position %zu\n",  )
}
*/

int main(void) {

  // creating a full set of cards
  card_t set[52];
//  card_t * deck[52];
  for (size_t i = 0; i < 52; i++) {
    set[i] = card_from_num(i);
//    deck[i] = &set[i];
  }

  //deck_t d = (deck_t) {.cards = deck, .n_cards = 52};
  //
  

  // make some custom hands for testing 
  
  // hand1
  card_t * straight[7] = { //straight
                        &set[8],
                        &set[0],
                        &set[35],
                        &set[44],
                        &set[13],
                        &set[6],
                        &set[20]
  };
  deck_t hand1 = {.cards = straight, .n_cards = 7};
  //

  // hand2
  card_t * fstraight[7] = { // spades straight
                        &set[6],
                        &set[10],
                        &set[42],
                        &set[7],
                        &set[9],
                        &set[19],
                        &set[8]
  };
  deck_t hand2 = {.cards = fstraight, .n_cards = 7};
  //

  // hand3
  card_t * low_ace[7] = { // spades low ace straight
                        &set[3],
                        &set[44],
                        &set[2],
                        &set[0],
                        &set[42],
                        &set[1],
                        &set[12]
  };
  deck_t hand3 = {.cards = low_ace, .n_cards = 7};


  is_straight_at_tester(&hand1);
  is_straight_at_tester(&hand2);

  is_straight_at_tester(&hand3);
 
  card_t * test1[7] = { // As Ad 5d 4d 3d 2h 2d
                        &set[12],
                        &set[25],
                        &set[3],
                        &set[2],
                        &set[1],
                        &set[0],
                        &set[26]
  };
  deck_t hand = {.cards = test1, .n_cards = 7};
  is_straight_at_tester(&hand);
  printf("is_straight_at(&hand, 0, NUM_SUITS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 0, NUM_SUITS));
 
  printf("is_straigt_at(&hand, 0, SPADES) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 0, SPADES)); 
 
  printf("is_straight_at(&hand, 1, NUM_SUITS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, NUM_SUITS));
 
  printf("is_straight_at(&hand, 1, SPADES)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, SPADES));
 
  printf("is_straight_at(&hand, 1, HEARTS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, HEARTS));

  card_t * test2[7] = { // Ah Ad Ac 5d 4d 3d 2d
                       &set[25],
                       &set[38],
                       &set[51],
                       &set[29],
                       &set[28],
                       &set[27],
                       &set[26]
  };
  hand = (deck_t) {.cards = test2, .n_cards = 7};
  is_straight_at_tester(&hand);
  printf("is_straight_at(&hand, 0, NUM_SUITS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 0, NUM_SUITS));
 
  printf("is_straight_at(&hand, 1, NUM_SUITS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, NUM_SUITS));
 
  printf("is_straight_at(&hand, 2, NUM_SUITS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 2, NUM_SUITS));

  printf("is_straigt_at(&hand, 0, SPADES) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 0, SPADES)); 
 
  printf("is_straight_at(&hand, 1, HEARTS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, HEARTS));
 
  printf("is_straight_at(&hand, 2, CLUBS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 2, CLUBS));
 
  printf("is_straight_at(&hand, 1, DIAMONDS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 1, DIAMONDS));

  printf("is_straight_at(&hand, 2, DIAMONDS)) returns: ");
  printf("%d\n\n", is_straight_at(&hand, 2, DIAMONDS));

  

/*
  for (int test = 0; test < 10; test++) {

    card_t * hand[7];
    deck_t h = make_hand(&d, hand);

    printf("Your hand is:\n\n\t");
    print_hand(&h);
    printf("\n\n");

    // Testing sort_hand 
    
    sort_hand(&h);
    printf("-------------------\n");
    printf("Your hand sorted is:\n\n\t");
    print_hand(&h);
    printf("\n-------------------\n");
  
    // Testing my functions
    
    // flush_suit
    printf("-------------------\n");
    printf("Your hand may flush on:\n\n\t");
    suit_t fs = flush_suit(&h);
    const char * str_fs = suit_string_from_suit_t(fs);
    printf("%s", str_fs);
    printf("\n-------------------\n\n");
   

    // is_straight_at_deck 
    is_straight_at_tester(&h);
    
       
    // Evaluate hand
    
    hand_eval_t h_eval = evaluate_hand(&h);
    
    printf("Your hand evaluates to %s\n", ranking_to_string(h_eval.ranking));
    printf("You play with: \n\n\t");
    for (size_t i = 0; i < 5; i++) {
      print_card(*h_eval.cards[i]);
      printf(" ");
    }
    printf("\n");
  } 
*/
  return EXIT_SUCCESS;
}
