#include <stdio.h>
const int maxn = 100005;
long long a[maxn];


int main()
{
	long long n, h, k;
	scanf("%I64d %I64d %I64d", &n, &h, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
	}
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] <= h)
			sum += a[i];
		else
		{
			sum = a[i];
			ans++;
		}
		long long t = sum / k;
		ans += t;
		sum -= t*k;
	}
	if(sum) ans++;
	printf("%I64d\n", ans);



	return 0;
}