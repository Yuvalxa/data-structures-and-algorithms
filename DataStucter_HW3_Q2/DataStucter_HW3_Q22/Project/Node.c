#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Node.h"

void initNode(Node* node, int n)
{
	if (n == 0)
	{
		node->next = NULL;
		return;
	}
	Node* ptr;
	Node* head = node;
	srand(time(NULL));
	int random = 0; //= rand() % 10;
	for (int i = 0; i < n; i++)
	{
		ptr = (Node*)malloc(sizeof(Node));
		random = rand() % 20;
		ptr->num = random;
		node->next = ptr;
		node = node->next;
	}
	node->next = head;
}

Node* insertNode(Node* ptr, int num)
{
	if (ptr == NULL) return NULL;
	Node* newPtr = (Node*)malloc(sizeof(Node));
	newPtr->num = num;
	newPtr->next = ptr->next;
	ptr->next = newPtr;
	return newPtr;
}

Node* copyListToList(Node* head, Node* list) 
{
	if (head == NULL) head = (Node*)malloc(sizeof(Node));
	if (list->next == NULL) return head;

	Node* listPtr = list->next, *headPtr = head;
	while (listPtr != list)
	{
		headPtr = insertNode(headPtr, listPtr->num);
		listPtr = listPtr->next;
	}
	headPtr->next = head;
	return head;
}

Node* combine_lists(Node* list1, Node* list2)
{
	Node* head3 = (Node*)malloc(sizeof(Node));
	
	if (list1->next == NULL && list2->next == NULL)
		return head3;
	else if (list1->next == NULL) return copyListToList(head3, list2);
	else if(list2->next == NULL) return copyListToList(head3, list1);

	int flag1 = 0, flag2 = 0;
	Node* ptr1 = list1->next, *ptr2 = list2->next, *list = head3;

	while (1)
	{
		// ptr1
		list = insertNode(list, ptr1->num);
		// ptr2
		list = insertNode(list, ptr2->num);

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (ptr1 == list1)
		{
			if(!flag1) flag1 = 1;
			ptr1 = ptr1->next;
		}
		if (ptr2 == list2)
		{
			if(!flag2) flag2 = 1;
			ptr2 = ptr2->next;
		}

		if (flag1 && flag2)
		{
			list->next = head3;
			break;
		}
	}
	return head3;
}