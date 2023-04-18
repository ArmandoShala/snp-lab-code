#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "person.h"

struct node* head = NULL;

node_t get_testing_head()
{
    return *head;
}

void insertAt(person_t person, struct node* afterThisNode)
{  
    if(head == NULL)
    {
        //This means that the list is empty.
        //Add it to the head.
        head = (struct node*)malloc(sizeof(struct node));
        head->content = person;
        head->next = NULL;
    }
    else
    {
        //TODO: This made a seg fault i think
        if(afterThisNode->next == NULL)
        {
            //This means, append at the end of the list.
            //TODO: Should check if malloc worked lol
            afterThisNode->next = (struct node*)malloc(sizeof(struct node));
            if (afterThisNode->next != NULL)
            {
                // malloc worked
                afterThisNode->next->content = person;
                afterThisNode->next->next = NULL;
            }
            else {
                printf("ERROR: Malloc did not work\n");
                exit(112043);
            }
        }
        else
        {
            //Insert somewhere in the middle.
            struct node* before = afterThisNode;
            struct node* after = afterThisNode->next;

            before->next = (struct node*)malloc(sizeof(struct node));
            before->next->content = person;
            before->next->next = after;
        }
    }
}

void insert_sorted(person_t person)
{
    if (head == NULL)
    {
        // handle first node
        insertAt(person, head);
        return;
    }
    struct node* current = head;

    while(current != NULL)
    {
        if(person_compare(&(current->content), &person) == 0)
        {
            printf("duplicate\n");
            return;
        }
        if(person_compare(&(current->content), &person) < 0)
        {
            //Insert.
            insertAt(person, current);
            return;
        }
        current = current->next;
    }
    insertAt(person, head);
}

void remove_person(person_t person){
    struct node* current = head;

    while(current != NULL)
    {
        if(current->next && person_compare(&(current->next->content), &person) == 0)
        {
            node_t* next = current->next;
            if (current->next->next)
            {
                *current->next = *current->next->next;
            }
            else {
                current->next = NULL;
            }
            return;
        }
        current = current->next;
    }
}
void clear(){
    node_t* current = head;
    node_t* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}
void get_list(){

}

void print_list(){
    struct node* current = head;

    if(current == NULL)
    {
        printf("Keine Personen erfasst!\n");
        return;
    }

    while (current != NULL) {
        print_person(current->content);
        current = current->next;
    }
}