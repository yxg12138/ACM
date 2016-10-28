#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 50000+5;
const int INF = 1e9+100;
int W[MAXN],D[MAXN];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	W[n+1] = INF;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&W[n-i]);
		W[n-i] = min(W[n-i+1],W[n-i]);
	}
	for(int i=0; i<m; i++)
	{
		scanf("%d",&D[i]);
	}
	int ans = 0,tp = 1;
	for(int i=0; i<m; i++)
	{
		int tmp = lower_bound(W+tp,W+n+1,D[i]) - W;
		if(tmp == n+1)
			break;
		tp = tmp + 1;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}