#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	void* item;
	struct node *next;
} node;

typedef struct candidate{
		int id;
    int n;
		int grade;
    int numeroAplicacoes;
    node *list;
} Candidate;

typedef struct university {
		int id;
    int m;
    int maxVacancies;
    int minimumGrade;
    node *list;
} University ;

struct Matched {
    Candidate C;
    University U;
};

node* new_node(void *item){
	node *no = malloc(sizeof(node));
	no->item = item;
	no->next = NULL;
	return no;
}

void insert(node **no, void *item){
	node *n_node = new_node(item);
	if (*no == NULL) {
		*no = n_node;
		return;
	}
	node *curr = *no;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = n_node;
}

Candidate *alocateCandidates(int numberCan){
  Candidate *candidates = NULL;
  candidates = (Candidate*)malloc(numberCan * sizeof(Candidate));
  for (int i = 0; i < numberCan; i++) {
			candidates[i].id = -1;
      candidates[i].n = numberCan;
      candidates[i].grade = -1;
      candidates[i].numeroAplicacoes = -1;
      candidates[i].list = NULL;
  }
  return candidates;
}

University  *alocateUniversities(int numberUni){
  University  *universities = NULL;
  universities = (University *)malloc(numberUni * sizeof(University));
  for (int i = 0; i < numberUni; i++) {
       universities[i].id = -1;
			 universities[i].m = numberUni;
       universities[i].maxVacancies = -1;
       universities[i].minimumGrade = -1;
       universities[i].list = NULL;
  }
  return universities;
}

FILE *fileOpener(char *arquivo){
  FILE *filePointer;
  filePointer = fopen(arquivo, "r");
  if(filePointer == NULL) {
      perror("Error opening file");
  }
  return filePointer;
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

Candidate *initCandidates(FILE *filePointerCan, University *universities){
  int numberCan;
  fscanf(filePointerCan, "%d", &numberCan);
  // // Aloca memória para os candidates
  Candidate *candidates = alocateCandidates(numberCan);
	int aux;
  for (int i = 0; i < numberCan; i++) {
    candidates[i].id = i;
    fscanf(filePointerCan, "%d", &candidates[i].numeroAplicacoes);
    fscanf(filePointerCan, "%d", &candidates[i].grade);
    for (int j = 0; j < candidates[i].numeroAplicacoes; j++) {
			fscanf(filePointerCan, "%d", &aux);
			insert(&candidates[i].list, &universities[aux-1]);
    }
  }
  fclose(filePointerCan);
  return candidates;
}

void printUniversity(void *ptr){
  University *u = ptr;
  printf("University: %d\tMinimum Grade: %d\tVacancies: %d\n",
    u->id, u->minimumGrade, u->maxVacancies);
}

void printCandidate(void *ptr){
  Candidate *c = ptr;
  printf("Candidate %d:\tGrade: %d\tNumber of Aplications: %d\n", 
    c->id, c->grade, c->numeroAplicacoes);  
}

void printList(node *list, void (*printFunction)(void *)){
  node *curr = list;
  while (curr != NULL){
    printFunction(curr->item);
    curr = curr->next;
  }
  free(curr);
}

void printCandidates(Candidate *candidates){
	for (int i = 0; i < candidates[0].n; i++) {
		printf("Candidate %d:\tGrade: %d\tNumber of Aplications: %d\n", candidates[i].id, candidates[i].grade, candidates[i].numeroAplicacoes);
	  printList(candidates[i].list, &printUniversity);
  }
}
void printUniversities(University *universities){
	for (int i = 0; i < universities[0].m; i++) {
		printf("University %d:\tMinimum Grade: %d\tVacancies: %d\n", universities[i].id,universities[i].minimumGrade, universities[i].maxVacancies);
	  printList(universities[i].list, &printCandidate);
  }
}

void freeNode(node *no){
  while (no != NULL){
    node *curr = no;
    no = no->next;
    free(curr);
  }
}

void freeCandidates(Candidate *candidates){
	for (int i = 0; i < candidates[0].n; i++) {
		freeNode(candidates[i].list);
	}
	free(candidates);
}

void freeUniversities(University *universities){
	for (int i = 0; i < universities[0].m; i++) {
		freeNode(universities[i].list);
	}
	free(universities);
}

int isInList(node *list, University *university){
  /*verifica se a universidade está na lista passada*/
  node *curr = list;
  
  while(1){
    if(list == NULL){
      free(curr);
      return 0;
    } else if (curr->item == university){
      free(curr);
      return 1;
    }
    curr = curr->next;
  }
}

void createCandidatesList(University *universities, Candidate *candidates){
  for (int i = 0; i < candidates[0].n; ++i){
    for (int j = 0; j < universities[0].m; ++j){
      if(isInList(candidates[i].list, &universities[j]) && 
        candidates[i].grade >= universities[j].minimumGrade){
        insert(&universities[j].list, &candidates[i]);
      }
    }
  }
}

int main(int argc, char **argv){
  University *universities = initUniversities(fileOpener(argv[1]));
  Candidate *candidates = initCandidates(fileOpener(argv[2]), universities);
  // createCandidatesList(universities, candidates);

	printCandidates(candidates);
	printUniversities(universities);

	freeCandidates(candidates);
	freeUniversities(universities);
  return 0;
}
