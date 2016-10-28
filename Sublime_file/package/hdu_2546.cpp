// 饭卡
// Time Limit: 5000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
// Total Submission(s): 22368    Accepted Submission(s): 7822
// Problem Description
// 电子科大本部食堂的饭卡有一种很诡异的设计，即在购买之前判断余额。如果购买一个商品之前，卡上的剩余金额大于或等于5元，就一定可以购买成功（即使购买后卡上余额为负），否则无法购买（即使金额足够）。所以大家都希望尽量使卡上的余额最少。
// 某天，食堂中有n种菜出售，每种菜可购买一次。已知每种菜的价格以及卡上的余额，问最少可使卡上的余额为多少。
// Input
// 多组数据。对于每组数据：
// 第一行为正整数n，表示菜的数量。n<=1000。
// 第二行包括n个正整数，表示每种菜的价格。价格不超过50。
// 第三行包括一个正整数m，表示卡上的余额。m<=1000。
// n=0表示数据结束。
// Output
// 对于每组输入,输出一行,包含一个整数，表示卡上可能的最小余额。

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n),n)
	{
		int i,price[1005] = {0},dp[1005] = {0};

		for(i=1; i<=n; i++)
			scanf("%d",&price[i]);
		sort(price+1,price+n+1);
		int MAX = price[n];
		int j,m;
		scanf("%d",&m);
		if(m < 5)
		{
			printf("%d\n",m);
			continue;
		}
		m-=5;
		for(i=1;i<n;i++)
		{
			for(j=m;j>=price[i];j--)
			{
				dp[j] = max(dp[j],dp[j-price[i]] + price[i]);
			}
		}

		printf("%d\n",m+5-dp[m]-MAX);
	}
	

	return 0;
}