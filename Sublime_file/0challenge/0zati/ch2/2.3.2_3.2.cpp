//2.3.2 多重部分和——2
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10;
const int max_K = 1e5+10;
int a[maxn],m[maxn];
int n,K;
bool dp[maxn][max_K];

void solve(){
	for(int i=0; i<n; i++)
		for(int j=0; j<max_K; j++)
			dp[i][j] = -1;

	for(int i=0; i<n; i++)
		for(int j=0; j<=K; j++){
			if(dp[i][j]>=0)
				dp[i+1][j] = m[i];
			else if(j < a[i] && dp[i+1][j-a[i]]<0)
				dp[i+1][j] = -1;
			else
				dp[i+1][j] = dp[i+1][j-a[i]]-1;
		}

	if(dp[n][K]) cout << "Yes" << endl;
	else cout << "No" << endl;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i] >> m[i];
	cin >> K;
	solve();
}