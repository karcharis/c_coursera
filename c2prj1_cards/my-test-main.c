#include "cards.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>



int main(void) {


// testing card_from_num

  printf("Cheking card_from_num and print_card..\n");
  card_t c1 = card_from_num(0); //2s
  card_t c2 = card_from_num(12); //As
  card_t c3 = card_from_num(15); //4h
  card_t c7 = card_from_num(50); //Kc
  card_t c8 = card_from_num(51); //Ac


  printf("card 1 is: ");
  print_card(c1);
  printf("\n");

  printf("card 2 is: ");
  print_card(c2);
  printf("\n");

  printf("card 3 is: ");
  print_card(c3);
  printf("\n");

  printf("card 7 is: ");
  print_card(c7);
  printf("\n");

  printf("card 8 is: ");
  print_card(c8);
  printf("\n");


/*  
  // here should crash the assertion

  printf("Here should crash the assertion");
  card_from_num(52); //2s
*/

// testing card_from_letters
  printf("Testing card_from_letters..\n");


  card_t c4 = card_from_letters('0', 'h');
  printf("c4 = card_from_letters(\'0\', \'h\') prints: ");
  print_card(c4);
  printf("\n");

  card_t c5 = card_from_letters('A', 's');
  printf("c5 = card_from_letters(\'A\', \'s\') prints: ");
  print_card(c5);
  printf("\n");

  card_t c6 = card_from_letters('2', 'd');
  printf("c6 = card_from_letters(\'2\', \'d\') prints: ");
  print_card(c6);
  printf("\n");

/*
  // here should crash the assertion

  printf("Here should crash the assertion");
  card_from_letters('1','f');
*/  
}
