#include <iostream>
#include <cstdio>
using namespace std;
int dp[105][105] = {0};

int main()
{
	int n,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				scanf("%d",&dp[i][j]);
			}
		}
		int maxn=0;
		for(int i=n; i>1; i--)
		{
			for(int j=1; j<i; j++)
			{
				if(dp[i][j] > dp[i][j+1])
					maxn = dp[i][j];
				else
					maxn = dp[i][j+1];
				dp[i-1][j] += maxn;
			}
		}
		printf("%d\n",dp[1][1]);
	}


	return 0;
}