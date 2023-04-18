#include <stdlib.h>
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)       \
    (byte & 0x80 ? '1' : '0'),     \
        (byte & 0x40 ? '1' : '0'), \
        (byte & 0x20 ? '1' : '0'), \
        (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), \
        (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0')

int main()
{
    unsigned int number = 0x75;
    unsigned int bit = 3; // bit at position 3

    printf("\nnum at start: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number));

    // Setting a bit
    number |= 1 << bit;

    printf("\nnum after setting: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number));

    // Clearing a bit
    bit = 1;
    number &= ~(1 << bit);

    printf("\nnum after clearing: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number));

    // Toggling a bit
    bit = 0;
    number ^= 1 << bit;

    printf("\nnum after toggling: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number));
    printf("\n");
    printf("number = 0x%02X\n", number);

    return EXIT_SUCCESS;
}