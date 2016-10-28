/*
 * ��������Ȼ���½� ��������Ի����� 
 * ��Ԥ�������iλǰ��j���������more[i][j]���iλ���jС��������small[i][j]
 * ��f[i][j]Ϊi�������һ�������Ϊj������ ��֮���������� 
 * f[j] = Min{f[w] + more[b[i]][j] + small[b[i]][j] (w = j �� 1} (b[i]Ϊ��i���յ�λ��) 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[10003], blank[10003], small[10003][102] = {}, more[10003][102] = {}, f[10003][103];
int n, k, ans, cnt = 0, sum = 0;
int main()
{
	int i, j, w;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++i) { scanf("%d", &num[i]); if(num[i] == -1) blank[++cnt] = i; }
	for(i = 2; i <= n; ++i)
	{
		for(j = 1; j <= k; ++j) more[i][j] = more[i - 1][j];
		if(num[i - 1] != -1) for(j = 1; j < num[i - 1]; ++j) ++more[i][j];
	}
	for(i = n - 1; i; --i)
	{
		for(j = 1; j <= k; ++j) small[i][j] = small[i + 1][j];
		if(num[i + 1] != -1) for(j = num[i + 1] + 1; j <= k; ++j) ++small[i][j];
	}
	for(i = 1; i <= n; ++i) if(num[i] != -1) sum += more[i][num[i]];
	memset(f, 0x7f, sizeof(f));
	for(i = 1; i <= k; ++i) f[1][i] = more[blank[1]][i] + small[blank[1]][i];
	for(i = 2; i <= cnt; ++i)
		for(j = 1; j <= k; ++j)
			for(w = 1; w <= j; ++w)
				f[i][j] = min(f[i][j], f[i - 1][w] + more[blank[i]][j] + small[blank[i]][j]);
	ans = 0x7f7f7f7f;
	for(i = 1; i <= k; ++i) if(ans > f[cnt][i]) ans = f[cnt][i];
	if(ans > 1e8) ans = 0;
	printf("%d\n", ans + sum);
	return 0;
}
