#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int a[maxn],d[maxn];
int vis[maxn];
int n,m;

bool C(int x){
	memset(vis,0,sizeof(vis));
	int res = 0, sum = 0;

	for(int i=x-1; i>=0; i--){
		if(d[i]){
			if(!vis[d[i]]){
				sum += a[d[i]];
				vis[d[i]] = 1;
				res ++;
			}else if(sum != 0){
				sum--;
			}
		}else if(sum != 0){ 
			sum--;
		}
	}
	if(res != m || sum > 0)
		return 0;
	return 1;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> d[i];
	for(int i=1; i<=m; i++) cin >> a[i];

	int le = 1, ri = n, mid;
	while(le < ri){
		mid = le + (ri-le)/2;
		if(C(mid))
			ri = mid;
		else 
			le = mid+1;
	}

	if(C(le))
		cout << le << endl;
	else
		cout << -1 << endl;
}