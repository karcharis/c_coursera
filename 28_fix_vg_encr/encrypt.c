#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(FILE * f, int key, FILE * outfile){
  // -charis: @bug line should be initialized to NULL
  char * line;
  line = NULL;
  size_t sz;
  while (getline(&line,&sz, f) >= 0) {
    char * ptr = line;
    while (*ptr != '\0') {
      int c = *ptr;
      if (isalpha(c)) {
	c = tolower(c);
	c -= 'a';
	c += key;
	c %= 26;
	c += 'a';
      }
      *ptr = c;
      ptr++;
    }
    fprintf(outfile, "%s", line);
  }
  // here we may free the mamory pointed by line, allocated by getline()
  free(line);
}

int main(int argc, char ** argv) {
  if (argc != 3) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  int key = atoi(argv[1]);
  if (key == 0) {
    fprintf(stderr,"Invalid key (%s): must be a non-zero integer\n", argv[1]);
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[2], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  // outfileNAme is argv[2] + ".txt", so add 4 to its length.
  // -charis: probably above is meant to say + ".enc", instead of + ".txt"
  // -charis: @bug note the use of strlen() in next line! strlen() deos not count null terminating char.
  //          Hence, to allocate enough memory we do a +1 in malloc() 
  char * outFileName = malloc((strlen(argv[2]) + 4 + 1) * sizeof(*outFileName));
  strcpy(outFileName, argv[2]);
  strcat(outFileName, ".enc");
  FILE * outFile = fopen(outFileName, "w");
  
  // -charis: here it is safe to free the space of outFileName
  free(outFileName);
  
  // -charis: Let us check if outFile = NULL
  if (!outFile) {
    perror("Error on open/creating the output file");
    return EXIT_FAILURE;
  }

  encrypt(f,key, outFile);
  if (fclose(outFile) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
