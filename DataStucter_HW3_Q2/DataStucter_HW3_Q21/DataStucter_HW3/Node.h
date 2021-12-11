#pragma once
typedef struct node
{
	int num;
	struct node *next;
} Node;
Node *combine_lists(Node *head1, Node *head2);
void initNode(Node* node);