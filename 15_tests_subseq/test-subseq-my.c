#include<stdlib.h>
#include<stdio.h>

size_t maxSeq(int * array, size_t size);

int main(void) {

  int array1[]= {1, 2, 3, 4, 5};
  int array2[]= {1, 2, 3, 4, 3};
  int array3[]= {-1, -2, -3, 1};
  int array4[]= {-1, 1, -10, 10};
  int array5[]= {3, 2, -1, -4};
  int array6[]= {0, 0, 0};
  int array7[]= {0, 15, 15, 15};
  size_t toprint;
  if (maxSeq(array1,5)!=5) {
    toprint = maxSeq(array1,5);
    printf("failed on 1st, ans returned:%zu while expected 5\n", toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array2,5)!=4) {
    toprint=maxSeq(array2,5);
    printf("failed on 2nd, ans returned:%zu while expected 4\n", toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array3,4)!=2) {
    toprint=maxSeq(array3,4);
    printf("failed on 3rd, ans returned:%zu while expected 2\n",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array4,4)!=2) {
    toprint=maxSeq(array4,4);
    printf("failed on 4th, ans returned:%zu while expected 2\n",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array5,4)!=1) {
    toprint=maxSeq(array5,4);
    printf("failed on 5th, ans returned:%zu while expected 1\n",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6,3)!=1) {
    toprint=maxSeq(array6,3);
    printf("failed on 6th, ans returned:%zu while expected 1\n",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array7,4)!=2) {
    toprint=maxSeq(array7,4);
    printf("failed on  array7, ans returned:%zu while expected 1\n",toprint);
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
