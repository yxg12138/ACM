#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		long long cur,ans = 0,last = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &cur);
			ans += abs(last*1.0);
			last += cur;
		}
		printf("%lld\n", ans);
	}
}