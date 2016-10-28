#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 50005;
long long b[maxn],dp[maxn];

long long getans(long long a[],int n)
{
	long long ans = 0;
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=n; i++)
	{
		if(dp[i-1] + a[i] < a[i])
			dp[i] = a[i];
		else
			dp[i] = dp[i-1] + a[i];
		ans = max(ans,dp[i]);
	}
	return ans;
}

int main()
{
	int n;
	long long sum = 0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&b[i]);
		sum += b[i];
	}
	long long ans = getans(b,n);
	for(int i=1; i<=n; i++)
	{
		b[i] = -b[i];
	}
	ans = max(ans,sum + getans(b,n));
	printf("%lld\n",ans);


	return 0;
}