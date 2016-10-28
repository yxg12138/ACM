//2.3.2 完全背包
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10;
int n,w[maxn],v[maxn],W;
int dp[maxn][maxn];

void solve(){
	for(int i=0; i<n; i++)
		for(int j=0; j<=W; j++)
			if(j<w[i])
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
	printf("%d\n",dp[n][W]);
}



int main(){
	memset(dp,0,sizeof(dp));
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> w[i] >> v[i];
	cin >> W;
	solve();
}