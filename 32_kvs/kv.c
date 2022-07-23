#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char * next_line(FILE * f) {
  size_t sz = 0;
  char * line = NULL;
  if (getline(&line, &sz, f) > 1 ) {
    return line;
  }
  free(line);
  return NULL;
}


char * get_key(char * str) {
  char * key = NULL;
  size_t sz = 0;

  while (str[sz] != '=') { // here we assume that there are no "invalid" chars in each line
    sz++;
    key = realloc(key, sz*sizeof(*key));  // the correct way is to realloc to a new buffer and if not NULL the point key to the new buff
    key[sz-1] = str[sz-1];
  }
  key = realloc(key, (sz+1)*sizeof(*key));
  key[sz] = '\0';
  return key;
}


char * get_value(char * str) {
  char * value = NULL;
  char * start = strchr(str, '=');
  if (start == NULL) {
    fprintf(stderr, "error: wrong file format\n");
    exit(EXIT_FAILURE);
  }
  start++;  // value begins after the first '='
  size_t sz = 0;
  
  while (start[sz] != '\n') {
    sz++;
    value = realloc(value, sz*sizeof(*value));
    value[sz-1] = start[sz-1];
  }
  value = realloc(value, (sz+1)*sizeof(*value));
  value[sz] = '\0';
  return value;
}


kvarray_t * readKVs(const char * fname) {
 
  //A. open kvs-file
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    fprintf(stderr, "error: file %s has not opened properly\n", fname);
    return NULL;
  }
   
  //B. get all the key-values pairs
  //B.1 creat an empty kvarray_t
  //B.1.1 alloc memory
  kvarray_t * pairs = malloc(sizeof(*pairs));
  /*
   * assuming memory allocated successfuly *
   *
   * if (pairs == NULL) {
   *   fprintf(stderr, "error: not enough memory\n");
   *   exit(EXIT_FAILURE);
   * }
   *
  */
    
  //B.1.2 initializing empty *pairs 
  pairs->n_pairs = 0;
  pairs->kvs = NULL;

  
  //B.2 read each line and write the correspoding kvpair_t entry
  char * curr; 
  char * t_key;
  char * t_val;
  while ( ( curr = next_line(f) ) != NULL ) {
    //B.3.1. extract from curr a key-value pair
    t_key = get_key(curr);
    t_val = get_value(curr);
 
    //B.2.2. check if t_key or t_value is NULL, this will indicate a format error    
    if (t_key == NULL || t_val == NULL) {
      //return
    }
    
    //B.2.3 allocate memory for an extra kvpair_t
    //      and write key-value
    pairs->n_pairs = pairs->n_pairs + 1;
    pairs->kvs = realloc(pairs->kvs, (pairs->n_pairs)*sizeof(*pairs->kvs));
    /* assume that memory allocated successfuly *
     * 
     * if (pairs->kvs == NULL) {
     *   fprintf(stderr, "error: not enough memory\n");
     *   exit(EXIT_FAILURE);
     * }
     *
    */
    
    pairs->kvs[pairs->n_pairs -1].key = t_key;
    pairs->kvs[pairs->n_pairs -1].value = t_val;
    
    //B.2.4 close loop to reenter
    //      note: curr points to no useful data, since key and value are retrievied
    free(curr);
  }
  free(curr);
  
  //C. close filr
  if (fclose(f)!= 0)  {
  /* assuming that the file is closed successfuly *
   *  
   * fprintf(stderr, "error: file %s have not closed properly\n", fname);
   * exit(EXIT_FAILURE);
   * 
  */
  }

  //D. exit
  //D.1. if no pairs are read print a message
  if (pairs->n_pairs == 0) {
    fprintf(stderr, "no key-value pair is found\n");
    fprintf(stderr, "this probably means that %s has wrong formating", fname);
  }
  return pairs;
}


void freeKVs(kvarray_t * pairs) {  
  // We have to free from inside to out
  // 1. each key and value for each kv->pairs
  // 2. the *kv->kvs
  // 3. *kv
  for (size_t i = 0; i < pairs->n_pairs; i++) {
      
    free(pairs->kvs[i].key);
    free(pairs->kvs[i].value);
  
  }
  free(pairs->kvs);
  free(pairs);
}


void printKVs(kvarray_t * pairs) {
  for (size_t i = 0; i < pairs->n_pairs; i++) {
    printf("key = \'%s\' value \'%s\'\n", pairs->kvs[i].key, pairs->kvs[i].value);
  }
}


char * lookupValue(kvarray_t * pairs, const char * key) {
  for (size_t i = 0; i < pairs->n_pairs; i++) {
    if (strcmp(pairs->kvs[i].key, key) == 0) {
      return pairs->kvs[i].value;
    }
  }
  return NULL;
}
