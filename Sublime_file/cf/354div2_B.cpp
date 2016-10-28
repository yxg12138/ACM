#include <stdio.h>

double dp[15][15] = {0};


int main()
{
	int n,t,ans=0;
	scanf("%d%d",&n,&t);
	dp[1][1] = t*1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(dp[i-1][j-1]>1)
				dp[i][j] += (dp[i-1][j-1]-1)/2;
			if(dp[i-1][j]>1)
				dp[i][j] += (dp[i-1][j]-1)/2;
			if(dp[i][j]>=1)
				ans++;
		}
	}
	printf("%d\n",ans);


	return 0;
}