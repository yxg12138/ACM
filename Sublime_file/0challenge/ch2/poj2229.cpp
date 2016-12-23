#include <cstdio>

const int maxn = 1e6+10;

const int M = 1000000000;
long long dp[maxn];

int main(){
	int N;
	scanf("%d",&N);
	dp[1] = 1; dp[2] = 2;
	for(int i=3; i<=N; i++){
		if(i & 1){
			dp[i] = dp[i-1];
		}else{
			dp[i] = dp[i-2] + dp[i/2];
			dp[i] %= M;
		}
	}

	printf("%d\n",dp[N]);
}