#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

__int64 d[100005];

int main()
{
	int T;
	__int64 n,k;
	scanf("%d",&T);
	while(T--)
	{
		__int64 ans = 0,sum = 0;
		scanf("%I64d%I64d",&n,&k); 
		for(int i=1; i<n; i++)
		{
			scanf("%I64d",&d[i]);
			ans += d[i]+1;
		}
		sort(d+1,d+n);
		if(n<=k)
		{
			printf("%d\n",n);
			continue;
		}
		for(int i=n-1; i>n-1-k+1; i--)
			sum += d[i];

		printf("%I64d\n",ans-sum+1);
	}

	return 0;
}