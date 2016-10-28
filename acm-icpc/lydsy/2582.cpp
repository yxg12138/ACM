/*
 * ���������������: 
 * 1.�������ڱ�����������+����̬�����ϵ����ѡ���ϱߣ����Ϸ���Ψһ�������ַ��� 
 * 2.�������ڱ���+1������̬����һ���㵥�����ܵ����ַ��� 
 * 3.�������û�н� 
 * �ֱ���ÿ����ͨ�飬�𰸳��������� 
 */ 
#include <cstdio>
#include <vector>
using namespace std;
const int mod = 1000000007;
int n, m, nn, mm, ans = 1;
vector<int> edge[100001];
bool vis[100001];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	int Size = edge[x].size();
	++nn;
	mm += Size;
	for(int i = 0; i < Size; ++i) dfs(edge[x][i]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0, u, v; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
	{
		if(vis[i] || edge[i].empty()) continue;
		nn = mm = 0;
		dfs(i);
		mm >>= 1;
		if(nn == mm + 1) ans = (long long)ans * nn % mod;
		else if(nn == mm) ans = (ans << 1) % mod;
		else ans = 0;
	}
	printf("%d\n", ans);
	return 0;
}
