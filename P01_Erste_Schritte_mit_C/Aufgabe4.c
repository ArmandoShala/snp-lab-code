//Zeichen und wörter zählen

#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("Gib Zeichen ein \n");
    char current = getchar();
    int anzahlZeichen = 0;
    int anzahlWoerter = 0;
    int isWord = 0;
    while(current != '\n')
    {
        printf("chars is %c \n", current);
        anzahlZeichen++;
        
        if((current == ' ' || current == '\t')){
            if(isWord)
            {
                anzahlWoerter++;
                isWord = 0;
            }
        }
        else
        {
            isWord = 1;
        }
        current = getchar();
    }
    if(isWord)
    {
        anzahlWoerter++;
    }

    printf("Anzahl Zeichen: %d\n", anzahlZeichen);
    printf("Anzahl Woerter: %d\n", anzahlWoerter);
    
    return EXIT_SUCCESS;
}