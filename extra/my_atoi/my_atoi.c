#include<stdlib.h>
#include<stdio.h>

/* we will write a function that reads an string 
   and returns the integral in dicemal that this string represents
   We opperate under the assumption that the string is actually a valid integer!
   Notes:
   1. A negative integer should not have any space between the minus sign and its absolute value
   2. -0 
   3. - is considered a non input
*/

int converter(const char * number_as_string, int start) {
  int i = start;
  int number = 0;
  while (number_as_string[i] != '\0') {
    int current_digit = number_as_string[i] - '0';
    number = 10*number + current_digit;
    ++i;
  }
  return number;  
}


int my_atoi(const char * number_as_string) { 
  int start = 0;
  if (number_as_string[0] == '\0') {
    exit(EXIT_FAILURE); 
  }
  else if (number_as_string[0] == '-') {
    start = 1;
    return -1*converter(number_as_string, start);
  }
  else {
    return converter(number_as_string, start);
  }
}

