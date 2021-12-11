#pragma once

typedef struct node {
	int num;
	struct node *next;
} Node;

Node* combine_lists(Node *head1, Node *head2);
void initNode(Node* node, int n);
Node* insertNode(Node *ptr, int num);
Node* copyListToList(Node* head, Node* list);