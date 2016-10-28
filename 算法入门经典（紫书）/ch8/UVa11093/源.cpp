#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
int p[maxn],q[maxn];


int main()
{
// 	freopen("in.txt", "r", stdin);
	int T,cas = 0;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &p[i]);
		for (int i = 0; i < n; i++) scanf("%d", &q[i]);

		int flag,i;
		for (i = 0;i < n; i++)
		{
			int ans = 0,pos;
			flag = 1;
			for (int j = 0; j < n; j++)
			{
				pos = (i + j) % n;
				ans += p[pos];
				ans -= q[pos];
				if (ans < 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag) break;
			if (pos < i) {
				flag = 0; break;
			}
			i = pos;
		}
		if (flag)
			printf("Case %d: Possible from station %d\n", ++cas, i+1);
		else
			printf("Case %d: Not possible\n",++cas);
	}




}