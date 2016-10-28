//2.3.1---LCS最长公共子序列
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000+10;
int n,m;
char s[maxn],t[maxn];
int dp[maxn][maxn];

void solve(){
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(s[i] == t[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
		}

	printf("%d\n",dp[n][m]);

}


int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	solve();
}
