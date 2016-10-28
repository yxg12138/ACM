// 1133 不重叠的线段
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// X轴上有N条线段，每条线段有1个起点S和终点E。最多能够选出多少条互不重叠的线段。
// （注：起点或终点重叠，不算重叠）。
// 例如：[1 5][2 3][3 6]，可以选[2 3][3 6]，这2条线段互不重叠。
// Input
// 第1行：1个数N，线段的数量(2 <= N <= 10000)
// 第2 - N + 1行：每行2个数，线段的起点和终点(-10^9 <= S,E <= 10^9)
// Output
// 输出最多可以选择的线段数量。

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct point
{
	int start;
	int end;
};
point p[10005];

int cmp(point a,point b)
{
	return a.end < b.end;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&p[i].start,&p[i].end);
	}
	sort(p,p+n,cmp);
	int j=0,ans=1;
	for(int i=0; i<n; i++)
	{
		if(p[j].end <= p[i].start)
		{
			ans++;
			j = i;
		}
	}
	printf("%d\n",ans);

	return 0;
}