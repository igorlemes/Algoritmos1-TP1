#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	void* item;
	struct node *next;
} node;

struct Matched {
    Candidate *C;
    University *U;
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


FILE *fileOpener(char *arquivo){
  FILE *filePointer;
  filePointer = fopen(arquivo, "r");
  if(filePointer == NULL) {
      perror("Error opening file");
  }
  return filePointer;
}

void printList(node *list, void (*printFunction)(void *)){
  node *curr = list;
  while (curr != NULL){
    printFunction(curr->item);
    curr = curr->next;
  }
  free(curr);
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
    if(curr == NULL){
      return 0;
    } else if (curr->item == university){
      return 1;
    }
    curr = curr->next;
  }
}

int compareGrades(const void *a, const void *b){
  Candidate *c = a;
  Candidate *d = b;
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

void createCandidatesList(University *universities, Candidate *candidates){
  for (int i = 0; i < candidates[0].n; ++i){
    for (int j = 0; j < universities[0].m; ++j){
      if(isInList(candidates[i].list, &universities[j]) &&
        candidates[i].grade >= universities[j].minimumGrade){
        insert(&universities[j].list, &candidates[i]);
        universities[j].numberOfApplications++;
      }
    }
  }
  qsort (universities->list, universities->numberOfApplications,
		sizeof(Candidate), compareGrades);
}

node *stableMatching(){
    // Inicialize todos os h ∈ H e m ∈ M como solteiros
		node *M;
    while(some university U is unmatched and hasn't proposed to every candidate){
        c = primeiro candidato na lista de U ao qual U ainda não propôs
        Se m esta disponivel
            (h, m) começam a namorar
        Senao (h', m) já namoram
            Se m prefere o h do que o h'
                h' fica solteiro
                (h, m) começam a namorar
            Senao
                (h', m) continuam namorando
    }
}

int isMatched(node *matchedList, void *ptr){
	node *currMatchedList = matchedList;
	int matched = 0;
  while(currMatchedList != NULL){
    if(currMatchedList->item->U == ptr || currMatchedList->item->C == ptr){
      matched++;
		}
    currMatchedList = currMatchedList->next;
  }
	return matched;
}

int someUniversityisAvailable(node *matchedList, University *universities){
	for (size_t i = 0; i < universities[0].m; i++) {
		if(universities[i].numberOfApplications >
			isMatched(matchedList, &universities[i])) return 1;
	}
	return 0;
}

int main(int argc, char **argv){
  University *universities = initUniversities(fileOpener(argv[1]));
  Candidate *candidates = initCandidates(fileOpener(argv[2]), universities);
  createCandidatesList(universities, candidates);

	printCandidates(candidates);
  printf("\n");
	printUniversities(universities);

	freeCandidates(candidates);
	freeUniversities(universities);
  return 0;
}
