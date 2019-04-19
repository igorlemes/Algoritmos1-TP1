#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "candidate.h"

struct node{
	void* item;
	struct node *next;
};

struct Matched {
    Candidate *C;
    University *U;
};

struct node *new_node(void *item);
void insert(struct node **no, void *item);
FILE *fileOpener(char *arquivo);
void printList(struct node *list, void (*printFunction)(void *));
void freeNode(struct node *no);
int isMatched(struct node *matchedList, void *ptr);

#endif // UTIL_H_INCLUDED
