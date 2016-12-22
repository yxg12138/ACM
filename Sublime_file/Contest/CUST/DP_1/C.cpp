#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn],dp4[maxn][maxn];
int a[maxn][maxn];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&a[i][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp1[i][j] = a[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
	for(int i=n; i>=1; i--)
		for(int j=m; j>=1; j--)
			dp2[i][j] = a[i][j] + max(dp2[i+1][j],dp2[i][j+1]);
	for(int i=n; i>=1;i--)
		for(int j=1; j<=m; j++)
			dp3[i][j] = a[i][j] + max(dp3[i+1][j],dp3[i][j-1]);
	for(int i=1; i<=n; i++)
		for(int j=m; j>=1; j--)
			dp4[i][j] = a[i][j] + max(dp4[i-1][j],dp4[i][j+1]);
	int ans = 0;
	for(int i=2; i<n; i++)
		for(int j=2; j<m; j++)
		{
			ans = max(ans,dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
			ans = max(ans,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
		}

	printf("%d\n",ans);

	return 0;
}