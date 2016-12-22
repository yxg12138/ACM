#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000+10;

int n,t,x,mx=0;
int dp[maxn][20];

int main(){
	while(scanf("%d",&n)==1 && n){
		mx=-1;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++){
			scanf("%d%d",&x,&t);
			if(t > mx) mx = t;
			dp[t][x] ++;
		}


		for(int i=mx-1; i>=0; i--){
			for(int j=0; j<=10; j++){
				dp[i][j] += max(max(dp[i+1][j],dp[i+1][j+1]),dp[i+1][j-1]);
			}
		}

		cout << dp[0][5] << endl;
	}
}