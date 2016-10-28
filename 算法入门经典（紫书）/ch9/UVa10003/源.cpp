#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[55];
int dp[1005][1005];

int main()
{
// 	freopen("in.txt", "r", stdin);
	int n,L;
	while (~scanf("%d", &L) && L)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		a[0] = 0, a[n + 1] = L;
		memset(dp, 0, sizeof(dp));
		int i, j, k;
		int minn;
		for (int p = 1; p <= n + 1; p++)
		{
			for (int i = 0; i <= n + 1; i++)
			{
				int j = i + p;
				if (j > n + 1)
					break;
				minn = INF;
				for (int k = i + 1; k < j; k++)
				{
					int tmp = dp[i][k] + dp[k][j] + a[j] - a[i];
					if (tmp < minn) minn = tmp;
				}
				if (minn != INF) dp[i][j] = minn;
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}


}