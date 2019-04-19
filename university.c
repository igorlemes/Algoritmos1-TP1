#include "university.h"

University  *alocateUniversities(int numberUni){
  University  *universities = NULL;
  universities = (University *)malloc(numberUni * sizeof(University));
  for (int i = 0; i < numberUni; i++) {
       universities[i].id = -1;
			 universities[i].m = numberUni;
       universities[i].maxVacancies = -1;
       universities[i].minimumGrade = -1;
       universities[i].numberOfApplications = 0;
       universities[i].list = NULL;
  }
  return universities;
}

University *initUniversities(FILE *filePointerUni){
  int numberUni;
  fscanf(filePointerUni, "%d", &numberUni);
  // Aloca memória para as universities
  University  *universities = alocateUniversities(numberUni);

  for (int i = 0; i < numberUni; i++) {
    universities[i].id = i;
    fscanf(filePointerUni, "%d", &universities[i].maxVacancies);
    fscanf(filePointerUni, "%d", &universities[i].minimumGrade);
  }
  fclose(filePointerUni);
  return universities;
}

void printUniversity(void *ptr){
  University *u = ptr;
  printf("University: %d\tMinimum Grade: %d\tVacancies: %d\n",
    u->id, u->minimumGrade, u->maxVacancies);
}

void printUniversities(University *universities){
	for (int i = 0; i < universities[0].m; i++) {
		printf("University %d:\tMinimum Grade: %d\tVacancies: %d\t
		Number of Aplications: %d\n",
      universities[i].id,universities[i].minimumGrade,
			universities[i].maxVacancies, universities[i].numberOfApplications);
	  printList(universities[i].list, &printCandidate);
  }
}
