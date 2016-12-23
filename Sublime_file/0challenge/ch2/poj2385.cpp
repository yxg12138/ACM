#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000+10;

int a[maxn];
int dp[maxn][maxn];

int main(){
	int T,W;
	scanf("%d%d",&T,&W);

	memset(dp,0,sizeof(dp));

	for(int i=1; i<=T; i++) scanf("%d",&a[i]);

	if(a[1] == 1){
		dp[1][0] = 1;
		dp[1][1] = 0;
	}

	if(a[1] == 2){
		dp[1][0] = 0;
		dp[1][1] = 1;
	}

	for(int i=2; i<=T; i++){
		for(int j=0; j<=W; j++){
			if(j == 0){
				dp[i][j] = dp[i-1][j] + a[i]%2;
			}

			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);

			if(j%2+1 == a[i]){
				dp[i][j]++;
			}
		}
	}

	int ans = dp[T][0];

	for(int i=1; i<=W; i++){
		ans = max(ans,dp[T][i]);
	}

	printf("%d\n",ans);


}