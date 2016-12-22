#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n,m,G[maxn][maxn];
int vis[maxn],topo[maxn],t;


bool dfs(int u){
	vis[u] = -1;
	for(int v=1; v<=n; v++){
		if(G[u][v]){
			if(vis[v] < 0) return false;
			else if(!vis[v] && !dfs(v)) return false;
		}
	}
	vis[u] = 1; topo[t--] = u;
	return true;
}

void toposort(){
	t = n;
	memset(vis,0,sizeof(vis));
	for(int u=1; u<=n; u++){
		if(!vis[u]) dfs(u);
	}
}

int main(){
	while(cin >> n >> m && (n||m)){
		int x,y;
		memset(G,0,sizeof(G));
		for(int i=0; i<m; i++){
			cin >> x >> y;
			G[x][y] = 1;
		}

		toposort();

		for(int i=1; i<n; i++){
			cout << topo[i] << " ";
		}
		cout << topo[n] << endl;
	}
}