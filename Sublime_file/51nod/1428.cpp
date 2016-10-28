// 1428 活动安排问题
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// 有若干个活动，第i个开始时间和结束时间是[Si,fi)，同一个教室安排的活动之间不能
// 交叠，求要安排所有活动，最少需要几个教室？ 
// Input
// 第一行一个正整数n (n <= 10000)代表活动的个数。
// 第二行到第(n + 1)行包含n个开始时间和结束时间。
// 开始时间严格小于结束时间，并且时间都是非负整数，小于1000000000
// Output
// 一行包含一个整数表示最少教室的个数。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000 + 1;
int ts[maxn],te[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> ts[i] >> te[i];
	}
	sort(ts+1,ts+n+1);
	sort(te+1,te+n+1);
	int j=1,cnt=0;
	for(int i=1; i<=n; i++)
	{
		if(te[j] > ts[i])
			cnt++;
		else
			j++;
	}
	cout << cnt << endl;

	return 0;
}
