#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "candidate.h"

struct university {
		int id;
    int m;
    int maxVacancies;
    int minimumGrade;
    int numberOfApplications;
    node *list;
};

struct university  *alocateUniversities(int numberUni);
struct university *initUniversities(FILE *filePointerUni);
void printUniversity(void *ptr);
void printUniversities(struct university *universities);
void freeUniversities(struct university *universities);
void createCandidatesList(struct university *universities, Candidate *candidates);
int someUniversityisAvailable(node *matchedList, struct university *universities);
int isInList(node *list, struct university *university);

#endif // UNIVERSITY_H_INCLUDED
