#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

vector<int> v[maxn];

int col[maxn],cnt[maxn],vis[maxn];
queue<int> q;
set<int> s;
set<int>::iterator it,iitt;
set<int> mp;

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++) scanf("%d",&col[i]);
	for(int i=1; i<=m; i++){
		int u,w;
		scanf("%d%d",&u,&w);
		v[u].push_back(w);
		v[w].push_back(u);
		s.insert(u);
		s.insert(w);
	}
	int ans = 0;
	for(it=s.begin(); it!=s.end(); it++){
		int kk = *it;
		if(!vis[kk]){
			for(iitt=mp.begin(); iitt!=mp.end(); iitt++) cnt[*iitt] = 0;
			mp.clear();

			vis[kk] = 1;
			q.push(kk);
			int sum = 0, mx = 0;
			while(!q.empty()){
				sum++;
				int t = q.front(); q.pop();
				cnt[col[t]] ++;
				mp.insert(col[t]);
				mx = max(mx,cnt[col[t]]);
				for(int i=0; i<v[t].size(); i++){
					if(!vis[v[t][i]])
						q.push(v[t][i]),vis[v[t][i]] = 1;
				}
			}
			ans += sum - mx;
		}
	}

	cout << ans << endl;
}	