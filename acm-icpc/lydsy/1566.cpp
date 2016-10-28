/*
 * ƽ��������Ϊ������������Ϸ���ֽ��������Ը��� 
 * ��f[i,j,k,l]��ʾ��һ����Ϸ����ȡi��������ȡj�����ڶ�����Ϸ����ȡk��������ȡl���Ĵ� 
 * ��Ϊʱ��Ҫ��i+j=k+l�����Կ�������һά����ͬת�Ƶĸ��Ӷ� 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 502, mod = 1024523;
int n, m, f[maxn][maxn][maxn];
char s[maxn], t[maxn];
inline void upd(int &x, const int &y)
{
	x += y;
	if(x >= mod) x -= mod;
}
int main()
{
	scanf("%d%d%s%s", &n, &m, s, t);
	f[0][0][0] = 1;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k <= n; ++k)
				if(f[i][j][k])
				{
					int l = i + j - k;
					if(s[i] == s[k]) upd(f[i + 1][j][k + 1], f[i][j][k]);
					if(s[i] == t[l]) upd(f[i + 1][j][k], f[i][j][k]);
					if(t[j] == s[k]) upd(f[i][j + 1][k + 1], f[i][j][k]);
					if(t[j] == t[l]) upd(f[i][j + 1][k], f[i][j][k]);
				}
	printf("%d\n", f[n][m][n]);
	return 0;
}
