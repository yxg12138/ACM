#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int pa[maxn],color[maxn],l[maxn],r[maxn],num[maxn],cnt[maxn];
int n,m,k,tot;

vector<int> v[maxn];

void init(){
	for(int i=1; i<maxn; i++) 
		pa[i] = i;
}

int find(int x){
	if(x == pa[x]) return x;
	return pa[x] = find(pa[x]);
}

void merge(int x,int y){
	int t1 = find(x), t2 = find(y);
	pa[t2] = t1;
}

int main(){
	init();
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++) cin >> color[i];
	for(int i=1; i<=m; i++) cin >> l[i] >> r[i], merge(l[i],r[i]);

	for(int i=1; i<=n; i++)
		if(pa[i] == i) num[i] = ++tot;
	for(int i=1; i<=n; i++)
		v[num[find(i)]].push_back(color[i]);

	int ans = 0;
	for(int i=1; i<=tot; i++){
		int ret = 0;
		for(int j=0; j<v[i].size(); j++) cnt[v[i][j]] = 0;
		for(int j=0; j<v[i].size(); j++){
			cnt[v[i][j]] ++;
			ret = max(ret,cnt[v[i][j]]);
		}

		ans += v[i].size()-ret;
	}

	cout << ans << endl;
}