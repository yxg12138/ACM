/* 
 * ��f[k,i]��ʾö�ٵ���k����������A��������iʱ�䣬������B��������f[i]ʱ�� 
 * Ȼ�������ֵı���������= =...
 * ��һά���Թ����� 
 */
#include <cstdio>
const int maxn = 6001, maxm = 30001;
int n, m, a[maxn], b[maxn], c[maxn], f[maxm], ans = maxm;
inline int max(int x, int y) { return x < y ? y : x; }
inline int min(int x, int y) { return x < y ? x : y; }
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", a + i, b + i, c + i);
		if(!a[i]) a[i] = maxm;
		if(!b[i]) b[i] = maxm;
		if(!c[i]) c[i] = maxm;
		m += min(a[i], min(b[i], c[i]));
	}
	for(int i = 1, tmp; i <= n; ++i)
		for(int j = m; j >= 0; --j)
		{
			tmp = maxm;
			if(j >= a[i]) tmp = min(tmp, f[j - a[i]]);
			tmp = min(tmp, f[j] + b[i]);
			if(j >= c[i]) tmp = min(tmp, f[j - c[i]] + c[i]);
			f[j] = tmp;
		}
	for(int i = 0; i <= m; ++i)
		ans = min(ans, max(i, f[i]));
	printf("%d\n", ans);
	return 0;
}
