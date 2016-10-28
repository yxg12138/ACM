#include <bits/stdc++.h>
using namespace std;
map<long long,long long>mp;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		long long u,v,w;
		int f;
		scanf("%d",&f);
		if(f==1)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&w);
			while(u!=v)
			{
				if (u>v) { mp[u] += w; u>>=1;}
				else  { mp[v] += w; v>>=1;}
			}
		}
		else
		{
			scanf("%I64d%I64d",&u,&v);
			long long ans=0;
			while(u!=v)
			{
				if(u>v) { ans += mp[u]; u>>=1;}
				else { ans += mp[v]; v>>=1; }
			}
			printf("%I64d\n",ans);
		}
	}



	return 0;
}