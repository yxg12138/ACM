#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+7;

int a[maxn],b[maxn],c[maxn],d[maxn];
int n,m,k,x,s;

int C(ll x){
	int le=0,ri=k-1;
	while(le < ri){
		int mid = (le+ri+1)/2;
		if(d[mid] <= x) le = mid;
		else ri = mid-1;
	}

	return c[le];
}

int main(){
	cin >> n >> m >> k >> x >> s;
	for(int i=0; i<m; i++) cin >> a[i];
	for(int i=0; i<m; i++) cin >> b[i];
	for(int i=0; i<k; i++) cin >> c[i];
	for(int i=0; i<k; i++) cin >> d[i];

	ll sum;
	int tmp = C(s);
	if(tmp == c[0] && d[0] > s)
		sum = 1LL*x*n;
	else
		sum = 1LL*x*(n-tmp);

	// cout << sum << endl;

	for(int i=0; i<m; i++){
		ll now = s-b[i];
		//cout << now << endl;
		if(now >= 0){
			// sum = min(sum,1LL*a[i]*(n-C(now)));
			// cout << sum << endl;
			ll tmp = C(now);
			if(tmp == c[0] && d[0] > now)
				sum = min(sum,1LL*a[i]*n);
			else
				sum = min(sum,1LL*a[i]*(n-tmp));
			// cout << sum << endl;
		}

	}

	cout << sum << endl;
}
