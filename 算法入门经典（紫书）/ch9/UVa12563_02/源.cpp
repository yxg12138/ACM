#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50 + 5;
int T, n, t, a[maxn], dp[180 * maxn];

int main()
{
	//freopen("in2.txt","r",stdin);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		scanf("%d%d", &n, &t);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int MAX = 180 * n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = MAX; j >= a[i]; j--)
			{
				if (dp[j - a[i]] >= 0)
				{
					dp[j] = max(dp[j], dp[j - a[i]] + 1);
				}
			}
		}
		int ans = 0, sum = 0;
		for (int i = 0; i < t; i++)
		{
			if (dp[i] >= ans)
			{
				ans = dp[i];
				sum = i;
			}
		}
		printf("Case %d: %d %d\n", cas, ans + 1, sum + 678);
	}
	return 0;
}