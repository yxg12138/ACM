// 1413 权势二进制
// 一个十进制整数被叫做权势二进制，当他的十进制表示的时候只由0或1组成。
// 例如0，1，101，110011都是权势二进制而2，12，900不是。
// 当给定一个n的时候，计算一下最少要多少个权势二进制相加才能得到n。
// Input
// 单组测试数据。
// 第一行给出一个整数n (1<=n<=1,000,000)
// Output
// 输出答案占一行。

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x;
	scanf("%lld",&x);
	int maxx = -1,tem = x % 10;
	while(x)
	{
		if(tem >= maxx)
			maxx = tem;
		x /= 10;
		tem = x%10;
	}
	printf("%d\n",maxx);


	return 0;
}