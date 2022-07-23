#include <stdio.h>
#include <stdlib.h>
#include "input.h" //input.h includes deck.h which includes cards.h


int main(int argc, char ** argv) {
  
  if (argc != 2) {
    fprintf(stderr, "usage error: two many arguments\n");
  }
   
  FILE * f = fopen(argv[1], "r");

  //create a pointer to an empty future_card_t
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->decks = NULL;
  fc->n_decks = 0;

  size_t n_hands = 0; 

  deck_t ** hands = read_input(f, &n_hands, fc);

  if (hands == NULL) {
    return EXIT_FAILURE;
  }

  if (fclose(f) != 0) {
    fprintf(stderr, "error closing the file");
  }
 
  for (size_t i = 0; i < n_hands; i++) {
    printf("\tthe %zu-th hand is: \t", i+1);
    print_hand(hands[i]);
    printf("\n");
  }


  printf("fc->n_decks=%zu\n", fc->n_decks);
  for (size_t i = 0; i < fc->n_decks; i++) {
    printf("unknown card %zu goes to %zu hands\n", i, fc->decks[i].n_cards);
  }




  deck_t * deck = build_remaining_deck(hands, n_hands);
  
  shuffle(deck);

  print_hand(deck);
  printf("\n");

  future_cards_from_deck(deck, fc);
  printf("after drawing cards the hands are\n");
  for (size_t i = 0; i < n_hands; i++) {
    printf("\t%zu-th hand: \t", i+1);
    print_hand(hands[i]);
    printf("\n");
  }
  
  //exit
  free_deck(deck);

  for (size_t i = 0; i<n_hands; i++) {
    free_deck(hands[i]);
  }
  free(hands);
  for (size_t i = 0; i < fc->n_decks; i++) {
    free(fc->decks[i].cards);
  }
  free(fc->decks);
  free(fc);

  
  return EXIT_SUCCESS;
}
