#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int minn = 20000, maxn = -20000, kk;
struct point
{
	int x;
	int y;
}po[1000 + 10];


int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		minn = 20000, maxn = -20000;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &po[i].x, &po[i].y);
			po[i].x *= 2;
			if (po[i].x<minn)
				minn = po[i].x;
			if (po[i].x>maxn)
				maxn = po[i].x;
		}
		kk = (minn + maxn) / 2;
		int flag = 0,i,j;
		for (i = 1; i <= n; i++)
		{
			flag = 0;
			for(j=1; j<=n; j++)
			{
				if(po[i].y == po[j].y && (po[i].x + po[j].x)/2==kk)
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				break;
		}
		if (i == n+1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;

}