#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
typedef long long ll;

ll gcd(ll x,ll y){
	return y==0 ? x : gcd(y,x%y);
}

int main(){
	ll n,a[3];
	cin >> n;
	ll x,y,z;
	if(n == 1){
		cout << -1 << endl;
		return 0;
	}

	a[0] = n;
	int flag = 0;
	for(ll i=1; i<=1e9; i++){
		ll p = gcd(i-n,n*i);
		ll c = (i-n)/p, b = (n*i) / p;
		if(a<=0 || b<=0) continue;
		if(c == 1){
			flag = 1;
			a[1] = b;
			a[2] = i;
			break;
		}
	}

	if(flag == 0)
		cout << -1 << endl;
	else{
		sort(a,a+3);
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
	}
}