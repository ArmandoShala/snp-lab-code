#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_LENGTH 20
#define STR_COUNT 10

void sort(int actual_str_count, char *strings[STR_COUNT]);
void str_to_upper(char *word);
int search_duplicate(int actual_str_count, char *strings[], int i);

int main(int argc, char const *argv[])
{
    char *strings[STR_COUNT];
    char abort[4] = "ZZZ";
    int actual_str_count = 0;
    int i = 0;
    while (i < STR_COUNT)
    {
        size_t len = 0;
        do
        {
            
            printf("Geben Sie ein Wort ein\n");
            strings[i] = malloc(STR_LENGTH);
            scanf("%s", strings[i]);
            // printf("Input: %s\n", strings[i]);
            len = strlen(strings[i]);
            if (len > STR_LENGTH)
            {
                printf("Das Wort ist zu lange\n");
            }
        } while (len > 20);
        // word to upper case
        str_to_upper(strings[i]);
        // printf("Uppercase: %s\n", strings[i]);

        // check for end signal
        if (strcmp(strings[i], abort) == 0)
        {
            printf("%s detected\n", abort);
            break;
        }
        int duplicate = search_duplicate(actual_str_count, strings, i);
        if (!duplicate)
        {
            actual_str_count++;
            i++;
        }
    }
    // printf("\nUnsorted\n");
    // for (int i = 0; i < actual_str_count; i++)
    // {
    //     printf("%d:%s\n", i, strings[i]);
    // }
    printf("\nSorted\n");
    sort(actual_str_count, strings);
    for (int i = 0; i < actual_str_count; i++)
    {
        printf("%d:%s\n", i, strings[i]);
    }

    return 0;
}

void sort(int actual_str_count, char *strings[STR_COUNT])
{
    for (int j = 0; j < actual_str_count; j++)
    {
        for (int i = j + 1; i < actual_str_count; i++)
        {
            if (strcmp(strings[j], strings[i]) > 0)
            {
                char *temp = strings[j];
                strings[j] = strings[i];
                strings[i] = temp;
            }
        }
    }
}

void str_to_upper(char *word)
{
    for (int j = 0; j < STR_LENGTH; j++)
    {
        if (word[j] >= 'a' && word[j] <= 'z')
        {
            word[j] = word[j] - 32;
        }
    }
}

int search_duplicate(int actual_str_count, char *strings[], int i)
{
    for (int j = 0; j < actual_str_count; j++)
    {
        // printf("i:%d\tj:%d\n", i, j);
        // printf("Comparing %s and %s\n", strings[i], strings[j]);
        if (strcmp(strings[i], strings[j]) == 0)
        {
            printf("String already in list\n");
            return 1;
        }
    }
    return 0;
}