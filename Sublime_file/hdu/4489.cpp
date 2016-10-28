#include <stdio.h>

__int64 dp[25][2],c[25][25];

int main()
{
	c[1][0] = c[1][1] = 1;
	for(int i=2; i<=20; i++)
	{
		c[i][0] = c[i][i] = 1;
		for(int j=1; j<i; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	
	dp[0][0] = dp[1][0] = dp[0][1] = dp[1][1] = 1;
	for(int i=2; i<=20; i++)
	{
		__int64 t = 0;
		for(int j=0; j<i; j++)
			t += dp[j][0]*dp[i-j-1][1]*c[i-1][j];
		dp[i][0] = dp[i][1] = t/2;
	}
	int T,cas,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&cas,&n);
		if(n==1)
		{
			printf("%d 1\n",cas);
			continue;
		}
		printf("%d %I64d\n",cas,dp[n][0]<<1);
	}




	return 0;
}