#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"


counts_t * createCounts(void) {
  //WRITE ME
  counts_t * c = malloc(sizeof(*c));
  if (c == NULL) {
    fprintf(stderr, "error: not enough memory\n");
    exit(EXIT_FAILURE);
  }
  c->counts = NULL;
  c->n_counts = 0;
  c->n_unknowns = 0;

  return c;
}


void addCount(counts_t * c, const char * name) {
  //WRITE ME
  // check first if name = NULL, otherwise in strcmp(.value, NULL) will SEGFAULT
  if (name == NULL) {
    c->n_unknowns += 1;
    return;
  }
  for (size_t i = 0; i < c->n_counts; i++) {
    if (strcmp(c->counts[i].value, name) == 0) {
      c->counts[i].count += 1;
      return;
    }
  }
  // if the function has not returned until know, then name should be a new value to counted
  one_count_t * temp_buff = realloc(c->counts, (c->n_counts+1)*sizeof(*c->counts));
  if (temp_buff == NULL) {
    fprintf(stderr, "error: not enough memory");
    exit(EXIT_FAILURE);
  }
  c->counts = temp_buff;
  c->counts[c->n_counts].value = name;
  c->counts[c->n_counts].count = 1;
  c->n_counts += 1;

  return;
}


void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  
  for (size_t i = 0; i < c->n_counts; i++) {
    fprintf(outFile, "%s: %d\n", c->counts[i].value, c->counts[i].count);
  }
  if (c->n_unknowns) {
    fprintf(outFile, "<unknown> : %d\n", c->n_unknowns);
  }  
}


void freeCounts(counts_t * c) {
  //WRITE ME
  free(c->counts);
  free(c);
}
