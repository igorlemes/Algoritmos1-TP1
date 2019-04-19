#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidate.h"
#include "util.h"

typedef struct university {
		int id;
    int m;
    int maxVacancies;
    int minimumGrade;
    int numberOfApplications;
    node *list;
} University ;

University  *alocateUniversities(int numberUni);
University *initUniversities(FILE *filePointerUni);
void printUniversity(void *ptr);
void printUniversities(University *universities);
void freeUniversities(University *universities);
void createCandidatesList(University *universities, Candidate *candidates);
int someUniversityisAvailable(node *matchedList, University *universities);
int isInList(node *list, University *university);

#endif // UNIVERSITY_H_INCLUDED
