#include <stdlib.h>
#include <stdio.h>

int main(){
  int a = 32; // any positive number
  if(a > 0 && !(a-1 & a)){
    printf("%d is a power of 2", a);
  }
  else
  {
    printf("%d is not a power of 2", a);
  }

  return EXIT_SUCCESS;
}