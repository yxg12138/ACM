#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b==0 ? a : gcd(b,a%b);
}


int main(){
	ll a,b;
	while(cin >> a >> b){
		ll g = gcd(a,b);
		ll lcm = a*b/g;
		cout << g << " " << lcm << endl;
	}
}