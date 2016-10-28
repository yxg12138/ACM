// 1010 只包含因子2 3 5的数
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// K的因子中只包含2 3 5。满足条件的前10个数是：2,3,4,5,6,8,9,10,12,15。
// 所有这样的K组成了一个序列S，现在给出一个数n，求S中 >= 给定数的最小的数。
// 例如：n = 13，S中 >= 13的最小的数是15，所以输出15。
// Input
// 第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
// 第2 - T + 1行：每行1个数N(1 <= N <= 10^18)
// Output
// 共T行，每行1个数，输出>= n的最小的只包含因子2 3 5的数。

#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e18+100;
long long a[100000];

int k;
void init()
{
	long long i,j,z;
	for(i=1; i<maxn; i*=2)
		for(j=1; j*i<maxn; j*=3)
			for(z=1; i*j*z<maxn; z*=5)
				a[k++] = i*j*z;
}


int main()
{
	init();
	sort(a,a+k);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",*lower_bound(a+1,a+k,n));

	}

	return 0;
}