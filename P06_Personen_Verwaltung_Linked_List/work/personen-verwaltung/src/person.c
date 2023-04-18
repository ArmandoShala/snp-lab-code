#include "person.h"
#include <stdio.h>
#include <string.h>
int person_compare(const person_t *a, const person_t *b) {
    /**
     * @brief  Compares two persons in this sequence: 1st=name, 2nd=first_name, 3rd=age
     * @param  a [IN] const reference to 1st person in the comparison
     * @param  b [IN] const reference to 2nd person in the comparison
     * @return =0 if all record fields are the same
     *         >0 if all previous fields are the same, but for this field, a is greater
     *         <0 if all previous fields are the same, but for this field, b is greater
     * @remark strncmp() is used for producing the result of string field comparisons
     * @remark a->age – b->age is used for producing the result of age comparison
     */
    int ret;
    ret = strcmp(a->name, b->name);
    if(ret == 0)
    {
        ret = strcmp(a->first_name, b->first_name);
        if(ret == 0)
        {
            return b->age - a->age;
        }
        return ret;
    }
    return ret;
}

void print_person(person_t person)
{
    printf("\nName: %s\n", person.name);
    printf("Vorname: %s\n", person.first_name);
    printf("Alter: %i\n", person.age);
}

person_t make_person(char firstName[NAME_LEN], char name[NAME_LEN], unsigned int age)
{
    person_t person;
    person.age = age;
    strcpy(person.first_name, firstName);
    strcpy(person.name, name);

    return person;
}