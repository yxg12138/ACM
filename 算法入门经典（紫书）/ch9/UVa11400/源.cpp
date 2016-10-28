#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1 << 30;

struct node
{
	int v, k, c, l;
	bool operator<(const node& rhs)const{
		return v < rhs.v;
	}
};

node light[1010];
int num[1010];
int cost[1010];


int main()
{
// 	freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) && n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &light[i].v, &light[i].k, &light[i].c, &light[i].l);
		}
		sort(light + 1, light + 1 + n);

		num[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			num[i] = num[i - 1] + light[i].l;
		}

		cost[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cost[i] = INF;
			for (int j = 0; j <= i; j++)
			{
				cost[i] = min(cost[i], cost[j] + (num[i] - num[j])*light[i].c + light[i].k);
			}
		}

		printf("%d\n", cost[n]);
	}
}