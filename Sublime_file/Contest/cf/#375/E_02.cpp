#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
const int maxm = 40010;

int T,n,m,sa[maxm],sb[maxm],ls,du[maxn],ans;
bool g[maxn][maxn];

void dfs(int u){
	while(du[u]){
		for(int i=1; i<=n; i++)
			if(g[u][i]){
				ls++; sa[ls]=u, sb[ls]=i;
				du[u]--,du[i]--;
				g[u][i] = g[i][u] = 0;
				u = i;
				break;
			}
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		ans = n;
		for(int i=1; i<=m; i++){
			int x,y; cin>>x>>y;
			g[x][y]=g[y][x] = 1;
			du[x]++,du[y]++;
		}

		for(int i=1; i<=n; i++) ans -= du[i]%2;
		cout << ans << endl;
		for(int i=1; i<=n; i++) if(du[i]&1) while(du[i]) dfs(i);
		for(int i=1; i<=n; i++) while(du[i]) dfs(i);

		for(int i=1; i<=ls; i++)
			cout << sa[i] << " " << sb[i] << endl;
		ls = 0;
	}

}