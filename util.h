#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidate.h"
#include "university.h"

typedef struct node{
	void* item;
	struct node *next;
} node;

struct Matched {
    Candidate *C;
    University *U;
};

node* new_node(void *item);
void insert(node **no, void *item);
FILE *fileOpener(char *arquivo);
void printList(node *list, void (*printFunction)(void *));
void freeNode(node *no);
int isMatched(node *matchedList, void *ptr);

#endif // UTIL_H_INCLUDED
