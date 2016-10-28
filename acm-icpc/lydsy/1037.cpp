/*
 * ��f[a, b, c, d]��ʾǰa + b��������a���к���b��Ů��������ĳһ������������Ů����c����ĳһ����Ů������������d�� 
 * ��f[a, b, c, d]����ת�Ƶ�f[a + 1, b, c + 1, d - 1]��f[a, b + 1, c - 1, d + 1]
 * ע��c��dΪ��ʱ��ӦΪ0
 */
#include <cstdio>
const int maxn = 152, maxk = 21, mod = 12345678;
int n, m, k, f[maxn][maxn][maxk][maxk], ans;
inline int abs(int x) { return x < 0 ? -x : x; }
inline int max(int x, int y) { return x < y ? y : x; }
inline void add(int &x, int y) { x += y; if(x >= mod) x -= mod; } 
inline void upd(int i, int j, int p, int q, int v) { if(abs(i - j + p) <= k && abs(i - j - q) <= k) add(i < j ? f[i][j][max(j - i, p)][q] : f[i][j][p][max(i - j, q)], v); }
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	f[0][0][0][0] = 1;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int p = 0; p <= k; ++p)
				for(int q = 0; q <= k; ++q)
					if(f[i][j][p][q])
					{
						upd(i + 1, j, p, q, f[i][j][p][q]);
						upd(i, j + 1, p, q, f[i][j][p][q]); 
					}
	for(int p = 0; p <= k; ++p)
		for(int q = 0; q <= k; ++q) add(ans, f[n][m][p][q]);
	printf("%d\n", ans);
	return 0;
}

