#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
long long dp[maxn][maxn],book[maxn*maxn];

struct point
{
	int x;
	int y;
	int dis;
}p[maxn];

int cmp(point a,point b)
{
	return a.x < b.x;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1; i<=n; i++)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
			p[i].dis = p[i].x*p[i].x+p[i].y+p[i].y;
		}
		sort(p+1,p+n+1,cmp);
		p[1].dis = 0;

		for(int i=2; i<=n; i++)
		{
			p[i].dis = (p[i].x-p[i-1].x)*(p[i].x-p[i-1].x) + (p[i].y-p[i-1].y)*(p[i].y-p[i-1].y);
		}
		long long sum1 = 0,sum2 = 0;
		for(int i=1; i<=n; i++)
		{
			dp[i][i] = 0;
			dp[i][i+1] = p[i+1].dis;
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				dp[i][j] = dp[i][j-1] + p[j].dis;
			}
		}
		int flag = 0,cnt = 0;
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				book[cnt++] = dp[i][j];
				flag = binary_search(book,book+cnt-2,book[cnt-1]);
				if(flag)
					break;
			}
			if(flag)
				break;
		}

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}


	return 0;
}