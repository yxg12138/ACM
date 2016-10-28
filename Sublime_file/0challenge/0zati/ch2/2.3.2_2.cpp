//2.3.2 01背包问题之2
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100+10;
const int max_v = 100+10;
int n,w[maxn],v[maxn],W;
int dp[maxn][maxn*max_v];

void solve(){
	fill(dp[0],dp[0]+maxn*max_v,INF);
	dp[0][0] = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<maxn*max_v; j++)
			if(j < v[i])
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);

	int res = 0;
	for(int i=0; i<maxn*max_v; i++) if(dp[n][i] <= W)
		res = i;
	printf("%d\n",res);

}



int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		scanf("%d%d",&w[i],&v[i]);
	cin >> W;
	solve();
}