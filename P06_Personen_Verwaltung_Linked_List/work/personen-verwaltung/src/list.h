#ifndef _LIST_H_
#define _LIST_H_

#include "person.h"

typedef struct node {
  person_t     content;        // in diesem Knoten gespeicherte Person
  struct node *next;           // Pointer auf den nächsten Knoten in der Liste
} node_t;

void insert_sorted(person_t person);
void remove_person(person_t person);
void clear();
void get_list();
void print_list();
node_t get_testing_head();

#endif