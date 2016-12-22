#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x7fffffffll;
long long ans;
long long n;

bool solve(long long x)
{
	if(x < 2)
		return false;
	long long t = x;
	for(long long i=2; i*i<=x; i++)
	{
		if(x%i==0)
		{
			if(x%(i*i)==0)
				return false;
			x/=i;
		}
	}
	ans = min(ans,abs(t*t-n));
	return true;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		long long x = (long long)(sqrt(n)+0.5);
		int flag = 0;
		ans = INF;
		for(int i=0;;i++)
		{
			if(solve(x+i))
				flag = 1;
			if(solve(x-i))
				flag = 1;
			if(flag == 1)
				break;
		}
		printf("%I64d\n",ans);
	}

}