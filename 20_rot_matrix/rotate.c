#include<stdlib.h>
#include<stdio.h>

/*
 * this function rotateds the elements of a 10x10 matrix
 * For example, the matrix 
 *
 *   1234
 *   abcd
 *   *+-/
 *   @#$%
 *
 * is rotated to 
 *
 *   @*a1
 *   #+b2
 *   $-c3
 *   %/d4
 *
 * First we compute rotaded[][],
 * then we write rotated[][] on matrix[][].
 *
 */

void rotate(char matrix[10][10]) {

  char rotated[10][10];
  
  // compute rotated
  for (int row  = 0; row < 10; row++) {
    for (int collumn = 0; collumn < 10; collumn++) {
    
      rotated[collumn][9-row] = matrix[row][collumn];  
  
    }
  }

  // write rotated to matrix
  for (int row  = 0; row < 10; row++) {
    for (int collumn = 0; collumn < 10; collumn++) {

      matrix[row][collumn] = rotated[row][collumn]; 
   
    }
  }

}

/*
 * Let us discuss how we may make the rotation in place.
 * 
 * We may perform the transformation in two steps:
 *  -step 1: reflect on the main diagonal, i.e. take the transpose
 *  -step 2: reflect on the vertical 
 *
 * Both steps could be performed without extra space.
 *
 *> char temp;
 *> for (int row = 0; row < 10; row++) {
 *>   for (column = 0; collumn < 10; collumn++) {   
 *>     temp = matrix[collumn][row];
 *>     matrix[collumn][row] = matrix[row][collumn];
 *>     matrix[row][collumn] = temp;
 *>   }
 *> }
 *>
 *> for..
 *>   for..
 *>     temp = matrix[row][N-1 - collumn];
 *>     matrix[row][N-1 - collumn] = matrix[row][collumn];
 *>     matrix[row][collumn] = temp;
 *>   }
 *> }
 *
 */
