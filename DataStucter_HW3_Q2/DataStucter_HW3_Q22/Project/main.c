#include <stdio.h>
#include "Node.h"

void main()
{
	Node list1, list2;
	initNode(&list1, 2);
	initNode(&list2, 2);
	Node* list3 = combine_lists(&list1, &list2);
}		
