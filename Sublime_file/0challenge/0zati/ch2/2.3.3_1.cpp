//划分数
#include <bits/stdc++.h>
using namespace std;

const int max_m = 1000+10;
const int max_n = 1000+10;
int n,m,MOD;
int dp[max_m][max_n];

//dp[i][j] j的i次划分
void solve(){
	dp[0][0] = 1;
	for(int i=1; i<=m; i++)
		for(int j=0; j<=n; j++){
			if(j-i>=0)
				dp[i][j] = (dp[i-1][j] + dp[i][j-i])%M;
			else
				dp[i][j] = dp[i-1][j];
		}

	printf("%d\n",dp[m][n]);

}

int main(){
	scanf("%d%d%d",&n,&m,&MOD);
	solve();

}