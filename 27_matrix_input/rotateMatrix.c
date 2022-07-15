#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LINE_LENGTH 11  // 10 printable chars plus '\0'

void rotate(char matrix[10][LINE_LENGTH]) {

  // Note:
  //  The str terminators should stay fixed on their position
  //  That means the column [][LINE_LENGTH-1] should remain untouched 
     
  // To rotate the matrix in-place
  //  1. First we reflect the elements with respect to the horizontal axes 
  char temp;

  for (size_t i = 0; i < 10; i++) { 
    for (size_t j = 0; j < (LINE_LENGTH-1)/2; j++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[i][LINE_LENGTH - 2 -j];
        matrix[i][LINE_LENGTH -2 -j] = temp;
    }
  }

  //  2. Next we reflect with respect to the second diagonal
  for (size_t i = 0; i < 10; i++) { 
    for (size_t j = 0; j < LINE_LENGTH-1 -i; j++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[LINE_LENGTH -2 -j][LINE_LENGTH -2 -i];
        matrix[LINE_LENGTH -2 -j][LINE_LENGTH -2 -i] = temp;
    }
  }

}

void get_matrix(FILE * f, char (* rows)[LINE_LENGTH], unsigned n_rows) {

  size_t line = 0;
  char temp[LINE_LENGTH];

  while ( (fgets(temp, LINE_LENGTH, f) != NULL) && (line < 10) ) {
  // Note: fgets returns whenever encounters one of the next three conditions (all have the same priority)
  //  1. reads n-1 chars, where n is its secont argument
  //  2. reads '\n'
  //  3. reads EOF
   
    // Validate 10 (non '\n') characters
    if (strlen(temp) != LINE_LENGTH-1) { // note strlen does not count '\0'. Hence we detect invalid '\0' chars
      fprintf(stderr, "invalid input at line: %zu\n\t", line+1);
      fprintf(stderr, "probably line's chars < 10");
      exit(EXIT_FAILURE);
    }

    // Validate that after 10 chars there is a '\n'
    if ( fgetc(f) != '\n' ) {
      fprintf(stderr, "invalid input: at line: %zu\n", line+1);
      fprintf(stderr, "probably line's chars > 10");
      exit(EXIT_FAILURE);
    }

    // If temp is a valid line
    //  1. write temp to matrix[line]
    strcpy(rows[line], temp);

    //  2. advance line
    line++;
  }

  // exiting if everything is alright 
  if (line == 10 && feof(f)) {
    return;
  }
  else if (f != NULL && line == 10) {
    fprintf(stderr, "invalid input: probably lines > 10\n)");
    exit(EXIT_FAILURE);
  }
  else if (!feof(f)) {
    fprintf(stderr, "error: read file failure\n)");
    exit(EXIT_FAILURE);
  }
  else { // error in reading, or invalid row numbers ending 
    fprintf(stderr, "error: either unexpected reading failure ");
    fprintf(stderr, "or invalid input (probably wrong number of lines\n)");
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char ** argv) {
  
  // validate that argc is correct
  if (argc != 2) {
    fprintf(stderr, "Wrong # of arguments.\n");
    fprintf(stderr, "Give only the name of the file containing the matrix\n");
    return EXIT_FAILURE;
  }

  // and file is opened
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Error on opening the file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // get the matrix from reading the file
  char matrix[10][LINE_LENGTH];
  get_matrix(f, matrix, 10);

  // Note we used an matrix[10][LINE_LENGTH] in order to store the str terminator,
  // but rotate is wrote to  
  rotate(matrix);
  
  //printing
  for (size_t i = 0; i < 10; i++) {
    fprintf(stdout, "%s\n", matrix[i]);
  }

  //closing files
  if (fclose(f) != 0) {
    fprintf(stderr, "error: %s not closed properly\n", argv[1]);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
