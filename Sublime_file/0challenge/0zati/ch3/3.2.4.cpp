//超大背包问题

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e16;
const int maxn = 40+10;

int n;
ll w[maxn],v[maxn];
ll W;

pair<ll,ll> ps[1<<(maxn/2)];

void solve(){
	int n2 = n/2;
	for(int i=0; i<(1<<n2); i++){
		ll sw = 0,sv = 0;
		for(int j=0; j<n2; j++){
			if(i>>j & 1){
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw,sv);
	}

	sort(ps,ps+(1<<n2));
	int m=1;
	for(int i=1; i<(1<<n2); i++){
		if(ps[m-1].second < ps[i].second)
			ps[m++] = ps[i];
	}

	ll res = 0;
	for(int i=0; i<(1<<(n-n2)); i++){
		ll sw = 0,sv = 0;
		for(int j=0; j<(n-n2); j++){
			if(i>>j & 1){
				sw += w[n2+j];
				sv += v[n2+j];
			}
		}

		if(sw <= W){
			ll tv = (lower_bound(ps,ps+m,make_pair(W-sw,INF))-1)->second;
			res = max(res,sv+tv);
		}
	}
	printf("%lld\n",res);

}

int main(){
	scanf("%d%d",&n,&W);
	for(int i=0; i<n; i++){
		scanf("%d%d",&w[i],&v[i]);
	}
	solve();

}

