//LIS 最长递增子序列
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000+10;
int a[maxn];
int n;
int dp[maxn];

void solve(){
	fill(dp,dp+n,INF);
	for(int i=0; i<n; i++)
		*lower_bound(dp,dp+n,a[i]) = a[i];
	cout << lower_bound(dp,dp+n,INF) - dp << endl;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	solve();

}
