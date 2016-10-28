#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int w[1005], val[1005];
int dp[1005] = { 0 };

int main()
{
	int n, v, T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &v);
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = v; j >= w[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + val [i]);
			}
		}
		printf("%d\n", dp[v]);
	}

	return 0;
}