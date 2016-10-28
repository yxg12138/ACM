//2.3.2 多重部分和——3
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10;
const int max_K = 1e5+10;
int a[maxn],m[maxn];
int n,K;
bool dp[max_K];

void solve(){
	memset(dp,-1,sizeof(dp));

	dp[0] = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<=K; j++){
			if(dp[j] >= 0)
				dp[j] = m[i];
			else if(j<a[i] || dp[j-a[i]]<=0)
				dp[j] = -1;
			else
				dp[j] = dp[j-a[i]] - 1;
		}

	if(dp[K]) cout << "Yes" << endl;
	else cout << "No" << endl;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i] >> m[i];
	cin >> K;
	solve();
}