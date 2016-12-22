// http://blog.csdn.net/shiqi_614/article/details/7983298
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const long long MOD = 1000000007;

long long dp[maxn][maxn],sum[maxn][maxn];
char str[maxn];

int main()
{
	while(scanf("%s",str+1)!=EOF)
	{
		int len = strlen(str+1);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		dp[1][1] = 1;sum[1][1] = 1;
		for(int i=1; i<=len; i++)
		{
			for(int j=1; j<=i+1; j++)
			{
				if(str[i] == 'I')
					dp[i+1][j] = sum[i][j-1];
				else if(str[i] == 'D')
					dp[i+1][j] = (sum[i][i] - sum[i][j-1] + MOD)%MOD; 
					//(a-b)%n=(a%n-b%n+n)%n 为什么要加n，由于a%n可能小于b%n,所以加n保证为正整数
				else
					dp[i+1][j] = sum[i][i];
				sum[i+1][j] = (sum[i+1][j-1]+dp[i+1][j])%MOD;
			}
		}
		printf("%lld\n",sum[len+1][len+1]);
	}


	return 0;
}