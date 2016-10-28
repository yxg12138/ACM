// 1007 正整数分组
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// 将一堆正整数分为2组，要求2组的和相差最小。
// 例如：1 2 3 4 5，将1 2 4分为1组，3 5分为1组，两组和相差1，是所有方案中相差最少的。
// Input
// 第1行：一个数N，N为正整数的数量。
// 第2 - N+1行，N个正整数。
// (N <= 100, 所有正整数的和 <= 10000)
// Output
// 输出这个最小差
// Input示例
// 5
// 1 2 3 4 5
// Output示例
// 1

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define maxn 10010
using namespace std;
int n,i,j,a[maxn],dp[maxn],sum = 0;

int main()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}

	for(i=0; i<n; i++)
		for(j=sum/2; j>=a[i]; j--)
			dp[j] = max(dp[j],dp[j-a[i]]+a[i]);

	printf("%d\n",abs(sum-dp[sum/2]) - dp[sum/2]);

	return 0;
}