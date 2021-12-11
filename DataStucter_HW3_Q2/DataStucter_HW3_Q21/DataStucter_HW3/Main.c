#include <stdio.h>
#include "Node.h"
void main()
{
	Node node1;
	Node node2;
	int n2 = 2;
	int n1 = 3;
	initNode(&node1, n1);
	initNode(&node2, n2);
	combine_lists(&node1, &node2);
}