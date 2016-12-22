#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

vector<int> G[maxn];
int color[maxn];
int deep = -1, p;

void dfs(int u,int fa,int num){

	if(num > deep){
		p = u;
		deep = num;
	}

	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u,num+(color[v]^color[u]));
	}
}


int main(){
	int n,x,y;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> color[i];

	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs(1,-1,1);
	deep = -1;
	dfs(p,-1,1);

	cout << deep/2 << endl;

}
