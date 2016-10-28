#include <cstdio>
#include <cstring>

int n, vis[20], notprime[30], a[30];

void init()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < 30; i++)
	{
		if (!notprime[i])
		{
			for (int j = 2*i; j < 30; j += i)
			{
				notprime[j] = 1;
			}
		}
	}
}

void dfs(int cur)
{
	if (cur == n && !notprime[a[0] + a[n - 1]])
	{
		for (int i = 0; i < n-1; i++)
			printf("%d ", a[i]);
		printf("%d\n",a[n-1]);
	}
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i] && !notprime[i + a[cur - 1]])
		{
			a[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	init();
	a[0] = 1;
	int kase = 1;
	while (scanf("%d", &n) == 1)
	{
		if(kase != 1) printf("\n");
		printf("Case %d:\n", kase++);
		dfs(1);
	}
}