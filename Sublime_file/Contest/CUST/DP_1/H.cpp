#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 3500
#define LL long long
double dp[N];
LL ans[N];
LL prime[N],notprime[N];

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

void init()
{
	prime[0] = 0;
	for(int i=2; i<=3000; i++)
	{
		if(!notprime[i])
		{
			prime[++prime[0]] = i;
			for(LL j=(LL)i*i; j<=3000; j+=i)
				notprime[j] = 1;
		}
	}
}

int main()
{
	int n,m;
	init();
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0; i<=n; i++)
		{
			dp[i] = 0;
			ans[i] = 1;
		}
		for(LL i=1; i<=prime[0] && prime[i]<=n; i++)
		{
			double tmp = log(prime[i]*1.0);
			for(LL j=n; j>=prime[i]; j--)
			{
				for(LL k=prime[i],q=1;k<=j;k*=prime[i],q++)
				{
					if(dp[j-k]+q*tmp>dp[j])
					{
						dp[j] = dp[j-k]+q*tmp;
						ans[j] = ans[j-k]*k%m;
					}
				}
			}
		}
		printf("%lld\n", ans[n]);
	}

	return 0;
}