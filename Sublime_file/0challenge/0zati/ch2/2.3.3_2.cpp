//多重集的组合数
#include <bits/stdc++.h>
using namespace std;

const int max_n = 1000+10;
const int max_m = 1000+10;

int n,m,M;
int a[max_n];
int dp[max_n][max_m];

//dp[i+1][j] 前i种物品取出j个的组合总数
void solve(){
	for(int i=0; i<=n; i++)
		dp[i][0] = 1;

	for(int i=0; i<n; i++)
		for(int j=1; j<=m; j++){
			if(j-1-a[i]>=0)
				dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+M)%M;
			else
				dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]);
		}
	printf("%d\n",dp[n][m]);

}

int main(){
	scanf("%d%d%d",&n,&m,&M);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	solve();

}