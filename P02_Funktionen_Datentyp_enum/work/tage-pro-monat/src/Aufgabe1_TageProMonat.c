#include <stdio.h>
#include <stdlib.h>
#include <string.h> //-> Used for declaration of strlen function.
#include <ctype.h> //-> Used for declaration of isdigit function.

#define MAXINPUT 60 

enum month_t { JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

int istSchaltjahr(int);
int gibIntWert(char*, int, int);
int tageProMonat(int, int);

int main (int argc, char *argv[]) {
    
    int monat, jahr;
     
    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);
	
    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);    
    
    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

	// Ausgabe
	printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));
   
    return 0;
}

int gibIntWert(char* bereich, int start, int end)
{
    printf("Gib ein %s an.\n", bereich);
    int returnValue, i, length;
    char str[MAXINPUT];
    if(fgets(str, MAXINPUT, stdin) != NULL) {
        length = strlen(str);
        for (i=0;i<length -1; i++)
        {
            if (!isdigit(str[i]))
            {
                printf("Entered input is not a number\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    returnValue = atoi(str);
    if(returnValue < start || returnValue > end)
    {
        printf("Entered input is not in the allowed range\n");
        exit(EXIT_FAILURE);
    }

    return returnValue;
}

int tageProMonat(int jahr, int monat)
{
    switch (monat)
    {
        case FEB:
            return istSchaltjahr(jahr) ? 29 : 28;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30; 
        default:
            return 31;
    }
}

int istSchaltjahr(int jahr)
{
    if(jahr % 4 == 0)
    {
        if(jahr % 100 == 0)
        {
            if(jahr % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return 1;
}