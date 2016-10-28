#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long

ll Pow(ll a, ll n, ll p)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res*a)%p;
		a = (a*a) % p;
		n >>= 1;
	}
	return res;
}


int cm(ll n, ll m, ll p)
{
	ll a = 1, b = 1;
	if (m > n) return 0;
	while (m)
	{
		a = (a*n) % p;
		b = (b*m) % p;
		m--;
		n--;
	}
	return (a*Pow(b, p - 2, p) % p);

}

ll Lucas(ll n, ll m, ll p)
{
	if (m == 0) return 1;
	return cm(n%p, m%p, p)*Lucas(n / p, m / p, p) % p;
}


int main()
{
	int T;
	ll n, m, p;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &n, &m, &p);
		printf("%lld\n",Lucas(n+m,m,p));
	}
}
