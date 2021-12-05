#pragma once
#define N 20 // max size
typedef struct {
	int size;
	int matrix[N][N];
	int rowOnesCounter[2 * N + 1];
	int DNF;
} A;

void Init(int n, A*);
void Flip(A*, int i, int j);
int DNF(A*);