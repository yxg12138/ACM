#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
int a[15][110];
int dp[15][110];
int _next[15][110];

int main()
{
// 	freopen("in.txt", "r", stdin);
	int m, n;
	while (~scanf("%d%d", &m, &n))
	{
		int ans = INF, first = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				if (j == n - 1) dp[i][j] = a[i][j];
				else
				{
					int row[3] = { i, i - 1, i + 1 };
					if (i == 0) row[1] = m - 1;
					if (i == m - 1) row[2] = 0;
					sort(row, row + 3);
					dp[i][j] = INF;
					for (int k = 0; k < 3; k++)
					{
						int v = dp[row[k]][j + 1] + a[i][j];
						if (v < dp[i][j]) { dp[i][j] = v; _next[i][j] = row[k]; }
					}
				}
				if (j == 0 && dp[i][j] < ans){ ans = dp[i][j]; first = i; }
			}
		}
		printf("%d", first + 1);
		for (int i = _next[first][0], j = 1; j < n; i = _next[i][j], j++)
			printf(" %d", i + 1);
		printf("\n%d\n", ans);
	}
}