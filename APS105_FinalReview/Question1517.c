#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node * link;
} Node;

Node * deleteFirstLast(Node * head) {
	Node * np = head;
	if (np == NULL) return NULL;
	free (np -> link);
	np -> link = np -> link -> link;
	while (np -> link -> link != NULL) {
		np = np -> link;
	}
	
	free (np -> link);
	np -> link = NULL;
	return head;
}