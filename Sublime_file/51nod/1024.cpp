// 1024 矩阵中不重复的元素
// 题目来源： Project Euler
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// 一个m*n的矩阵。

// 该矩阵的第一列是a^b,(a+1)^b,.....(a + n - 1)^b
// 第二列是a^(b+1),(a+1)^(b+1),.....(a + n - 1)^(b+1)
// .......
// 第m列是a^(b + m - 1),(a+1)^(b + m - 1),.....(a + n - 1)^(b + m - 1)
// (a^b表示a的b次方）
// Input
// 输入数据包括4个数：m,n,a,b。中间用空格分隔。m，n为矩阵的长和宽（2 <= m,n <= 100)。a，b为矩阵的第1个元素，a^b（2 <= a , b <= 100）。
// Output
// 输出不重复元素的数量。
// Input示例
// 4 3 2 2
// Output示例
// 11

#include <bits/stdc++.h>
using namespace std;

double d[11000];

int main()
{
	int m,n,a,b;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	int cnt = 0;
	for(int i=a; i<a+n; i++)
		for(int j=b; j<b+m; j++)
			d[cnt++] = (double)j*log((double)i);
	sort(d,d+cnt);
	int ans = n*m;
	for(int i=1; i<cnt; i++)
	{
		if(d[i] - d[i-1] < 1e-9)
			ans--;
	}
	printf("%d\n",ans);


	return 0;
}