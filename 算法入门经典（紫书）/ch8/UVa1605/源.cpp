#include <cstdio>
#include <cstring>

char str[100];


void solve(int z)
{
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < z; j++)
		{
			if (i < 26)
				printf("%c", 'A' + i);
			else
				printf("%c", 'a' + i - 26);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < z; j++)
		{
			if (j < 26)
				printf("%c", 'A' + j);
			else
				printf("%c", 'a' + j - 26);
		}
		printf("\n");
	}
}


int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		printf("2 %d %d\n", n, n);
		solve(n);
	}
}