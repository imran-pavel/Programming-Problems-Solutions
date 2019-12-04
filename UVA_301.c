#include<stdio.h>

#define SIZE_ORDER 23
#define SIZE_B 8

int N, B, Order;
int Src[SIZE_ORDER], Dest[SIZE_ORDER], Pass[SIZE_ORDER];
int Count[SIZE_B];
int Max;

void initCase()
{
	int i;
	for (i = 0; i < SIZE_B; i++)
		Count[i] = 0;
}

void readCase()
{
	int i;
	for (i = 0; i < Order; i++)
		scanf("%d %d %d", &Src[i], &Dest[i], &Pass[i]);
}

void addOrder(int i)
{
	int j;
	for (j = Src[i]; j < Dest[i]; j++)
		Count[j] += Pass[i];
}

void subOrder(int i)
{
	int j;
	for (j = Src[i]; j < Dest[i]; j++)
		Count[j] -= Pass[i];
}

int checkValidity()
{
	int i;
	for (i = 0; i<B; i++) if (Count[i]>N)
		return 0;
	return 1;
}

void solve(int i, int earn)
{
	if (i == Order) {
		if (earn > Max)
			Max = earn;
		return;
	}
	addOrder(i);
	if (checkValidity())
		solve(i + 1, earn + (Dest[i] - Src[i])*Pass[i]);
	subOrder(i);
	solve(i + 1, earn);
}

void solveCase()
{
	Max = 0;
	solve(0, 0);
}

void printCase()
{
	printf("%d\n", Max);
}

int main()
{
	while (3 == scanf("%d %d %d", &N, &B, &Order)) {
		if (N + B + Order == 0)
			break;
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
