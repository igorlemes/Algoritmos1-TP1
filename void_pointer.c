#include <stdio.h>
#include <stdlib.h>

// struct Match{
// 	Universidade U;
// 	Candidato C;
//}

// union Datatype{
// 	Universidade U;
// 	Candidato C;
// 	Match M;
//}

typedef struct no{
	void* item;
	struct no *next;
} no;

no* new_node(void *item){
	no *node = malloc(sizeof(no));
	node->item = item;
	node->next = NULL;
	return node;
}

void insert(no **node, void *item){
	no *n_node = new_node(item);
	if (*node == NULL) {
		*node = n_node;
		return;
	}
	no *curr = *node;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = n_node;
}

typedef struct frac{
	int den, num;
} frac;

int main(){
	no *list = NULL;
	
	while (1){
		frac *n = malloc(sizeof(frac));
		scanf("%d%*c%d", &n->num, &n->den);
		if (n->num == -1) {
			free(n);
			break;
		}
		insert(&list, n);
	}
	printf("list: ");
	while (list != NULL){
		no *curr = list;
		list = list->next;
		frac *v = ((frac*)curr->item);
		printf("%d/%d ", v->num, v->den);
		free(v);
		free(curr);
	}
	printf("\n");
	return 0;
}
