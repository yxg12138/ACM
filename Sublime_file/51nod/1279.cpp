// 1279 扔盘子
// 有一口井，井的高度为N，每隔1个单位它的宽度有变化。现在从井口往下面扔圆盘，如果圆盘
// 的宽度大于井在某个高度的宽度，则圆盘被卡住（恰好等于的话会下去）。
// 盘子有几种命运：1、掉到井底。2、被卡住。3、落到别的盘子上方。
// 盘子的高度也是单位高度。给定井的宽度和每个盘子的宽度，求最终落到井内的盘子数量。
// 如图井和盘子信息如下：
// 井：5 6 4 3 6 2 3
// 盘子：2 3 5 2 4

// 最终有4个盘子落在井内。
// Input
// 第1行：2个数N, M中间用空格分隔，N为井的深度，M为盘子的数量(1 <= N, M <= 50000)。
// 第2 - N + 1行，每行1个数，对应井的宽度Wi(1 <= Wi <= 10^9)。
// 第N + 2 - N + M + 1行，每行1个数，对应盘子的宽度Di(1 <= Di <= 10^9)
// Output
// 输出最终落到井内的盘子数量。


#include <iostream>
#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int a[550000];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	a[0] = INF;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		a[i] = min(a[i],a[i-1]);
	}
	int ans = 0;
	for(int i=0; i<m; i++)
	{
		int x;
		scanf("%d",&x);
		while(a[n] < x)  n--;
		if(n>0)
			ans++,n--;
	}

	printf("%d\n",ans);


	return 0;
}