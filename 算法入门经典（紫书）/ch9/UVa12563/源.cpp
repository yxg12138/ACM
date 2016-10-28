#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int n, t, w[55], dp[10000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &t);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &w[i]);
		}

		memset(dp, 0, sizeof(dp));

		int ma = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = t - 1; j >= w[i]; j--)
			{
				if (dp[j - w[i]] >=1 || j == w[i])
				{
					dp[j] = max(dp[j], dp[j - w[i]] + 1); 
					ma = max(ma, dp[j]);
				}
			}
		}
		int k;
		for (k = t - 1; dp[k] != ma; k--);

		if (ma == 0)                            
			printf("Case %d: %d %d\n", cas, 1, 678);
		else
			printf("Case %d: %d %d\n", cas, 1 + ma, k + 678);
	}
	

}
