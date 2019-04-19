#ifndef CANDIDATE_H_INCLUDED
#define CANDIDATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "university.h"

struct candidate{
		int id;
    int n;
		int grade;
    int numberOfApplications;
    node *list;
};

struct candidate* alocateCandidates(int numberCan);
struct candidate* initCandidates(FILE *filePointerCan, University *universities);
void printCandidate(void *ptr);
void printCandidates(struct candidate* candidates);
void freeCandidates(struct candidate* candidates);
int compareGrades(void *a, void *b);

#endif //CANDIDATE_H_INCLUDED
