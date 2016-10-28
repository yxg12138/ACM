#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[50] = {0};

int main()
{
	dp[1] = dp[2] = 1;
	for(int i=3; i<=40; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	int T,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		printf("%d\n",dp[x]);
	}



	return 0;
}