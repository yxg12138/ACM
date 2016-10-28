#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 101;
int n, m;
int indegree[maxn], graph[maxn][maxn], res[maxn];


void topologic()
{
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		res[cnt++] = tmp;
		for (int i = 1; i <= n; i++)
		{
			if (graph[tmp][i])
			{
				indegree[i]--;
				if (indegree[i] == 0)
					q.push(i);
			}
		}
	}
	printf("%d", res[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", res[i]);
	printf("\n");
}
int main()
{
// 	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
		int a, b;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			graph[a][b] = 1;
			indegree[b]++;
		}
		topologic();

	}
}