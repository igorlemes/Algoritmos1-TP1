#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato {
    int nota; //Ser ́a adotada como premissa que, quando outros aspectos forem iguais, os candidatos com menor identificador tera prioridade
    int numeroAplicacoes;
    int *lista; // 0< Li≤ m por ordem de preferência (sem empates), nessa lista não deve haver aquelas que o aluno não quer estudar}
} Candidato;

typedef struct universidade {
    int maxVagas; // A quantidade de vagas na universidade pode ser maior, menor ou igual a quantidade de aplicações
    int notaDeCorte;
    int *lista; // Ordenam os alunos pela nota, dentre os que listaram interesse }
} Universidade;

struct Node {
    Candidato matchedCandidato;
    Universidade matchedUniversidade;
    struct Node *next;
};

Candidato *alocaCandidatos(int numberCan){
  Candidato *candidatos = NULL;
  candidatos = (Candidato*)malloc(numberCan * sizeof(Candidato));
  for (size_t i = 0; i < numberCan; i++) {
      candidatos[i].nota = -1;
      candidatos[i].numeroAplicacoes = -1;
      candidatos[i].lista = NULL;
  }
  return candidatos;
}
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

Universidade *inicializaUniversidades(FILE *filePointerUni){
  int numberUni;
  fscanf(filePointerUni, "%d", &numberUni);
  // Aloca memória para as universidades
  Universidade *universidades = alocaUniversidades(numberUni);

  for (size_t i = 0; i < numberUni; i++) {
    fscanf(filePointerUni, "%d", &universidades[i].maxVagas);
    fscanf(filePointerUni, "%d", &universidades[i].notaDeCorte);
  }
  fclose(filePointerUni);
  return universidades;
}

Candidato *inicializaCandidatos(FILE *filePointerCan){
  int numberCan;
  fscanf(filePointerCan, "%d", &numberCan);
  // // Aloca memória para os candidatos
  Candidato *candidatos = alocaCandidatos(numberCan);
  for (size_t i = 0; i < numberCan; i++) {
    fscanf(filePointerCan, "%d", &candidatos[i].numeroAplicacoes);
    fscanf(filePointerCan, "%d", &candidatos[i].nota);
    candidatos[i].lista = malloc(candidatos[i].numeroAplicacoes * sizeof(int));
    for (size_t j = 0; j < candidatos[i].numeroAplicacoes; j++) {
      fscanf(filePointerCan, "%d", &candidatos[i].lista[j]);
    }
  }
  fclose(filePointerCan);
  return candidatos;

}
int main(int argc, char **argv){
  Universidade *universidades = inicializaUniversidades(fileOpener(argv[1]));
  Candidato *candidatos = inicializaCandidatos(fileOpener(argv[2]));


}
