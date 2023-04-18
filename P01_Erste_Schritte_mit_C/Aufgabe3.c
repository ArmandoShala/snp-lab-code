/*Dateien lesen/scheiben*/
#include <stdio.h>  //ist für printf
#include <stdlib.h> // ist für EXIT_SUCCESS
#define  NUM_ROW 8
int main(void)
{
    double fac;
    printf("Enter conversion rate (1.00 BTC -> CHF):");
    scanf("%lf", &fac);

    printf("\nder faktor ist %f \n", fac);
    int i;
    for (int i = 200; i <= 200 * NUM_ROW; i += 200)
    {
        double btc = i / fac;
        printf("\n%d CHF <--> %f BTC", i, btc);
    }
    return EXIT_SUCCESS;
}
