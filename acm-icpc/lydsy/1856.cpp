/*
 * ���Ǵӿմ����������Ҫ����ַ����������ֲ�������ĩβ��0���1
 * ����ӳ�䵽��άƽ���ڣ�����ĳ������1�ĸ�����Ϊ�����꣬0�ĸ�����Ϊ������ 
 * �մ���ԭ��(0,0)����1�൱����x�������ƶ�һ�񣬼�0ͬ�� 
 * ����·�߼���(0,0)�ߵ�(n,m)����ͬ���ַ�������ͬ�Ĺ���·�� 
 * ����Ҫ������ǰk���ַ���1�ĸ���������0�ĸ�����������·�߲��ܳ���y=x����ֱ�� 
 * ��Ŀת��Ϊ����Ŀ������� 
 */
#include <cstdio>
typedef long long LL;
const int maxn = 2000001, mod = 20100403;
int n, m, fact[maxn];
inline int pow(int x, int k)
{
	int ret = 1;
	while(k)
	{
		if(k & 1) ret = ret * (LL)x % mod;
		x = x * (LL)x % mod;
		k >>= 1;
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
	fact[0] = 1;
	for(int i = 1; i < maxn; ++i)
		fact[i] = fact[i - 1] * (LL)i % mod;
	printf("%lld\n", (LL)fact[n + m] * (n + 1 - m) % mod * pow((LL)fact[n + 1] * fact[m] % mod, mod - 2) % mod);
	return 0;
}
