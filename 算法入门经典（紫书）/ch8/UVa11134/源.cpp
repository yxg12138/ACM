#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;

bool vis[maxn];
int n;
struct node 
{
	int l, r, num;
	node() :l(0), r(0), num(0){}
	bool operator<(const node& rhs)const{
		return r < rhs.r || (r == rhs.r&&l < rhs.l);
	}
};

node x[maxn], y[maxn];

bool solve(int* a, node* q)
{
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < n; i++)
	{
		for (int j = q[i].l; j <= q[i].r; j++)
		{
			if (!vis[j])
			{
				a[q[i].num] = j;
				vis[j] = 1;
				break;
			}
			if (j == q[i].r)
				return false;
		}
	}
	return true;
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	int a[maxn], b[maxn];
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &x[i].l, &y[i].l, &x[i].r, &y[i].r);
			x[i].num = y[i].num = i;
		}
		sort(x, x + n);
		sort(y, y + n);
		if (solve(a, x) && solve(b, y))
		{
			for (int i = 0; i < n; i++)
				printf("%d %d\n", a[i], b[i]);
		}
		else
			printf("IMPOSSIBLE\n");
	}
}