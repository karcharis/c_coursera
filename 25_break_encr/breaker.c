#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void get_freq(FILE * f, unsigned * arr, size_t size) {
  unsigned total = 0;
  int  c;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      total++;
      c = tolower(c);
      c -= 'a';
      arr[c]++;
    }
  }
  if (total == 0) {
    fprintf(stderr, "No encrypted text found. The code braeker cannot return any key\n");
    exit(EXIT_FAILURE);
  }
}

int get_idx_of_max(unsigned * arr, size_t size) {
  int idx = 0;
  for (int i = 1; i < size; i++) {
    if (arr[idx] < arr[i]) {
      idx = i;
    }
  }
  return idx;
}



int main(int argc, char ** argv) {
  if (argc != 2) { // NOTE: there is always one argument! the name of the program  
    fprintf(stderr, "Wrong number of input arguments. Expecting one argument\n");
    return EXIT_FAILURE;
  }
  FILE * encrypted = fopen(argv[1], "r");
  if (encrypted == NULL) {
    fprintf(stderr, "Could not access the file %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  unsigned freq_alpha[26] = {0};
  get_freq(encrypted, freq_alpha, 26);
  
  int key = get_idx_of_max(freq_alpha, 26);
  key = (26 + (key - ('e'-'a'))) % 26; // the 26 + ensures that we take a value in [0,26). This has to do with how the % operator is working in C.

  if (key < 0 || key >= 26) {
    fprintf(stderr, "Unknown error! key is outside of the interval [0,26)\n");
    return EXIT_FAILURE;
  }  
  fprintf(stdout, "%d\n", (int) key);
  return EXIT_SUCCESS;
}
