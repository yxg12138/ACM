// 有编号1-n的n个格子，机器人从1号格子顺序向后走，一直走到n号格子，并需要从n号格子走出去。机器人有一个初始能量，每个格子对应一个整数A[i]，表示这个格子的能量值。如果A[i] > 0，机器人走到这个格子能够获取A[i]个能量，如果A[i] < 0，走到这个格子需要消耗相应的能量，如果机器人的能量 < 0，就无法继续前进了。问机器人最少需要有多少初始能量，才能完成整个旅程。

// 例如：n = 5。{1，-2，-1，3，4} 最少需要2个初始能量，才能从1号走到5号格子。途中的能量变化如下3 1 0 3 7。
// Input
// 第1行：1个数n，表示格子的数量。(1 <= n <= 50000)
// 第2 - n + 1行：每行1个数A[i]，表示格子里的能量值(-1000000000 <= A[i] <= 1000000000)
// Output
// 输出1个数，对应从1走到n最少需要多少初始能量。

// #include <iostream>
#include<bits/stdc++.h>
#define maxn 50005

long long dp[maxn] = {0};

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i < n;i++)
	{
		scanf("%lld",&dp[i]);
		dp[i] += dp[i-1];
	}
	long long minn = 1000000001;
	for(int i=0;i < n;i++)
	{
		if(dp[i] < minn)
		{
			minn = dp[i];
		}
	}
	if(minn > 0)
		printf("%d\n",0);
	else 
		printf("%lld\n",-minn);

	return 0;
}