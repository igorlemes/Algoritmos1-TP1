#ifndef CANDIDATE_H_INCLUDED
#define CANDIDATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "util.h"

typedef struct candidate{
		int id;
    int n;
		int grade;
    int numberOfApplications;
    node *list;
} Candidate;

Candidate *alocateCandidates(int numberCan);
Candidate *initCandidates(FILE *filePointerCan, University *universities);
void printCandidate(void *ptr);
void printCandidates(Candidate *candidates);
void freeCandidates(Candidate *candidates);
int compareGrades(const void *a, const void *b);

#endif //CANDIDATE_H_INCLUDED
