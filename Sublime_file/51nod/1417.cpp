#include <stdio.h>
#define LL long long

LL gcd(LL a,LL b)
{
	return b == 0 ? a : gcd(b,a%b);
}

int main()
{
	LL n,a,b;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld %lld",&a,&b);
		LL x = a + 3*b;
		LL y = 4*(a+b);
		// int k = x,m = y;
		// while(m)
		// {
		// 	int r = k%m;
		// 	k = m;
		// 	m = r;
		// }
		LL k = gcd(x,y);
		printf("%lld/%lld\n",x/k,y/k);
	}



	return 0;
}