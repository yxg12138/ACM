// 1278 相离的圆
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// 平面上有N个圆，他们的圆心都在X轴上，给出所有圆的圆心和半径，求有多少对圆是相离的。
// 例如：4个圆分别位于1, 2, 3, 4的位置，半径分别为1, 1, 2, 1，那么{1, 2}, {1, 3}
//  {2, 3} {2, 4} {3, 4}这5对都有交点，只有{1, 4}是相离的。
// Input
// 第1行：一个数N，表示圆的数量(1 <= N <= 50000)
// 第2 - N + 1行：每行2个数P, R中间用空格分隔，P表示圆心的位置，R表示圆的半径(1 <= P, R <= 10^9)
// Output
// 输出共有多少对相离的圆。
// Input示例
// 4
// 1 1
// 2 1
// 3 2
// 4 1
// Output示例
// 1

#include <iostream>  
#include<bits/stdc++.h>  
#define N 55000  
#define INF 0x7ffffff  
#define LL long long  
using namespace std;  
  
struct node
{
	LL x,y;
}a[N];

int cmp(node a,node b)
{
	return a.y < b.y;
}

int _find(LL l,LL r,LL t)
{
	while(l<r)
	{
		LL mid = (l+r)>>1;
		if(a[mid].y<t)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	while(l>0 && a[l].y>=t) l--;
	return l;
}

int main()
{
	LL n;
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
	{
		LL p,r;
		scanf("%lld%lld",&p,&r);
		a[i].x = p - r;
		a[i].y = p + r;
	}
	sort(a+1,a+n+1,cmp);
	LL ans = 0;
	for(LL i=2; i<=n; i++)
		ans += _find(1,i-1,a[i].x);
	printf("%lld\n",ans);
}