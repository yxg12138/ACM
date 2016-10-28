//LIS 最长递增子序列
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000+10;
int a[maxn];
int n;
int dp[maxn];

void solve(){
	int res = 0;
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; i++) if(a[j] < a[i])
			dp[i] = max(dp[i],dp[j]+1);
		res = max(res,dp[i]);
	}
	cout << res << endl;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	solve();

}
