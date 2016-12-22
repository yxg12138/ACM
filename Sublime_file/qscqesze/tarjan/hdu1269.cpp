#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;
const int maxn = 1e4+7;

int dfn[maxn],low[maxn],vis[maxn],tot,n,m,ans;
vector<int> E[maxn];
stack<int> S;

void tarjan(int x){
	low[x] = dfn[x] = ++tot;
	S.push(x);
	vis[x] = 1;

	for(int i=0; i<E[x].size(); i++){
		int v = E[x][i];

		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x],low[v]);
		}else if(vis[v]){
			low[x] = min(low[x],dfn[v]);
		}
	}

	if(low[x] == dfn[x]){
		int cnt = 0;
		while(1){
			int now = S.top();
			S.pop();
			vis[x] = 0;
			cnt++;
			if(now == x) break;
		}

		if(cnt >= 1) ans = min(ans,cnt);
	}
}

int main(){
	
	while(scanf("%d%d",&n,&m)==2 && (n||m)){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));

		ans = INF;
		tot = 0;
		while(!S.empty()) S.pop();
		for(int i=0; i<maxn; i++) E[i].clear();

		for(int i=1; i<=m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			E[u].push_back(v);
		}
	
		for(int i=1; i<=n; i++){
			if(!dfn[i])
				tarjan(i);
		}
	
		cout << ((ans==n)?"Yes":"No") << endl;
	}

}