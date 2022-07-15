#include<stdlib.h>
#include<stdio.h>

int my_atoi(const char * number_as_string);

int my_atoiHex(const char * number_as_string);

int main(void) {

  const char * str1 = "11";
  const char * str1Hex = "0x11";

  const char * str2 = "1445";
  const char * str2Hex = "0x1445";

  const char * str3 = "-234";
  const char * str3Hex = "-0x234";


  printf("The string %s represents in base 10 \n\t the number: %d\n", str1, my_atoi(str1));

  printf("The string %s represents in base 16 \n\t the number: %d\n", str1Hex, my_atoiHex(str1Hex));
 
   
      printf("The string %s represents in base 10 \n\t the number: %d\n", str2, my_atoi(str2));

  printf("The string %s represents in base 16 \n\t the number: %d\n", str2Hex, my_atoiHex(str2Hex));

   
    printf("The string %s represents in base 10 \n\t the number: %d\n", str3, my_atoi(str3));

  printf("The string %s represents in base 16 \n\t the number: %d\n", str3Hex, my_atoiHex(str3Hex));

  return EXIT_SUCCESS;
}
