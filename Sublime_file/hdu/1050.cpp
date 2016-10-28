#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int T,a[205] = {0};
	scanf("%d",&T);
	while(T--)
	{
		int n,s,e,maxn = -1;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&s,&e);
			if(s>e) swap(s,e);
			s = (s+1)/2,e = (e+1)/2;
			for(int i=s; i<=e; i++)
			{
				a[i]++;
				if(a[i] > maxn)
					maxn = a[i];
			}
		}
		printf("%d\n",maxn*10);
	}

	return 0;
}