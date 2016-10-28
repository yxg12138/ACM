#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct point 
{
	double x;
	double y;
	bool operator<(const point& rhs)const
	{
		return x < rhs.x;
	}
};

point p[1010];
double dp[1010][1010];
double dis[1010][1010];

double dist(int i, int j)
{
	if (dis[i][j] >= 0) return dis[i][j];
	return dis[i][j] = sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}

double DP(int i, int j)
{
	if (dp[i][j] >= 0) return dp[i][j];
	dp[i][j] = min(DP(i + 1, j) + dist(i, i + 1), DP(i + 1, i) + dist(j, i + 1));
	return dp[i][j];
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	int n;
	while (~scanf("%d", &n))
	{
		memset(dp, -1, sizeof(dp));
		memset(dis, -1, sizeof(dis));

		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);	
		}
		sort(p, p + n);
		for (int j = 0; j < n; j++)
			dp[n - 2][j] = dist(n - 2, n - 1) + dist(j, n - 1);
		printf("%.2lf\n", DP(0, 0));

	}

}