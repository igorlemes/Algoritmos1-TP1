#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	void* item;
	struct node *next;
} node;

typedef struct candidate{
    int grade; /*Ser ́a adotada como premissa que, quando outros aspectos forem
		iguais, os candidates com menor identificador tera prioridade*/
    int numeroAplicacoes;
    node *list; /* 0< Li≤ m por ordem de preferência (sem empates), nessa list
		não deve haver aquelas que o aluno não quer estudar}*/
} Candidate;

typedef struct university {
    int maxVacancies; /* A quantidade de vagas na university pode ser maior,
		menor ou igual a quantidade de aplicações */
    int minimumGrade;
    node *list; //Ordenam os alunos pela grade, dentre os que listram interesse
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
  for (size_t i = 0; i < numberCan; i++) {
      candidates[i].grade = -1;
      candidates[i].numeroAplicacoes = -1;
      candidates[i].list = NULL;
  }
  return candidates;
}

University  *alocateUniversities(int numberUni){
  University  *universities = NULL;
  universities = (University *)malloc(numberUni * sizeof(University ));
  for (size_t i = 0; i < numberUni; i++) {
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

  for (size_t i = 0; i < numberUni; i++) {
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
  for (size_t i = 0; i < numberCan; i++) {
    fscanf(filePointerCan, "%d", &candidates[i].numeroAplicacoes);
    fscanf(filePointerCan, "%d", &candidates[i].grade);
    for (size_t j = 0; j < candidates[i].numeroAplicacoes; j++) {
			fscanf(filePointerCan, "%d", &aux);
			insert(&candidates[i].list, &universities[aux]);
    }
  }
  fclose(filePointerCan);
  return candidates;
}

void printCandidates(Candidate *candidates){

}
void printUniversities(){}

// node *matchedList(){
//
//
// }

int main(int argc, char **argv){
  University *universities = initUniversities(fileOpener(argv[1]));
  Candidate *candidates = initCandidates(fileOpener(argv[2]), universities);

}
