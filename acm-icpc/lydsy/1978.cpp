/*
 * ��f[t, i]��ʾö�ٵ���t�������Ժ�Լ��i������β���ȡ���ĸ��� 
 * ���ڵ�ǰ��x�����ҵ�max{f[t - 1, k] + 1}(k | x && k >= l)
 * �ٴθ���f[t, k](k | x)��ans
 * ��һά���Թ����� 
 */
#include <cstdio>
const int maxv = 1000001, maxsqv = 1001;
int n, l, f[maxv], g[maxsqv], ans;
inline void update(int &x, int y) { if(x < y) x = y; }
int main()
{
	scanf("%d%d", &n, &l);
	while(n--)
	{
		int x, Max = g[0] = 0;
		scanf("%d", &x);
		for(int i = 1; i * i <= x; ++i)
			if(x % i == 0)
			{
				g[++g[0]] = i;
				if(i >= l) update(Max, f[i]);
				g[++g[0]] = x / i;
				if(x / i >= l) update(Max, f[x / i]);
			}
		update(ans, ++Max);
		for(int i = 1; i <= g[0]; ++i)
			update(f[g[i]], Max);
	}
	printf("%d\n", ans);
	return 0;
}
