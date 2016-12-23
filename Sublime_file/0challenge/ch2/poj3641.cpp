#include <iostream>
using namespace std;

typedef long long ll;

bool is_prime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0)
			return false;
	}
	return n!=1;
}

ll mod_exp(ll a,ll b,ll m){
	ll res = 1;
	ll exp = a%m;
	while(b){
		if(b&1) res = (res%m)*(exp%m) % m;
		exp = (exp%m)*(exp%m)%m;
		b >>= 1;
	}

	return res;
}

int main(){
	int p,a;
	while(cin>>p>>a && (p||a)){
		if(!is_prime(p) && (mod_exp(a,p,p) == a)){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}