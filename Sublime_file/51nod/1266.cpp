// 1266 蚂蚁
// n只蚂蚁以每秒1cm的速度在长为Lcm的竿子上爬行。当蚂蚁爬到竿子的端点时就会掉落。由于
// 竿子太细，两只蚂蚁相遇时，它们不能交错通过，只能各自反向爬回去。对于每只蚂蚁，我们
// 知道它距离竿子左端的距离xi，但不知道它当前的朝向。请计算各种情况当中，所有蚂蚁落
// 下竿子所需的最短时间和最长时间。
// 例如：竿子长10cm，3只蚂蚁位置为2 6 7，最短需要4秒(左、右、右)，最长需要8秒（右、右、右）。
// Input
// 第1行：2个整数N和L，N为蚂蚁的数量，L为杆子的长度(1 <= L <= 10^9, 1 <= N <= 50000)
// 第2 - N + 1行：每行一个整数A[i]，表示蚂蚁的位置(0 < A[i] < L)
// Output
// 输出2个数，中间用空格分隔，分别表示最短时间和最长时间。

#include <cstdio>
#include <cmath>
using namespace std;

long long min = 1e9+5, max = -1;

int main()
{
	long long n, l,kk;
	scanf("%lld %lld", &n, &l);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &kk);
		if (fabs((kk - l/2)*1.0) < min)
		{
			min = fabs((kk - l/2)*1.0);
		}
		if (kk > max)
		{
			max = kk;
		}
		if (l - kk > max)
		{
			max = l-kk;
		}
	}

	printf("%lld %lld\n", l/2 - min, max);


	return 0;
}

// #include <iostream>  
// #include<bits/stdc++.h>  
  
// using namespace std;  
  
// int main()  
// {  
//     int n,l;  
//     scanf("%d%d",&n,&l);  
//     int mmin=0,mmax=0;  
//     for(int i=0;i<n;i++)  
//     {  
//         int x;  
//         scanf("%d",&x);  
//         mmin=max(mmin,min(x,l-x));  
//         mmax=max(mmax,max(x,l-x));  
//     }  
//     cout<<mmin<<" "<<mmax<<endl;  
// }  