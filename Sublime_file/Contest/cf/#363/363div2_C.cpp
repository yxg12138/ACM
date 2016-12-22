#include <stdio.h>
#include <algorithm>
#define maxn 105
#define INF 1e9+7
using namespace std;

int n;
int a[maxn];
int dp[maxn][3];

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<3; i++)
		dp[0][i] = 0;
	for(int i=1; i<=n; i++)
	{
		dp[i][0] = min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2])) + 1;
		if(a[i] == 1 || a[i] == 3)
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
		else
			dp[i][1] = INF;
		if(a[i] == 2 || a[i] == 3)
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
		else
			dp[i][2] = INF;
		if(a[i] == 0)
		{
			dp[i][1] = INF;
			dp[i][2] = INF;
		}
	}

	printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));

	return 0;
}