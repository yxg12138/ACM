#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll quickpow(ll m, ll n,ll k){
	ll b = 1;
	while(n > 0){
		if(n & 1) b = (b*m) % k;
		m = (m*m) % k;
		n >>= 1;
	}

	return b;
}

int main(){
	ll n;
	cin >> n;
	cout << quickpow(1378,n,10) << endl;
}