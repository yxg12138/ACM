#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		ll n, s1, v1, s2, v2;
		scanf("%lld%lld%lld%lld%lld", &n,&s1,&v1,&s2,&v2);
		
		ll ans = 0;
		ll cnt1 = n / s1;
		ll cnt2 = n / s2;
		if (v1*s2 >= v2*s1)
		{
			for (int i = 0; i <= min(s1 - 1, cnt2); i++)
			{
				ll t = v2*i + ((n - i*s2) / s1)*v1;
				if (ans < t)
					ans = t;
			}
		}else
		{
			for (int i = 0; i <= min(s2 - 1, cnt1); i++)
			{
				ll t = v1*i + ((n - i*s1) / s2)*v2;
				if (ans < t)
					ans = t;
			}
		}
		printf("Case #%d: %lld\n",cas, ans);
	}


}