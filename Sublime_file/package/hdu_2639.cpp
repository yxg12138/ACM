#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Node
{
	int price;
	int val;
}node[1005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,v,k,i,dp[1005][31] = {0},a[31],b[31];
		scanf("%d%d%d",&n,&v,&k);
		for(i=0; i<n; i++)
			scanf("%d",&node[i].price);
		for(i=0; i<n; i++)
			scanf("%d",&node[i].val);
		int j;
		for(i=0; i<n; i++)
		{
			for(j=v; j>=node[i].val; j--)
			{
				int cnt=0,d;
				for(d=1; d<=k; d++)
				{
					a[d] = dp[j-node[i].val][d]+node[i].price;
					b[d] = dp[j][d];
				}
				int x,y,z;
				x = y = z = 1;
				a[d] = b[d] = -1;
				while(z<=k && (x<=k||y<=k))
				{
					if(a[x] > b[y])
					{
						dp[j][z] = a[x];
						x++;
					}
					else
					{
						dp[j][z] = b[y];
						y++;
					}
					if(dp[j][z] != dp[j][z-1])
						z++;
				}
			}
		}
		printf("%d\n",dp[v][k]);
	}
	return 0;
}