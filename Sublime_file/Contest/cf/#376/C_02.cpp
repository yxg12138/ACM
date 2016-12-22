#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int col[maxn],cnt[maxn],q[maxn];
int sz,mx;
bool vis[maxn];
vector<int> E[maxn];

void dfs(int x){
	vis[x] = 1;
	q[sz++] = x;
	cnt[col[x]]++;
	if(cnt[col[x]] > mx) mx = cnt[col[x]];

	for(int i=0; i<E[x].size(); i++)
		if(!vis[E[x][i]]) dfs(E[x][i]);
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%d",&col[i]);
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}

	int ans = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			sz = 0, mx = 0;
			dfs(i);
			for(int i=0; i<sz; i++) cnt[col[q[i]]]--;
			ans += sz - mx;
		}
	}

	printf("%d\n",ans);
}