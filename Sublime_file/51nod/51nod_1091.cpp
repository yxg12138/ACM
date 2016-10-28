// 1091 线段的重叠
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
// X轴上有N条线段，每条线段包括1个起点和终点。线段的重叠是这样来算的，[10 20]和[12 25]的重叠部分为[12 20]。
// 给出N条线段的起点和终点，从中选出2条线段，这两条线段的重叠部分是最长的。输出这个最长的距离。如果没有重叠，输出0。
// Input
// 第1行：线段的数量N(2 <= N <= 50000)。
// 第2 - N + 1行：每行2个数，线段的起点和终点。(0 <= s , e <= 10^9)
// Output
// 输出最长重复区间的长度。

#include <iostream>
#include <algorithm>
#define maxn 50005
#include <cstdio>
using namespace std;

struct region
{
	long long start;
	long long end;
};

region kk[maxn];

int cmp(region x,region y)
{
	if(x.start < y.start) return true;
	else if(x.start == y.start && x.end > y.end) return true;

	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i < n;i++)
	{
		scanf("%lld%lld",&kk[i].start,&kk[i].end);
	}

	sort(kk,kk+n,cmp);  //起点升序  若起点相同，终点降序

	region tmp = kk[0];
	long long ans = 0;

	for(int i=1;i < n;i++)
	{
		if(kk[i].end < tmp.end)   //区间覆盖
			ans = max(ans,kk[i].end - kk[i].start);
		else 
		{
			ans = max(ans,tmp.end - kk[i].start);   //覆盖跟不覆盖 
			tmp = kk[i];   //更新前一个区间 
		}
	}

	printf("%lld\n",ans);


	return 0;
}