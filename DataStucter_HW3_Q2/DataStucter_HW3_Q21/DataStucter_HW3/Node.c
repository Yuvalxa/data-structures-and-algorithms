#include <stdio.h>
#include "Node.h"
#include <stdlib.h>
#include <time.h>
Node *combine_lists(Node *head1, Node *head2)
{
	int sum1 = 0, sum2 = 0;
	Node* ptr1 = head1->next;
	Node* ptr2 = head2->next;
	Node* previus1=head1, *previus2=head2;
	while (ptr1||ptr2)
	{
		if (ptr1)
		{
			sum1 += ptr1->num;
			previus1 = ptr1;
			ptr1 = ptr1->next;
		}
		if (ptr2!=NULL)
		{
			sum2 += ptr2->num;
			previus2 = ptr2;
			ptr2 = ptr2->next;
		}
	}
	 if (sum2 > sum1)
	{
		previus2->next = head1->next;
		previus1->next = head2->next;
		return head2;
	}
	else
	{
		previus1->next = head2->next;
		previus2->next = head1->next;
		return head1;
	}
}
void initNode(Node* node,int n)
{
	Node* ptr;
	srand(time(NULL));
	int random = 0; //= rand() % 10;
	for (int i = 0; i < n; i++)
	{
		ptr = (Node*)malloc(sizeof(Node));
		random = rand() % 10;
		ptr->num = random;
		node->next = ptr;
		node = node->next;
	}
	node->next = NULL;
}