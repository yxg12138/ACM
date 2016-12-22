#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;

struct pii{
	ll a,b;
}cars[maxn];

ll n,k,s,t;
ll gs[maxn];
ll ng[maxn];

ll check(ll x){
	ll nowt = 0;
	ll canrun = x/2;
	ll y1,y2;
	for(int i=0; i<=k; i++){
		if(ng[i] <= canrun){
			nowt += ng[i];
		}else{
			y1 = x-ng[i];
			y2 = ng[i] - y1;
			nowt += y2*2;
			nowt += y1;
		}
	}
	if(nowt > t) return 0;
	return 1;
}


int main(){
	cin >> n >> k >> s >> t;
	for(int i=0; i<n; i++)
		cin >> cars[i].a >> cars[i].b;
	for(int i=1; i<=k; i++)
		cin >> gs[i];

	gs[0] = 0;gs[k+1] = s;
	sort(gs+1,gs+k+1);

	ll mng =0 ;
	for(int i=1; i<k+2; i++){
		ng[i-1] = gs[i]-gs[i-1];
		mng = max(mng,ng[i-1]);
	}

	if(s > t){
		cout << -1 << endl;
		return 0;
	}

	ll l=mng-1, r=1e9+7;
	ll mid;

	while(1){
		if(l == r-1) break;
		mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid;
	}

	ll mina = 1e9;

	for(int i=0; i<n; i++){
		if(cars[i].b >= r)
			mina = min(mina,cars[i].a);
	}

	if(mina == 1e9) cout << "-1" << endl;
	else cout << mina << endl;


}