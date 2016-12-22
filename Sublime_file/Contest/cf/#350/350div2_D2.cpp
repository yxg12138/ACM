#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100010],b[100010],minn = 0xffffff;
long long n,k;


int ok(long long num)
{
	long long ret = k;
	for(int i=1; i<=n; i++)
	{
		if(num>b[i]/a[i])
		{
			if(ret<a[i]*num-b[i]) return 0;
			else ret -= a[i]*num - b[i];
		}
	}
	return 1;
}

int main()
{
	long long left = 0,right = 2e9 + 10, ans = 0;
	scanf("%I64d%I64d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%I64d",&a[i]);
	for(int i=1; i<=n; i++)
		scanf("%I64d",&b[i]);
	while(left<=right)
	{
		long long mid = (left+right)/2;
		if(!ok(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			ans = mid;
		}
	}
	printf("%I64d\n",ans);



}