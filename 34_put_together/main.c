#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  
  //A. open list file
  FILE * f = fopen(filename, "r");
  if (f == NULL) {
    fprintf(stderr, "error: file %s has not open properly\n", filename);
    return NULL;
  }
  
  
  //B. creating the counts_t
  //B.1. create an empty count_t
  counts_t * c = createCounts(); 
  /* assuming memory allocated successfuly */
  
  //B.2. get each line of the list file and count it
  //     note: we put > 1 as the boundary contidion in the next while
  //         since  only one '\n' char doesnot count for a valid key
  char * curr = NULL;
  size_t sz = 0; 
  while ( getline(&curr, &sz, f) > 1) {
  //B.2.1 make *curr a valid string, i.e. remove '\n' char and null terminate it
  //      notes: - *curr has the form ..'\n''\0'.
  //             - note  also that '\n' is at index strlen(curr)-1
  //               (remember! strlen doesnot count '\0')
    curr[strlen(curr)-1] = '\0';
  //B.2.2 count *curr
  //      note: - lookupValue returns NULL if curr is not a key of kvPairs->kvs[]
  //              and NULL otherwise
  //            - addCount(c, value) will count/add the value
    addCount(c, lookupValue(kvPairs, curr));
  }
  free(curr);
  
  //C. close counting file
  if (fclose(f) != 0) {
  /* assuming the file is closed succesfully *
   * 
   * fprintf(stderr, "error: file %s  has not closed properly\n", filename);
   * free(kvPairs);
   * freeCounts(c);
   * exit(EXIT_FAILURE);
   *
   */
  } 
  
  //D. exit

  //D.1 in case of no counts print a messege
  if (c->n_counts == 0 && c->n_unknowns == 0) {
    fprintf(stdout, "no counts found for file %s\n", filename);
  }

  return c;
}

int main(int argc, char ** argv) {
  //O. check argc
  if (argc < 3) {
    fprintf(stderr, "error: usage needs at least 2 arguments\n");
    return EXIT_FAILURE;
  }
  
  //A. read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  if ( kv == NULL ) { // file argv[1] has not opened properly!
    return EXIT_FAILURE;  
  }
  //B. count from 2 to argc (call the number you count i)
  for (size_t i = 2; i < argc; i++) {
    //B.1 count the values that appear in the file named by argv[i],
    //    using kv as the key/value pair (call this result c)
    counts_t * c = countFile(argv[i], kv);
    if (c == NULL) { // file argv[i] have not oppened properly!
      break;
    }
    //B.2. open output file and print counts
    //B.2.1 compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);
    
    //B.2.2 open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    /* assuming the file is opend successfuly *
     *
     * if (f == NULL) {
     *   fprintf(stderr, "error: output file %s has not open properly\n", outName);
     *   return EXIT_FAILURE;
     * }
    */ 
        
    //B.2.3 print the counts from c into the FILE f
    printCounts(c, f);

    //B.2.4 close f
    if (fclose(f) != 0) {
    /* assuming file closed properly *
     * fprintf(stderr, "error: output file %s has not closed properly\n", outName);
     * return EXIT_FAILURE;
    */
    }
    
    //C. exit
    //C.1. free the memory for outName and c
    free(outName);
    freeCounts(c);
  }
  //D. exit
  //D.1 free the memory for kv
  freeKVs(kv); 
  return EXIT_SUCCESS;
}
