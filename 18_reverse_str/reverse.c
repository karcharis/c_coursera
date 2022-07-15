#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlgth(char * str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length; 
  //Note:
  //  we have to  subtract 1 to remove '\0' from the count,
  //  we have to add 1 since  we count from 0
 }

void reverse(char * str) {

  if (str == NULL) {
    return;    
  }

  if (str[0] == '\0') {
    return;
  }
  int last = strlgth(str)-1; 
  //note that this is the index of the last non '\0' char of str 
  
  char temp;
  for (int i=0; i < (last+1)/2; ++i) {
    temp = str[i];
    str[i] = str[last-i];
    str[last-i] = temp;
   }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
