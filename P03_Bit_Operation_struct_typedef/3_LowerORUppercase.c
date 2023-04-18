#include <stdlib.h>
#include <stdio.h>

int main(){
  char word[8] = "sREedEv";
  char *wordptr = &word[0];

  while(wordptr < &word[7]) {
    printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
    printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
    wordptr++;
  }

  return EXIT_SUCCESS;
}

/*
UPPERCASE 
95: 0000000001011111 = _
s:  0000000001110011
&:  0000000001010011 -> 83 in Ascii Tabelle = S

LOWERCASE
32: 0000000000100000 space 
R:  0000000001010010
|:  0000000001110010 -> 114 in Ascii Tabelle = r
 */
