#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e5 + 10;
vector <int> g[maxn];
vector <int> c[maxn];
int n, m, vis[maxn], d[maxn], ans[maxn];


void init()
{
	int x, y;
	int temp;
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 0; i <= n; i++)
		c[i].clear();
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		scanf("%d", &temp);
		c[x].push_back(temp);
		c[y].push_back(temp);
	}
}


void bfs1(int n)
{
	memset(d, -1, sizeof(d));
	queue <int> q;
	d[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		int sz = g[u].size();
		for (int v = 0; v < sz; v++)
		{
			int vv = g[u][v];
			if (vv == 1)
			{
				d[1] = d[u] + 1;
				return;
			}
			if (d[vv] == -1)
			{
				d[vv] = d[u] + 1;
				q.push(vv);
			}
		}
	}
}


void bfs2()
{
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (d[u] == 0) return;
		int sz = g[u].size();
		int mm = -1;
		for (int i = 0; i < sz; i++)
		{
			int vv = g[u][i];
			if (d[vv] == d[u] - 1)
			{
				if (mm == -1)
					mm = c[u][i];
				else
					mm = min(mm, c[u][i]);
			}
		}

		int t = d[1] - d[u];
		if (ans[t] == 0) ans[t] = mm;
		else ans[t] = min(mm, ans[t]);
		
		for (int v = 0; v < sz; v++)
		{
			int vv = g[u][v];
			if (vis[vv] == 0 && d[vv] == d[u] - 1 && c[u][v] == mm)
			{
				q.push(vv);
				vis[vv] = 1;
			}
		}

	}
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	while (~scanf("%d%d", &n, &m))
	{
		init();
		bfs1(n);
		bfs2();
		printf("%d\n", d[1]);
		for (int i = 0; i < d[1]; i++)
		{
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
}