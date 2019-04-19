#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
