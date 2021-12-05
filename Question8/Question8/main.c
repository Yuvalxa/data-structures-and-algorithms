#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "question8.h"

void Init(int n, A* mat)
{
	mat->size = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			mat->matrix[i][j] = 1;
		mat->rowOnesCounter[i] = n;
		mat->rowOnesCounter[i + n] = 1;
	}
	mat->rowOnesCounter[2 * n] = n;
	mat->DNF = 1;
}

void Flip(A* mat, int i, int j)
{
	int n = mat->size;
	int rowCount = i, rowDNF = i + n, isDNF = 2 * n;
	if (mat->matrix[i][j] == 1) // turn cell into 0
	{
		mat->matrix[i][j] = 0;
		mat->rowOnesCounter[rowCount]--;
		if (mat->rowOnesCounter[rowDNF] == 1)
		{
			mat->rowOnesCounter[rowDNF] = 0;
			mat->rowOnesCounter[isDNF]--;
		}
		if (mat->rowOnesCounter[isDNF] == 0)
			mat->DNF = 0;
	}
	else // turn cell into 1
	{
		mat->matrix[i][j] = 1;
		mat->rowOnesCounter[rowCount]++;
		if (mat->rowOnesCounter[rowCount] == n)
		{
			mat->rowOnesCounter[rowDNF] = 1;
			mat->rowOnesCounter[isDNF]++;
			mat->DNF = 1;
		}
	}
}

int DNF(A* mat)
{
	return mat->DNF;
}

void main()
{
	A mat;
	int size = 4;
	//printf("Enter size of matrix :");
	//scanf("%d", &size);

	Init(size, &mat);
	Flip(&mat, 0, 1);
	Flip(&mat, 1, 2);
	Flip(&mat, 2, 3);
	Flip(&mat, 3, 0);
	printf("%d", DNF(&mat)); // not DNF
	Flip(&mat, 0, 1);
	Flip(&mat, 1, 2);
	Flip(&mat, 2, 3);
	Flip(&mat, 3, 0);
	printf("%d", DNF(&mat)); // DNF
}