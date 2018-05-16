#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

typedef struct node Node;

// Creating a new node
Node * newNode (Node * link, int data) {
	Node * np = (Node *) malloc (sizeof(Node)); 
	if (np == NULL) {
		exit (EXIT_FAILURE);
	}
	np -> data = data;
	np -> link = link;
}

// Inserting a new node at the front of the list
Node * insertAtFront (Node * head, int data) {
	Node * np = head;
	if (head == NULL) {
		return newNode(data, NULL);
		
	}
}