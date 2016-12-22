#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+7;

int dfn[maxn],low[maxn],vis[maxn],tot,n,ans = maxn;
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
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		E[i].push_back(x);
	}

	for(int i=1; i<=n; i++){
		if(!dfn[i])
			tarjan(i);
	}

	cout << ans << endl;

}