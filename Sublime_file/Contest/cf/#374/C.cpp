#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3+10;
int dp[maxn][maxn],pre[maxn][maxn];
int n,m,k;
vector<int> E[maxn];
vector<int> val[maxn];

void dfs(int x,int num,int sp,int pa){
	if(dp[x][num] <= sp) return;
	dp[x][num] = sp;
	pre[x][num] = pa;
	for(int i=0; i<E[x].size(); i++)
		if(sp+val[x][i] <= k)
			dfs(E[x][i],num+1,sp+val[x][i],x);
}

vector<int> ppp;
void dfs2(int x,int y){
	ppp.push_back(x);
	if(pre[x][y] == -1){
		cout << ppp.size() << endl;
		for(int i=ppp.size()-1; i>=0; i--)
			cout << ppp[i] << " ";
		cout << endl;
		return;
	}
	else
		dfs2(pre[x][y], y-1);
}

int main(){
	memset(pre,-1,sizeof(pre));
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++)
			dp[i][j] = 1e9+7;

	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		E[a].push_back(b);
		val[a].push_back(c);
	}

	dfs(1,1,0,-1);
	for(int i=n; i>=2; i--){
		if(dp[n][i] <= k){
			dfs2(n,i);
			break;
		}
	}


}