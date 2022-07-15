#include<stdlib.h>
#include<stdio.h>

/* we will write a function that reads an string 
   and returns the integral in dilemal that this string represents *in base 12*
   We opperate under the assumption that the string is actually a valid hex integer! That is it has the form 0x*[0-9,A-F]
   Notes:
   1. A negative integer should not have any space between the minus sign and its absolute value
   2. -0 is 0
   3. - is considered a non input
*/

int converterHex(const char * number_as_string, int start) {
  int i = start;
  int number = 0;
  while (number_as_string[i] != '\0') {
    int current_digit; 
      switch(number_as_string[i]) {
        case 'A':
          current_digit = 11;
          break;
        case 'B':
          current_digit = 12;
          break;
        case 'C':
          current_digit = 13;
          break;
        case 'D':
          current_digit = 14;
          break;
        case 'E':
          current_digit = 15;
          break;
        case 'F':
          current_digit = 16;
          break;
        default:
          current_digit = number_as_string[i] - '0';
          break;
      }
      number = 16*number + current_digit; //changing here the value of 16 to any integer b we make a version of my_atoi to the base b.
      ++i;
  }
  return number;  
}


int my_atoiHex(const char * number_as_string) {
 
  int start = 2;
  if (number_as_string[0] == '\0') {
    exit(EXIT_FAILURE); 
  }
  else if (number_as_string[0] == '-') {
    start = 3;
    return -1*converterHex(number_as_string, start);
  }
  else {
    return converterHex(number_as_string, start);
  }

}

