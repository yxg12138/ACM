// 1050 循环数组最大子段和
// N个整数组成的循环序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的连续
// 的子段和的最大值（循环序列是指n个数围成一个圈，因此需要考虑a[n-1],a[n],a[1],a[2]
// 这样的序列）。当所给的整数均为负数时和为0。
// 例如：-2,11,-4,13,-5,-2，和最大的子段为：11,-4,13。和为20。
// Input
// 第1行：整数序列的长度N（2 <= N <= 50000)
// 第2 - N+1行：N个整数 (-10^9 <= S[i] <= 10^9)
// Output
// 输出循环数组的最大子段和。
// Input示例
// 6
// -2 11 -4 13 -5 -2
// Output示例
// 20

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50005;
long long a[maxn];

int main()
{
	long long n,sum=0;
	scanf("%lld",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	long long k=a[0],maxx = -0x7fffffff,minn = 0x7fffffff,ans=0;
	for(int i=1; i<n; i++)
	{
		if(k<0)
			k = a[i];
		else
			k += a[i];
		if(k>maxx)
			maxx = k;
	}
	k=a[0];
	for(int i=1; i<n; i++)
	{
		if(k>0)
			k = a[i];
		else
			k += a[i];
		if(k<minn)
			minn = k;
	}
	ans = max(maxx,sum-minn);
	printf("%lld\n",ans);
		

}