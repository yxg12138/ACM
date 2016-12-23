#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 350;

int a[maxn][maxn],dp[maxn][maxn];

int main(){
	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			cin >> a[i][j];
		}
	}

	dp[0][0] = a[0][0];

	for(int i=0; i<N-1; i++){
		for(int j=0; j<=i; j++){
			dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]+a[i+1][j]);
		}
	}

	int ans = 0;
	for(int i=0; i<N; i++){
		ans = max(ans,dp[N-1][i]);
	}

	cout << ans << endl;

}