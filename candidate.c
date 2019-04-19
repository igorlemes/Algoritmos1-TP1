#include "candidate.h"
#include "types.h"

struct candidate *alocateCandidates(int numberCan){
  struct candidate *candidates = NULL;
  candidates = (Candidate*)malloc(numberCan * sizeof(Candidate));
  for (int i = 0; i < numberCan; i++) {
			candidates[i].id = -1;
      candidates[i].n = numberCan;
      candidates[i].grade = -1;
      candidates[i].numberOfApplications = -1;
      candidates[i].list = NULL;
  }
  return candidates;
}

struct candidate *initCandidates(FILE *filePointerCan, University *universities){
  int numberCan;
  fscanf(filePointerCan, "%d", &numberCan);
  // // Aloca memória para os candidates
  struct candidate *candidates = alocateCandidates(numberCan);
	int aux;
  for (int i = 0; i < numberCan; i++) {
    candidates[i].id = i;
    fscanf(filePointerCan, "%d", &candidates[i].numberOfApplications);
    fscanf(filePointerCan, "%d", &candidates[i].grade);
    for (int j = 0; j < candidates[i].numberOfApplications; j++) {
			fscanf(filePointerCan, "%d", &aux);
			insert(&candidates[i].list, &universities[aux-1]);
    }
  }
  fclose(filePointerCan);
  return candidates;
}

void printCandidate(void *ptr){
  struct candidate *c = ptr;
  printf("struct candidate %d:\tGrade: %d\tNumber of Aplications: %d\n",
    c->id, c->grade, c->numberOfApplications);
}

void printCandidates(struct candidate *candidates){
	for (int i = 0; i < candidates[0].n; i++) {
		printf("struct candidate %d:\tGrade: %d\tNumber of Aplications: %d\n",
      candidates[i].id, candidates[i].grade, candidates[i].numberOfApplications);
	  printList(candidates[i].list, &printUniversity);
  }
}

void freeCandidates(struct candidate *candidates){
	for (int i = 0; i < candidates[0].n; i++) {
		freeNode(candidates[i].list);
	}
	free(candidates);
}

int compareGrades(void *a, void *b){
  struct candidate *c = a;
  struct candidate *d = b;
  if ( c->grade > d->grade ) return -1;
  if ( c->grade == d->grade){
    if(c->id > d->id){
      return -1;
    } else if (c->id < d->id){
      return 1;
    }
  }
  if ( c->grade < d->grade ) return 1;
}
