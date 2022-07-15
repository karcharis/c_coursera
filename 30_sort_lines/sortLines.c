#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}

//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void print_lines(char ** lines, size_t n_lines) {
  for (size_t i = 0; i < n_lines; i++) {
    fprintf(stdout, "%s", lines[i]);
  }
}

// This function will carefully free the allocated space.
// First wil free for each elent of lines the string it points to, 
// then will free lines itself.
void free_lines(char ** lines, size_t n) {
  for (size_t i = 0; i < n; i++) {
    free(lines[i]);
  }
  free(lines);
  lines = NULL;
}


char ** get_lines(FILE * f, size_t * pn_lines) {
  
  // this the return value, initialize to NULL for realloc
  char ** lines = NULL;  
  // initialize line to NULL for getline()
  char * line = NULL;
  size_t sz = 0;

  
  while (getline(&line, &sz,f) > 0) { 
    *pn_lines = *pn_lines + 1;
    lines  = realloc(lines, (*pn_lines)*sizeof(*lines));
    lines[*pn_lines - 1] = line;
    // initialize line to NULL
    // Note! We should not free(line)!
    // This action will leed to loosing the value of lines[n_lines-1] 
    line = NULL;
  }

  // Free memory block pointed by line
  free(line);
  // note the pointer line is destroyed after return, hence we do not bother to make it NULL.

  return lines;
}


void sort_and_print(FILE * f) {
       
  // unitialize for every arg the variables lines and n_lines
  //  1. lines is used to point to the first line
  char ** lines = NULL;
  //  2. n_lines will store the number of total lines (per arg)
  size_t n_lines=0;


  // get_lines returns the # of lines found
  // and manipulates lines to a char * [# of lines], 
  // where each element points to the respective line.
  lines = get_lines(f, &n_lines);

  sortData(lines, n_lines);
    
  print_lines(lines, n_lines);
 
  // to carefully free the allocated memory,
  // and initialize lines to NULL since it points to freed memory block
  free_lines(lines, n_lines);
}


int main(int argc, char ** argv) {
  
  
  if (argc > 1) {
    size_t arg = 1;
    do {
      
      FILE * f = fopen(argv[arg], "r");
      if (!f) {
        fprintf(stderr, "error: could not open file %s", argv[arg]);
        exit(EXIT_FAILURE);
      }
      
      sort_and_print(f);
      
      
      if (fclose(f)) {
        fprintf(stderr, "error: file %s closed inproperly", argv[arg]);
        exit(EXIT_FAILURE);
      }
        
           
      arg++;
    } while (argv[arg] != NULL);
  }
  else {
    sort_and_print(stdin);      
  }

  return EXIT_SUCCESS; 
}
