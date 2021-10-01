#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cost, n, a[50][50], visited[50], start_city;
int least(int c)
{
	int i, ncity = 999;
	int min = 999;
	for (i = 0; i < n; i++)
	{
		if (a[c][i] != 0 && visited[i] == 0)
		{
			if (a[c][i] < min)
			{
				min = a[c][i];
				ncity = i;
			}
		}
	}
	if (ncity != 999)
		cost += min;
	return ncity;
}

void mincost(int city)
{
	int ncity;
	visited[city] = 1;
	printf("%d-->", city + 1);
	ncity = least(city);
	if (ncity == 999)
	{
		printf("%d", start_city);
		cost += a[city][start_city - 1];
		return;
	}
	mincost(ncity);
}

int main()
{
	int i, j;
	clock_t start, end;
	double clk;
	cost = 0;

	printf("\nEnter the no of cities : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		visited[i] = 0;

	printf("Enter the cost matrix : \n");
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}

	printf("\nEnter the starting city : ");
	scanf("%d", &start_city);

	printf("\nShortest path between cities : ");

	start = clock();
	mincost(start_city - 1);
	end = clock();

	clk = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\n\nMinimum Cost : %d\n\n", cost);

	printf("Time taken for execution : %lf\n\n", clk);
	return 0;
}