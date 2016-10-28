#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll c[50];

ll f(int k, int i)
{
	ll ret = 0;
	if (!i) return 0;
	if (!k) return 1;
	if (i < (1 << k-1))
	{
		ret = 2 * f(k - 1, i);
	}
	else
		ret = 2 * c[k-1] + f(k - 1, i - (1 << k-1));

	return ret;
}

int main()
{
	ll T, a, b,k;
	c[0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		c[i] = 3 * c[i - 1];
	}
	int cas = 0;
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld%lld%lld",&k, &a, &b);
		printf("Case %d: %lld\n", ++cas,f(k, b) - f(k, a - 1));

	}

}

