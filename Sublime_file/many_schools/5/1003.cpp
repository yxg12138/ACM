#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;

long long a[maxn],sum;

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%lld",&a[i]);
		}
		int d = 0;
		for(int i=n; i>=1; i--)
		{
			if(a[i]<0)
			{
				for(int j=i; j>=1; j--)
				{
					sum += a[j];
					if(sum>=0)
					{
						d = i-j;
						i = j+1;
						n -= d;
						sum = 0;
						break;
					}
				}
			}
			
		}
		printf("%lld\n",n);
	}

	return 0;
}