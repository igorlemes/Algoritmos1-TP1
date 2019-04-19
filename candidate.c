#inlcude "candidate.h"
#include "university.h"

Candidate *alocateCandidates(int numberCan){
  Candidate *candidates = NULL;
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

Candidate *initCandidates(FILE *filePointerCan, University *universities){
  int numberCan;
  fscanf(filePointerCan, "%d", &numberCan);
  // // Aloca memória para os candidates
  Candidate *candidates = alocateCandidates(numberCan);
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
  Candidate *c = ptr;
  printf("Candidate %d:\tGrade: %d\tNumber of Aplications: %d\n",
    c->id, c->grade, c->numberOfApplications);
}

void printCandidates(Candidate *candidates){
	for (int i = 0; i < candidates[0].n; i++) {
		printf("Candidate %d:\tGrade: %d\tNumber of Aplications: %d\n",
      candidates[i].id, candidates[i].grade, candidates[i].numberOfApplications);
	  printList(candidates[i].list, &printUniversity);
  }
}
