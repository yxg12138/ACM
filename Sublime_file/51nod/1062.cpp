// 1062 序列中最大的数
// 有这样一个序列a：
// a[0] = 0
// a[1] = 1
// a[2i] = a[i]
// a[2i+1] = a[i] + a[i+1]
// 输入一个数N，求a[0] - a[n]中最大的数。
// a[0] = 0, a[1] = 1, a[2] = 1, a[3] = 2, a[4] = 1, a[5] = 3, a[6] = 2, a[7] = 3, a[8] = 1, a[9] = 4, a[10] = 3。
// 例如：n = 5，最大值是3，n = 10，最大值是4。
// Input
// 第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10)
// 第2 - T + 1行：T个数，表示需要计算的n。（1 <= n <= 10^5)
// Output
// 共T行，每行1个最大值。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long a[maxn],dp[maxn];

void init()
{
	a[0] = 0,a[1] = 1; 
	dp[0] = 0,dp[1] = 1;
	for(int i=2; i<maxn; i++)
	{
		if(i%2)
			a[i] = a[i/2] + a[i/2+1];
		else
			a[i] = a[i/2];
		dp[i] = max(dp[i-1],a[i]);
	}
}

int main()
{
	init();
	int T,x;
	scanf("%d",&T);
	while(T--)
	{
		int i;
		scanf("%d",&x);
		
		printf("%lld\n",dp[x]);
	}


	return 0;
}