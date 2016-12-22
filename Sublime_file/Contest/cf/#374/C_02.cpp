#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f;
const int maxn = 5e3+10;
int n,m,t,u,v,d,pa[maxn][maxn],dp[maxn][maxn],a[maxn];

struct node{
	int u,v,d;
	node(int u=0,int v=0,int d=0) : u(u),v(v),d(d) {}
};

vector<node> E;
vector<int> G[maxn];

int main(){
	cin >> n >> m >> t;
	for(int i=1; i<=m; i++){
		cin >> u >> v >> d;
		E.push_back(node(u,v,d));
		G[u].push_back(E.size()-1);
	}
	memset(dp,INF,sizeof(dp));
	memset(pa,0,sizeof(pa));
	dp[1][1] = 0;
	for(int i=0; i<G[1].size(); i++){
		node &e = E[G[1][i]];
		dp[2][e.v] = e.d;
		pa[2][e.v] = 1;
	}

	for(int i=3; i<=n; i++){
		for(int j=0; j<m; j++){
			node &e = E[j];
			if(dp[i][e.v] > dp[i-1][e.u]+e.d){
				dp[i][e.v] = dp[i-1][e.u]+e.d;
				pa[i][e.v] = e.u;
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; i++)
		if(dp[i][n] <= t)
			ans = i;
	cout << ans << endl;
	int fa = n, index=1, tt=ans;
	while(fa){
		a[index++] = fa;
		fa = pa[tt--][fa];
	}

	for(int i=ans; i>=1; i--)
		cout << a[i] << " ";
	cout << endl;

}