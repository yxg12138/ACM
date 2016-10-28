#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main()
{
	long long a[1005];
	long long n,i;
	scanf("%lld",&n);
	a[0] = 1,a[1] = 1;
	for(i=2; i<=n; i++)
		a[i] = (a[i-1] + a[i-2])%MOD;
	printf("%lld\n",a[n]);


	return 0;
}