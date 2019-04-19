#include "util.h"

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
