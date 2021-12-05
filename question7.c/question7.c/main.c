#include <stdio.h>

int Q7a(int A[], int start, int end)
{
	return A[end] - A[start] > end - start;
}

int Q7b(int A[], int start, int end)
{
	if (start > end) return -1;
	if (start + 1 == end) return A[start] + 1;
	int med = (start + end) / 2;
	if (Q7a(A, start, med))
		return Q7b(A, start, med);
	else
		return Q7b(A, med, end);
}

int Q7c(int A[], int start, int end)
{
	if (end < start)
		return 0;
	int m = (end + start) / 2;
	if (A[m] == m)
		return 1;
	if (A[m] > m)
		return Q7c(A, start, m - 1);
	else
		return Q7c(A, m + start, end);
}

void main()
{
	int qa1[] = { 1,2,3,4,5,7 };
	int qa2[] = { 1,2,3,4,5 };
	int start = 0, end1 = sizeof(qa1) / sizeof(int) - 1, end2 = sizeof(qa2) / sizeof(int) - 1;
	printf("In array qa1:\n");
	if (Q7a(qa1, start, end1))
		printf("element x exist\n");
	else
		printf("element x doesn't exist\n");

	printf("In array qa2:\n");
	if (Q7a(qa2, start, end2))
		printf("element x exist\n");
	else
		printf("element x doesn't exist\n");

	if (Q7a(qa1, start, end1)) // if number is missing
		printf("The missing element in array qa2 is: %d\n", Q7b(qa1, start, end1));
	else
		printf("No element is missing in qa2\n");

	int qa3[] = { 0,3,5,7,11 };
	int end3 = sizeof(qa3) / sizeof(int) - 1;
	if (Q7c(qa3, start, end3))
		printf("element A[i] = i exist in qa3");
	else
		printf("element A[i] = i doesn't exist in qa3");
}