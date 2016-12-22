#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
int dp[35],n,x;
long long ans;

int main(){
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>x;
			if(x==1)
				dp[0]++;
			else{
				int cnt=0;
				while((x&1)==0){
					x >>= 1;
					cnt++;
				}
				if(x==1 && dp[cnt-1]!=0)
					dp[cnt] = (dp[cnt]+dp[cnt-1]) % MOD;
			}
		}
		ans = 0;
		for(int i=0; i<32; i++)
			ans = (ans + dp[i]) % MOD;
		cout << ans << endl;
	}
}