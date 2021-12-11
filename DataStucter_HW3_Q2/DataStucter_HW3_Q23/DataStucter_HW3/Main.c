#include <stdio.h>
#include "Node.h"
void main()
{
	int vec[] = { 0,3,5,7,8,-1 };
	int arr[] = { 2,4,6,9,1,3,5,7 };
	Node list;
	createListFromArr(&list,arr,8);
	del_func(&list, vec);
}