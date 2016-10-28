#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int maxn = 5050;
char stra[maxn], strb[maxn];

int dp[maxn][maxn], res[maxn][maxn], first[27][2], last[27][2];
bool vis[27];
int tot = 0;
int l1, l2;


void init()
{
	memset(vis, 0, sizeof(vis));
	memset(last, -1, sizeof(last));
	for (int i = 0; i < 27; i++)
	{
		first[i][0] = first[i][1] = INF;
	}
	l1 = strlen(stra), l2 = strlen(strb);
	for (int i = 0; i < l1; i++)
	{
		if (!vis[stra[i] - 'A'])
		{
			vis[stra[i] - 'A'] = 1;
			tot++;
		}
		if (first[stra[i] - 'A'][0] == INF)
			first[stra[i] - 'A'][0] = i;
		last[stra[i] - 'A'][0] = i;
	}

	for (int i = 0; i < l2; i++)
	{
		if (!vis[strb[i] - 'A'])
		{
			vis[strb[i] - 'A'] = 1;
			tot++;
		}
		if (first[strb[i] - 'A'][1] == INF)
			first[strb[i] - 'A'][1] = i;
		last[strb[i] - 'A'][1] = i;
	}
	for (int i = 0; i <= l1; i++)
	{
		for (int j = 0; j <= l2; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 26; k++)
			{
				if (first[k][0] == INF && first[k][1] == INF)
					continue;
				if (first[k][0] > i - 1 && first[k][1] > j-1)
					continue;
				if (last[k][0] <= i - 1 && last[k][1] <= j-1)
					continue;
				cnt++;
			}
			res[i][j] = cnt;
		}
	}

}


int main()
{
// 	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", stra, strb);
		init();
		dp[l1][l2] = 0;
		for (int i = l2 - 1; i >= 0; i--)
			dp[l1][i] = dp[l1][i + 1] + res[l1][i];
		for (int i = l1 - 1; i >= 0; i--)
		{
			for (int j = l2; j >= 0; j--)
			{
				if (j == l2)
					dp[i][j] = dp[i + 1][j] + res[i][j];
				else
					dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + res[i][j];
			}
		}
	
		printf("%d\n", dp[0][0]);
	}
}