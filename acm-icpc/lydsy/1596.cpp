/*
 * ������С֧�伯
 * f[i][0]��ʾ��iΪ�������������ǣ�i����������С����������ѡһ������������ 
 * f[i][1]��ʾ��iΪ�������������ǣ�i����������С�����������Ƿ񸲸ǽԿɣ� 
 * f[i][2]��ʾ��iΪ����������i�ⱻ���ǵ���С����������ȫû���������ǣ� 
 * ����һ�ֽⷨ��̰�ģ����ȡһ����Ϊ�� 
 * ���յ����ľ���(���)����ö��ÿ���㣬���û�����������丸�׽ڵ㽨վ 
 * ̰�ĵ���ȷ�Էǳ���Ȼ���ڸ���˳���£�һ����δ�����ǵĵ�ֻ�ܱ��Լ����ǻ��Ǹ��׸��� 
 * ���ڸ��׽ڵ㽨վ���Ը��Ǹ���ĵ㣬����ʹ��վ������ 
 */
#include <cstdio>
const int maxn = 10001;
int n, f[maxn][3], g[maxn], cnt;
struct Node { int v, nxt; } l[maxn << 1];
inline int min(int a, int b) { return a < b ? a : b; }
void dfs(int u, int fa)
{
	int sum = 0;
	f[u][1] = 1;
	for(int i = g[u]; i; i = l[i].nxt)
	{
		int &v = l[i].v;
		if(v == fa) continue;
		dfs(v, u);
		f[u][1] += min(f[v][0], min(f[v][1], f[v][2]));
		f[u][2] += f[v][0];
		sum += min(f[v][0], f[v][1]);
	}
	f[u][0] = maxn;
	if(!l[g[u]].nxt && u != 1) return;
	for(int i = g[u]; i; i = l[i].nxt)
	{
		int &v = l[i].v;
		if(v == fa) continue;
		f[u][0] = min(f[u][0], f[v][1] + sum - min(f[v][0], f[v][1]));
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		l[++cnt] = (Node){v, g[u]}, g[u] = cnt;
		l[++cnt] = (Node){u, g[v]}, g[v] = cnt;
	}
	dfs(1, 0);
	printf("%d\n", min(f[1][0], f[1][1]));
	return 0;
}
