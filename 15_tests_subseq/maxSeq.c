#include<stdlib.h>
#include<stdio.h>

size_t indexOfTop(int * array, size_t size) {
  //finds the maximal increasing subsequence staring from array[0]
  //returns the index of its the last element
  
  size_t index = 0;
  while (index < size - 1) {
    if (array[index] < array[index+1]) {
      ++index;
    }
    else break;
  }
  return index;
}

size_t maxSeq(int * array, size_t size) {
  
  if (size == 0 || array == NULL) {
    //if there are no elements or a null array we return failure
    return EXIT_FAILURE;
  }

  size_t ans = 1; //our return variable, there is always a one element subsequence

  int * rest = array; //this is the sub-array of array that needs to be examined for a subsequance
  
  size_t index = rest - array; //this is the index of the first element of rest, as an element of array
  size_t size_rest = size - index; //the size of rest

   while (size_rest > ans) {
    /*The boundary contition should normally be 
     *
     * size_rest > 0 (size_rest = size-index)
     *
     *Note that we may trim further the boundary condition using the fact that if 
     *
     * size - index <= ans
     *
     *then we can not find a better answer. Hence we may use
     *
     * size_rest > ans
     *
     */


    size_t temp_ans = indexOfTop(rest, size_rest) + 1;
    if (temp_ans > ans) {
      ans = temp_ans;
    }
    rest = rest + (int) temp_ans; 
    index = rest - array;
    size_rest = size - index;
  }

  return ans;
}
