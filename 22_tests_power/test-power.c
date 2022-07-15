#include<stdlib.h>
#include<stdio.h>

unsigned power (unsigned x, unsigned y);
// x is the base
// y is the exponent

unsigned power_correct (unsigned base, unsigned exponent) {
  unsigned ans = 1;
  while (exponent > 0) {
    ans *= base;
    exponent--;
  }
  return ans;
}

void run_check(unsigned base, unsigned exponent) {


  if (power(base, exponent) != power_correct(base, exponent)) {
   // printf("power(%u,%u) returns %u while %u is expected", base, exponent, power_correct(base, exponent));
    exit(EXIT_FAILURE);
  }

}
     
int main(void) {

  // test 1
  run_check(1,0);
  // test 2
  run_check(0,0);
  // test 3
  run_check(0,1);
  // test 4
  run_check(-1,2);
  // test 5
  run_check(2,-1);

  // tests
  for (int i = 0; i < 10; i++) {
    run_check(2, i/2);
  }
  return EXIT_SUCCESS;
}
