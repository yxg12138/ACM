#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5+4;
int n,sum[N],k;
char s[N];

int check(int x,int y)
{
	if(sum[x]-sum[y]<=k) return 1;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	sum[0] = 0;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='a') sum[i+1] = sum[i];
		else sum[i+1] = sum[i] + 1;
	}
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(check(mid,i-1))  l = mid + 1;
			else r = mid - 1;
		}
		ans= max(ans,l-i);
	}
	for(int i=0; i<n; i++)
	{
		if(s[i]=='b') sum[i+1] = sum[i];
		else sum[i+1] = sum[i]+1;
	}
	for(int i=1; i<=n; i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(check(mid,i-1)) l = mid+1;
			else r = mid-1;
		}
		ans = max(ans,l-i);
	}
	printf("%d\n",ans);
}