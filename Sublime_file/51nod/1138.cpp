// 1138 连续整数的和
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
// 给出一个正整数N，将N写为若干个连续数字和的形式(长度 >= 2)。例如N = 15，可以写为1 + 2 + 3 + 4 + 5，也可以写为4 + 5 + 6，或7 + 8。如果不能写为若干个连续整数的和，则输出No Solution。
// Input
// 输入1个数N(3 <= N <= 10^9)。
// Output
// 输出连续整数中的第1个数，如果有多个按照递增序排列，如果不能分解为若干个连续整数的和，则输出No Solution。
// Input示例
// 15
// Output示例
// 1
// 4
// 7
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	scanf("%d",&n);
	int flag = 0;
	for(i=(int)sqrt(2*n); i>=2; i--)
	{
		if((n-i*(i-1)/2)%i == 0 && (n-i*(i-1)/2) > 0)
		{
			printf("%d\n",(n-i*(i-1)/2)/i);
			flag = 1;
		}
	}

	if(!flag)
		printf("No solution\n");

	return 0;
}