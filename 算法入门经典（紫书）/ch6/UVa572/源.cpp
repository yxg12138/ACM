#include <cstdio>
#include <cstring>
const int maxn = 100+5;

char pic[maxn][maxn];
int m, n, vis[maxn][maxn];

void dfs(int r, int c, int id)
{
	if (r < 0 || r >= m || c<0 || c >= n) return;
	if (pic[r][c] != '@' || vis[r][c] > 0) return;
	vis[r][c] = id;
	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (dr != 0 || dc != 0)
				dfs(r + dr, c + dc, id);
		}
	}
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &m, &n) == 2 && m && n)
	{
		for (int i = 0; i < m; i++) scanf("%s", pic[i]);
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vis[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
			}
		}
		printf("%d\n", cnt);
	}
}