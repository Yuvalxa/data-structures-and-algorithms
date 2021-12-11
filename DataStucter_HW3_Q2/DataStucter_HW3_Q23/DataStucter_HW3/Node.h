#pragma once
typedef struct node
{
	int info;
	struct node* next;
} Node;
Node *del_func(Node *head, int *vec);
Node *searchBefore(Node *list, int x);
int delafter(Node *p);
int checkArrayOrder(int* arr);
void createListFromArr(Node* pLst, const int* arr, int size);
Node* L_insert(Node* pNode, int Value);


