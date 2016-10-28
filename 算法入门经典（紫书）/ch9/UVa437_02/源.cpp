#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node 
{
	int x, y, z;
	void f(int a, int b, int c)
	{
		x = a; y = b; z = c;
	}
};
node st[200];

bool comp(node a, node b)
{
	if (a.x*a.y < b.x*b.y)
		return 1;
	return 0;
}

int n, m, x, y, z, dp[200];

int main()
{
// 	freopen("in.txt", "r", stdin);
	int flag = 1;
	while (scanf("%d", &n) && n)
	{
		m = 0;
		int i, j;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			st[m++].f(x, y, z);
			st[m++].f(x, z, y);
			st[m++].f(y, z, x);
		}
		sort(st, st + m, comp);
		int t = 0;
		for (i = 0; i < m; i++)
		{
			dp[i] = st[i].z;
			for (j = 0; j < i; j++)
			{
				if ((st[i].x>st[j].x && st[i].y > st[j].y) || (st[i].x > st[j].y && st[i].y > st[j].x))
					dp[i] = max(dp[i], dp[j] + st[i].z);

			}
			if (dp[i] > t)
				t = dp[i];
		}
		printf("Case %d: maximum height = %d\n", flag++, t);
	}
}