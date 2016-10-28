// 1432 独木舟
// n个人，已知每个人体重。独木舟承重固定，每只独木舟最多坐两个人，可以
// 坐一个人或者两个人。显然要求总重量不超过独木舟承重，假设每个人体重
// 也不超过独木舟承重，问最少需要几只独木舟？
// Input
// 第一行包含两个正整数n (0<n<=10000)和m (0<m<=2000000000)，表示人数
// 和独木舟的承重。
// 接下来n行，每行一个正整数，表示每个人的体重。体重不超过1000000000，
// 并且每个人的体重不超过m。
// Output
// 一行一个整数表示最少需要的独木舟数。

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 1;
long long n,m;
bool cmp(long long a,long long b)
{
	return a > b;
}
int main()
{
	long long a[maxn];
	scanf("%lld %lld",&n,&m);
	for(int i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n,cmp);
	int i = 0;
	int cnt = 0;
	while(i < n)
	{
		if(a[n-1]+a[i] <= m)
		{
			cnt++;
			n--;
			i++;
		}
		else 
		{
    		i++;
			cnt++;
		}
	}
	printf("%lld",cnt);
}