#include <stdio.h>
#include "Node.h"
#include <stdlib.h>
#include <time.h>
// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

Node *del_func(Node *head, int *vec)
{
	//check vector
	if(!checkArrayOrder(vec)) return head;
	int counter = 0;
	Node *p;
	while(*vec!=-1)
	{
		p = searchBefore(head, *vec-counter);
		if (p->next == NULL) break;
		delafter(p);//del after p
		vec = vec + 1;//next vec
		counter++;
	}
	return head;
}

Node *searchBefore(Node *list, int x)
{
		if (list == NULL) return (NULL);

	for (int i = 0; i < x; i++)
	{
		list = list->next;
		if (list == NULL) return (NULL);
	}
	return (list);
}
int delafter(Node *p)
{
	Node *q;
	int x;
	if (p == NULL) {
		printf("ERROR\n");
		return(-1);
	}
	else
	{
		if (p->next == NULL)
		{
			printf("ERROR");
			return(-1);
		}

		else
		{
			q = p->next;
			x = q->info;
			p->next = q->next;
			free(q);
			return (x);
		}
	}
}int checkArrayOrder(int* arr)
{
	for (int i = 0; arr[i] != -1; i++)
		for (int j = i; arr[j] != -1; j++)
			if (arr[i] > arr[j]) return 0;
	return 1;
}
void createListFromArr(Node* pLst, const int* arr, int size)
{
	Node* pN = pLst;
	for (int i = 0; i < size; i++)
		pN = L_insert(pN, arr[i]);
	pN->next= NULL;

}
Node* L_insert(Node* pNode, int Value)
{
	Node* tmp;

	if (!pNode) return NULL;

	tmp = (Node*)malloc(sizeof(Node));    // new node

	if (tmp != NULL) {
		tmp->info = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}