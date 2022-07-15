#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  // allocate enough memory for outputName
  // Note: outputname = inputName + ".counts"
  //       inputName has strlen(inputName) chars (except '\0')
  //       ".counts" has 7 chars (except \0') 
  char * outputName = malloc( sizeof(*outputName)*(strlen(inputName) + 8) );
  if (!outputName) {
    fprintf(stderr, "malloc returned NULL");
    exit(EXIT_FAILURE);
  }
      
  // assemble outputName 
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");

  return outputName;
  
}
