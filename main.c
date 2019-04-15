#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato {
    int nota; //Ser ́a adotada como premissa que, quando outros aspectos forem iguais, os candidatos com menor identificador tera prioridade
    int *lista; // 0< Li≤ m por ordem de preferência (sem empates), nessa lista não deve haver aquelas que o aluno não quer estudar}
} Candidato;

typedef struct universidade {
    int maxVagas; // A quantidade de vagas na universidade pode ser maior, menor ou igual a quantidade de aplicações
    int notaDeCorte;
    struct Node *lista; // Ordenam os alunos pela nota, dentre os que listaram interesse }
} Universidade;

struct Node {
    Candidato *candidatoInscrito;
    struct Node *next;
};

// Candidato *alocaCandidatos(int numberCan){
//   *candidatos = (Candidato*)malloc(numberCan * sizeof(**Candidato));
//
// }
// https://stackoverflow.com/questions/41040440/returning-a-dynamically-allocated-array-of-structures-from-a-function-in-c
Universidade *alocaUniversidades(int numberUni){
  Universidade *universidades = NULL;
  universidades = (Universidade*)malloc(numberUni * sizeof(Universidade));
  for (size_t i = 0; i < numberUni; i++) {
       universidades[i].maxVagas = -1;
       universidades[i].notaDeCorte = -1;
       universidades[i].lista = NULL;
  }
  return universidades;
}


FILE *fileOpener(char *arquivo){
  FILE *filePointer;
  filePointer = fopen(arquivo, "r");
  if(filePointer == NULL) {
      perror("Error opening file");
  }
  return filePointer;
}

int main(int argc, char **argv){

  FILE *filePointerUni = fileOpener(argv[1]);
  // Numero de universidades
  int numberUni;
  fscanf(filePointerUni, "%d", &numberUni);
  // Aloca memória para as universidades
  Universidade *universidades = alocaUniversidades(numberUni);

  for (size_t i = 0; i < numberUni; i++) {
    fscanf(filePointerUni, "%d", &universidades[i].maxVagas);
    fscanf(filePointerUni, "%d", &universidades[i].notaDeCorte);

    // printf("%d\t%d\n", (*universidades)[i].maxVagas, (*universidades)[i].notaDeCorte);
  }
  fclose(filePointerUni);

/*
  FILE *filePointerCan = fileOpener(argv[2]);
  // Numero de candidatos
  int numberCan;
  fscanf(filePointerCan, "%d", &numberCan);
  // // Aloca memória para os candidatos
  Candidato *candidatos = NULL;
  alocaCandidatos(numberCan, &candidatos);
  fclose(filePointerCan);
*/

}
