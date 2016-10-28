//2.3.2 多重部分和——1
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10;
const int max_K = 1e5+10;
int a[maxn],m[maxn];
int n,K;
bool dp[maxn][max_K];

void solve(){
	dp[0][0] = true;
	for(int i=0; i<n; i++)
		for(int j=0; j<=K; j++)
			for(int k=0; k<=m[i] && k*a[i]<=j; k++)
				dp[i+1][j] |= dp[i][j-k*a[i]];

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