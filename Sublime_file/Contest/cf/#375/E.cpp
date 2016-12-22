#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;

set<int> s[maxn];
vector<pair<int,int> > ans;
int n,m;

void dfs(int x){
	while(s[x].size()){
		int p = *s[x].begin();
		s[x].erase(p), s[p].erase(x);
		ans.push_back(make_pair(x,p));
		dfs(p);
	}
}

int main(){
	int T; cin>>T;
	while(T--){
		ans.clear();
		cin >> n >> m;
		for(int i=0; i<m; i++){
			int x,y; cin>>x>>y;
			s[x].insert(y);
			s[y].insert(x);
		}

		for(int i=1; i<=n; i++)
			if(s[i].size() % 2 == 1){
				s[n+1].insert(i), s[i].insert(n+1);
			}

		cout << n-s[n+1].size() << endl;

		for(int i=1; i<=n; i++)
			dfs(i);

		for(int i=0; i<ans.size(); i++)
			if(ans[i].first!=n+1 && ans[i].second!=n+1)
				cout << ans[i].first << " " << ans[i].second << endl;
	}
}