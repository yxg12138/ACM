/*
 * f[l][r][0/1]��ʾs[l..r]���ӻ����M֮�����̴� 
 * �������M��f[l][r][1] <- f[l][i][1] + 1(M) + f[i + 1][r][1] 
 * ����ѹ��һ�Σ�ѹǰѹ�󶼻ᱻ��һ�������ֻ��һ���ͺã�f[l][r][t] <- f[l][i][t] + r - (i + 1) + 1
 * ���s[l..r]�ǵȳ������Σ����м䶼û��M����f[l][r][t] <- f[l][(l + r) / 2][0] + 1(R) 
 */
#include <cstdio>
#include <cstring>
char s[60];
int f[60][60][2];
inline int min(int a, int b) { return a < b ? a : b; }
inline bool check(int l, int r)
{
	int len = r - l + 1;
	if(len & 1) return 0;
	len >>= 1;
	for(int i = 0; i < len; ++i)
		if(s[l + i] != s[l + len + i]) return 0;
	return 1;
}
int dp(int l, int r, bool t)
{
	if(l == r) return f[l][r][t] = 1;
	if(f[l][r][t]) return f[l][r][t];
	int Min = r - l + 1;
	if(t) for(int i = l; i < r; ++i)
		Min = min(Min, dp(l, i, 1) + dp(i + 1, r, 1) + 1);
	for(int i = l; i < r; ++i)
		Min = min(Min, dp(l, i, t) + r - i);
	if(check(l, r)) Min = min(Min, dp(l, l + r >> 1, 0) + 1);
	return f[l][r][t] = Min;
}
int main()
{
	scanf("%s", s + 1);
	printf("%d\n", dp(1, strlen(s + 1), 1));
	return 0;
}
