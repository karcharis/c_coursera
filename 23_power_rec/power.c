#include<stdlib.h>
#include<stdio.h>

unsigned power (unsigned base, unsigned exponent) {
  if (exponent == 0) {
    return 1;
  }
  else {
   return base*power(base, exponent-1);
  }
} 

