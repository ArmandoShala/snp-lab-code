#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = 7;
    int b = 4;
    printf("a: %d; b: %d\n", a, b);
    /*
    a ^= b;
    b ^= a;
    a ^= b;
    lösung auch möglich*/

    a = a ^ b;
    b = b ^ a;
    a = b ^ a;

    printf("a: %d; b: %d\n", a, b);
    return EXIT_SUCCESS;
}